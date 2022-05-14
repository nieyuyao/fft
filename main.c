#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fft.h"
#include "complex.h"

#define N 4

int main()
{
    complex *src_vector = (complex *)(malloc(sizeof(complex) * N));
    complex *dest_vector = (complex *)(malloc(sizeof(complex) * N));
    for (unsigned int i = 0; i < N; i++)
    {
        complex src_p, dest_p;
        src_p.Im = i + 1;
        src_p.Re = 0;
        memcpy(&dest_p, &src_p, sizeof(complex));
        src_vector[i] = src_p;
        dest_vector[i] = dest_p; 
    }
    fft(src_vector, N, dest_vector);
    return 0;
}