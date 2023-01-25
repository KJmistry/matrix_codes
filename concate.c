#include <stdio.h>
#define con(a,b) a######b
#define string(a) #a
#define mac(a,b)\
        if(a==1&&b==1)\
            printf("test\n");
int main()
{   
    printf("%d\n",con(97,79));
    printf("%s\n",string(192.168.1.100));
    mac(1,1);
    mac(2,2);
    return 0;
}