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
    return dest;
}

void perform(complex *src, complex *dest, uint32_t n, int inverse)
{
    adjust_src_array(src, dest, n);
    float pi = inverse ? -1 * PI : PI;
    for (int group_step = n; group_step > 1; group_step <<= 2)
    {
        // group * step = n
        int group = n / group_step;
        float p = 2 * pi / group_step;
        for (int step = 0; step < group_step; step++)
        {
            p = step * 2 * PI / group_step;
            for (int pair = 0; pair < group; pair += 2)
            {

                int l1 = pair * group_step + step;
                int l2 = (pair + 1) * group_step + step;
                float re = cos(p);
                float im = sin(p);
                float new_re = re * dest[l2].Re - im * dest[l2].Im;
                float new_im = re * dest[l2].Im + im * dest[l2].Re;
                dest[l1].Re += new_re + new_re;
                dest[l1].Im += new_im;
                dest[l2].Re -= new_re;
                dest[l2].Im -= new_im;
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
