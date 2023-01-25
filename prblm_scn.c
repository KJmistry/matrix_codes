#include <stdio.h>
  
int main()
{
    char c[100];
    printf("Press q to quit\n");
    do {
        printf("Enter a character\n");
        scanf("%s", &c);
        printf("%s\n", c);
    } while (c != 'q');
    return 0;
}