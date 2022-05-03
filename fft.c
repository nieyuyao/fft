#include <math.h>
#include "fft.h"

uint32_t bitReverse(uint32_t x, uint32_t log2n)
{
    int n = 0;
    for (int i = 0; i < log2n; i++)
    {
        n <<= 1;
        n |= (x & 1);
        x >>= 1;
    }
    return n;
}

void adjust_src_array(complex *src, complex *dest, uint32_t n)
{
    uint32_t x = 0;
    uint32_t log2n = n == 0 ? 0 : log2(n);
    for (uint32_t i = 0; i < n; i++)
    {
        x = bitReverse(i, log2n);
        dest[i] = src[x];
    }
    return dest;
}


int fft(complex *src, uint32_t n, complex *dest)
{
}


int ifft(complex *src, uint32_t n, complex *dest)
{
    
}

int fft2(complex *src, uint32_t n, complex *dest)
{

}

int ifft2(complex *src, uint32_t n, complex *dest)
{

}