
#include "complex.h"

#ifndef PI

#define PI 3.1415926

#endif

typedef unsigned int uint32_t;

int fft(complex *src, complex *dest, uint32_t n);
int ifft(complex *src, complex *dest, uint32_t n);
int fft2(complex *src, complex *dest, uint32_t n);
int ifft2(complex *src, complex *dest, uint32_t n);