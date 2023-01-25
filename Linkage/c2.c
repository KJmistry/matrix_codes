#include <stdio.h>
// #include "c1.c"
extern int animals ;
int call_me();

int main()
{
    animals=10;
    //int call_me(void);
    // animals = 2;
    printf(" %d", animals);
    // int call_me(void) {
         printf("hey there\n%lu\n",&animals);
    //     return 0;
    // }
    call_me();
    return 0;
}