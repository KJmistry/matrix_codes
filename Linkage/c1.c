#include <stdio.h>
  
int animals = 8;
static const int i = 5;
  
int call_me(void)
//int call_me(void)
{
    printf("%d %lu", animals, &animals);
}
