#include <stdio.h>
#include <stdbool.h>
int main()
{   
    int m=10;
    int *a[10];
    int *ptr = a;
    printf("%d----%d\n",sizeof(a),sizeof(ptr));
}