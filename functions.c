#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

void myStartupFun (void) __attribute__ ((constructor));
void myCleanupFun (void) __attribute__ ((destructor));

void func()
{
	printf ("aaaaaaaaa\n");

}
void myStartupFun (void)
{
	printf ("startup code before main()\n");
}

void myCleanupFun (void)
{
	printf ("cleanup code after main()\n");
}

int main (void)
{
	printf ("hello\n");
	int k = atexit(func);
	// assert(0);
	exit(0);
	// abort();
	// return 0;
	// _Exit(10);
}

// #include <stdio.h>

// int main (void)
// {
// 	printf("\n%d\n", sum(10.5, 5));
// 	return 0;
// }
// float sum (float b, int c)
// {
// 	return (b+c);
// }
