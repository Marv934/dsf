//#########Beschreibung Hunzufuegen#########
#include "m_pd.h"	// PD Interface
#include <stdlib.h>
//#include "dsf_defines.h"

// DSF class and its data space
static t_class *dsf_tilde_class;	// pointer to new class

// object-variables
typedef struct _dsf_tilde {	// data struct
 	t_object x_obj;		// internal object properties
	
	t_sample f_frequency;
	t_sample f_increment;
	t_float f;
	
	//t_inlet *x_in1;
	t_inlet *x_in2;

	t_outlet*x_out;
	
} t_dsf_tilde;

t_int *dsf_tilde_perform(t_int *w)
{
	t_dsf_tilde *x = (t_dsf_tilde *)(w[1]);
	//t_sample *in1 = (t_sample *)(w[2]);
	//t_sample *in2 = (t_sample
	t_sample *out = (t_sample *)(w[2]);    	
	int vector_size = (int)(w[3]);

	float phasor = 0;
	float increment = 0.01;
	
	for(int i = 0; i < vector_size; i++) {
		phasor += increment;
		phasor -= (int)phasor;
		*out = phasor;
	}
    	return (w+4);
}

void dsf_tilde_dsp(t_dsf_tilde *x, t_signal **sp)
{
    	dsp_add(dsf_tilde_perform, 3, x, sp[1]->s_vec, (t_int)sp[0]->s_n);
}

void dsf_tilde_free(t_dsf_tilde *x)		// destructor
{	
	outlet_free(x->x_out);
}

void *dsf_tilde_new(t_floatarg f)
{
  	t_dsf_tilde *x = (t_dsf_tilde *)pd_new(dsf_tilde_class);

	x->f_frequency = f;

	x->x_in2 = floatinlet_new (&x->x_obj, &x->f_frequency);
	//x->x_in2 = floatinlet_new (&x->x_obj, &x->f_increment);

    	x->x_out=outlet_new(&x->x_obj, &s_signal);
    	
	return (void *)x;
	//t_dsf_tilde *x = (t_dsf_tilde *)malloc(sizeof(t_dsf_tilde));
	//x->f_frequency = 440;
    	//x->f_increment = 0.01;
    	//return x; 
}
//### generate new class
// Constructor definiert in class_new
// arguments depend on object-arguments defined in class_new
// initialise object-variables

//# Setup
void dsf_tilde_setup(void) {
	dsf_tilde_class = class_new(gensym("dsf~"),
        	(t_newmethod)dsf_tilde_new,		// constructor
       		(t_method)dsf_tilde_free,		// destructor
        	sizeof(t_dsf_tilde),
        	CLASS_DEFAULT,
        	A_DEFFLOAT, 0);

  	class_addmethod(dsf_tilde_class,
        	(t_method)dsf_tilde_dsp, gensym("dsp"), A_CANT, 0);
}