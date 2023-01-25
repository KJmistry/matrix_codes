#include <stdio.h>
// int main()
// {
//     //int a=1;
//     //int p = ++a  + a++ + printf("-%d",a);
//     printf("%*ck",5,'abcdef');
// }
//#include <stdio.h>
  
// Driver Code
int main()
{
    volatile int a = 10;
    printf("%d %d\n", a, a++);
  
    a = 10;
    printf("%d %d\n", a++, a);
  
    a = 10;
    printf("%d %d %d\n", a, a++, ++a);
    return 0;
}