#include <stdio.h>
#define macro(m,n) (m)*(n) 
 
int main(void)
{
    printf("%d\t\v",macro(3+1,2+1));
    return 0;
}