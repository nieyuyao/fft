#include <math.h>
#include "fft.h"

uint32_t bit_reverse(uint32_t x, uint32_t log2n)
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
    int x = 0;
    int log2n = n == 0 ? 0 : log2(n);
    for (int i = 0; i < n; i++)
    {
        x = bit_reverse(i, log2n);
        dest[i] = src[x];
    }
}

void perform(complex *src, complex *dest, uint32_t n, int inverse)
{
    adjust_src_array(src, dest, n);
    float pi = inverse ? -1 * PI : PI;
    for (int jump = n; jump > 1; jump >>= 2)
    {
        // group * step = n
        int group = n / jump;
        float delta = 2 * pi / jump;
        for (int step = 0; step < jump; step++)
        {
            delta = step * 2 * PI / jump;
            for (int pair = 0; pair < group; pair += 2)
            {
                int k = pair * jump + step;
                int m = k + jump;
                float cos_v = cos(delta);
                float sin_v = sin(delta);
                float re = cos_v * dest[m].Re - sin_v * dest[m].Im;
                float im = cos_v * dest[m].Im + sin_v * dest[m].Re;
                dest[k].Re += re;
                dest[k].Im += im;
                dest[m].Re -= re;
                dest[m].Im -= im;
            }
        }
    }
}

int fft(complex *src, complex *dest, uint32_t n)
{
    int log2n = log2(n);
    if (log2n % 1 != 0) {
        return -1;
    }
    // adjust array base on reversed bit
    perform(src, dest, n, 0);
    return 0;
}

int ifft(complex *src, complex *dest, uint32_t n)
{
    int log2n = log2(n);
    if (log2n % 1 != 0) {
        return -1;
    }
    perform(src, dest, n, 1);
    return 0;
}