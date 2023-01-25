// // // C/C++ program to demonstrate return value
// // // of printf()
// // #include <stdio.h>

// // int main()
// // {
// // 	char st[100];
// // 	//printf("%d\n", getchar(st));
    
// // 	scanf("%[^\n]s",st);
// //     printf("%s",st);
// //     return 0;
// // }

// // C program to show the use of puts

// // #include <stdio.h>
// // int main()
// // {
// // 	puts("Geeksfor");
// // 	puts("Geeks");

// // 	getchar();
// // 	return 0;
// // }

// // C program to show the use of fputs and getchar
// #include <stdio.h>
// int main()
// {
// 	fputs("Geeksfor", stdout);
// 	fputs("Geeks", stdout);

// 	getchar();
// 	return 0;
// }

// C program to show the side effect of using
// %s in printf
// #include <stdio.h>
// int main()
// {   
int a,b;
//     //char c='%';
// 	// % is intentionally put here to show side effects of
// 	// using printf(str)
// 	//printf("Geek%nsvs\0dfvb%nvvdf",&a,&b);
// 	//printf("\n%d%d",a,b);
//     // printf("\n%%");
//     // printf("%d", c);
//     printf("%c","%");

// 	return 0;
// }
/* Program to print %*/
#include<stdio.h>
/* Program to print %*/
int main()
{   printf("Geek%nsvs\0dfvb%nvvdf",&a,&b);
   printf("%c", "%");
    return 0;
}



