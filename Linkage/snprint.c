// // // // // C program to demonstrate snprintf()
// // // // #include <stdio.h>
// // // // #include <string.h>
// // // // int main()
// // // // {
// // // // 	char buffer[50];
// // // // 	char* s = "geeksforgeeks";

// // // // 	// Counting the character and storing
// // // // 	// in buffer using snprintf
// // // // 	printf("Writing %s onto buffer"
// // // // 		" with capacity 6",
// // // // 		s);
// // // // 	int j = snprintf(buffer, 6, "%s\n", s);

// // // // 	// Print the string stored in buffer and
// // // // 	// character count
// // // // 	printf("\nString written on "
// // // // 		"buffer = %s", buffer);
// // // //   	int k = strlen(buffer);
// // // // 	printf("\nValue returned by "
// // // // 		"snprintf() method = %d\n%d\n", j,k);
    
// // // //     for(int l=0;l<10;l++){
// // // //         printf("%d %d\n",buffer[l],l);
// // // //     }

// // // // 	return 0;
// // // // }
// // // // C program to demonstrate the difference
// // // // between %i and %d specifier



// #include <stdio.h>

// int main()
// {
// 	int a, b, c;

// 	printf("Enter value of a in decimal format:");
// 	scanf("%d", &a);

// 	printf("Enter value of b in octal format: ");
// 	scanf("%i", &b);

// 	printf("Enter value of c in hexadecimal format: ");
// 	scanf("%i", &c);

// 	printf("a = %i, b = %i, c = %i", a, b, c);

// 	return 0;
// }
// // // C program to illustrate situation
// // // where flush(stdin) is required only
// // // in certain compilers.









// // #include <stdio.h>
// // #include<stdlib.h>
// // int main()
// // {
// // 	char str[20];
// // 	int i;
// // 	for (i=0; i<2; i++)
// // 	{
// // 		scanf("%[^A]s", str);
// // 		printf("%s\n", str);
// // 		fflush(stdin);
// // 	}
// // 	return 0;
// // }


// // C program to demonstrate use of *s
// #include <stdio.h>
// int main()
// {
// 	char a[100];
// 	scanf("%*d %s", &a);
// 	printf("Input value read : a=%s", a);
// 	return 0;
// }
// #include <stdio.h>
// int main()
// {
//     const int a=9;
//     printf("%d\n",a);
// }
#include <stdio.h>

int main()
{
	char a[100];

	for (int i = 0; i<5;i++)
    {
        scanf("%s", &a);
        printf("String %d: %s\n",i, a);
    }
	return 0;
}