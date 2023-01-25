#include <stdio.h>

int i ;
int f (int *x, int *y)
{           
    i = 100;
    *x = 10;
    int t = *y;
    *y = *y + i;
}
int main ()
{
    int j = 60;
    i = 50;
    f (&i, &j);
    printf("%d  %d  \n",i,j);
    return 0;
}
