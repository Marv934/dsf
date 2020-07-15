/**
 * @file stp_defines.h
 * @author Thomas Resch <br>
 * Audiocommunication Group, Technical University Berlin <br>
 * University of Applied Sciences Nordwestschweiz (FHNW), Music-Academy, Research and Development <br>
 * Preprocessor Instructions for the stp library
 */

#ifndef DSF_DEFINES_H
#define DSF_DEFINES_H

/** Data Type Macro for flexible input vector single or double floating point precision */
#define DSF_INPUTVECTOR_USE_FLOAT
#define DSF_OUTPUTVECTOR_USE_FLOAT

#ifdef DSF_INPUTVECTOR_USE_FLOAT
typedef t_float INPRECISION;
#else
typedef t_double INPRECISION;
#endif

/** Data Type Macro for flexible output vector single or double floating point precision */
#ifdef DSF_OUTPUTVECTOR_USE_FLOAT
typedef t_float OUTPRECISION;
#else
typedef t_double OUTPRECISION;
#endif

#endif /* DSF_DEFINES_H */