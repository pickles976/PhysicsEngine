#ifndef CYCLONE_PRECISION_H
#define CYCLONE_PRECISION_H

#include <float.h>
#define real_pow powf
#define real_abs fabsf
#define real_sin sinf
#define real_cos cosf
#define real_exp expf
#define real_sqrt sqrtf

#define REAL_MAX DBL_MAX

namespace cyclone {
    typedef float real;
}

#endif