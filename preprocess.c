// // C code to illustrate
// the use of fabs function
#include <stdio.h>
#include <math.h>
extern nam();

int main ()
{
unsigned int a, b;
a = 1234;
b = -3.7;

printf("The absolute value of %u is %lf\n", a, fabs(a));
printf("The absolute value of %d is %lf\n", b, fabs(b));
	
return(0);
}
