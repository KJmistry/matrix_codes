// #include <stdio.h>


// int main()
// {
//     for(int i = 0 ; i < 5; i++)
//     {
//     label: printf("hey \n");
//     }    
//     return 0;
// }


// fun()
// {
    
//         goto label;
// }
// C program to illustrate the working
// of _Noreturn type function.
#include <stdio.h>
#include <stdlib.h>

// Nothing to return
//_Noreturn int show();
_Noreturn void show()
{
	printf("BYE BYE");
//   return 1;
}
int main(void)
{
	printf("Ready to begin...\n");
	show();

	printf("NOT over till now\n");
	return 0;
}
