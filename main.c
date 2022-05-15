#include <stdio.h>
#include "complex.h"
#include "fft.h"

int main()
{

    complex input[8] = {{0., 0.}, {1., 0.}, {2., 0.}, {3., 0.}, {4., 0.}, {5., 0.}, {6., 0.}, {7., 0}};
    complex output[8];
    fft(input, output, 8);
    for (int i = 0; i < 8; i++)
    {
        printf("%f %f j \n", output[i].Re, output[i].Im);
    }
    return 0;
}