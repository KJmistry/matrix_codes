#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
int x = 0;
void* routine1()
{
    printf("Test from threads 1\n");
    for(int i = 0; i < 1000000000; i++)
    {
        x++;
    }
    
    // printf("x1 = %d\n",x);
}

void* routine2()
{
    for(int i = 0; i < 1000000000; i++)
    {
        x++;
    }
    printf("Test from threads 2\n");
    // printf("x2 = %d\n",x);
}

int main(int argc,char* argv[])
{
    pthread_t t1,t2;
    pthread_create(&t1, NULL, &routine1, NULL);
    pthread_create(&t2, NULL, &routine2, NULL);
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
    
    printf("x = %d\n",x);

    return 0;
}
