// CPP program to illustrate (##) operator
#include <stdio.h>
// #define concat(a, b) a##b
int main(void)
{   
    int a=10;
    char k[100];
    if(!a)
    do{
        printf("if");
    }while(0);
    else
    {
        printf("elif\n");
    }
	//printf("%d", concat('x', 'y'));
    printf("%d--",printf("\t\n"));
    printf("%d",a*=10+20);
    scanf("%[^K]s",&k);
    printf("\n%s",k);
    

}
