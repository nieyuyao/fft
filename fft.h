
#ifndef PI

#define PI 3.1415926

#endif


typedef struct complex
{
    float Re;
    float Im;
} complex;

typedef unsigned long int uint32_t;


int fft(complex *src, uint32_t n, complex *dest);
int ifft(complex *src, uint32_t n, complex *dest);
int fft2(complex *src, uint32_t n, complex *dest);
int ifft2(complex *src, uint32_t n, complex *dest);