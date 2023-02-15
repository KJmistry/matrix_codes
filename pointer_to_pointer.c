// C program to demonstrate sizeof normal and double pointer.
#include <stdio.h>

int main()
{

	int a = 5;
	int* ptr = &a;
	int** d_ptr = &ptr;

	printf(" Size of normal Pointer: %d \n", **d_ptr);
    **d_ptr=10;
	printf(" Size of normal Pointer: %d \n", **d_ptr);
    

	return 0;
}
