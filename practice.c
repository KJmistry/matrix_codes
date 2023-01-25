// // Example program to demonstrate sprintf()
// #include<stdio.h>
// int main()
// {
// 	char buffer[50];
// 	int a = 10, b = 20, c;
// 	c = a + b;
// 	sprintf(buffer, "Sum of %d and %d is %d", a, b, c);

// 	// The string "sum of 10 and 20 is 30" is stored
// 	// into buffer instead of printing on stdout
// 	//printf("%s", buffer);

// 	return 0;
// }
// C program to demonstrate the problem when
// scanf() is used in a loop
#include <stdio.h>

int main()
{
	char c[100];
	//printf("Press q to quit\n");
	do {
		printf("Enter a character\n");
		scanf("%s", &c);
        //fflush(stdin);
		printf("%s\n", c);
	} while (c != 'q');
	
    return 0;
}
