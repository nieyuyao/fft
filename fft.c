#include "fft.h"

unsigned int bitReverse(unsigned int x, int log2n)
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