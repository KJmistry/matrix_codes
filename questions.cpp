//#include <stdio.h>
#include <iostream>
int main(void)
{
	int i = 10;
	int j = 20;
	/* ptr is pointer to constant */
	int *const ptr = &i;
	*ptr = 100;
    printf("i: %d\n", i);
	//ptr = &j;
    *ptr = 200;		 
	printf("j: %d\n", j);
	
	if(isgraph('\n'))
	{
		printf("if");
	}
	else
	{
		printf("idgdfghf");
	}
	return 0;
}
