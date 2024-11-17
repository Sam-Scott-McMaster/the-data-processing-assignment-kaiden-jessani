#include <stdlib.h>
#include <stdio.h>

R = argv(1);
C = argv(2);

int TwoDArr[][] = new int [] [];

int counter = 3;

for(int i = 0; i<R; i++)
{
    for(int j = 0; j<C; j++)
    {
        TwoDArr[i][j] = argv(counter);
        counter++;
    }
}