#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
int x = 0;
pthread_mutex_t mutex;


void* routine1()
{
    printf("Test from threads 1\n");
    for(int i = 0; i < 1000000000; i++)
    {   
        pthread_mutex_lock(&mutex);
        x++;
        pthread_mutex_unlock(&mutex);
    }
    
    // printf("x1 = %d\n",x);
}

// void* routine2()
// {
//     for(int i = 0; i < 1000000000; i++)
//     {
//         pthread_mutex_lock(&mutex);
//         x++;
//         pthread_mutex_unlock(&mutex);
//     }
//     printf("Test from threads 2\n");
//     // printf("x2 = %d\n",x);
// }

int main(int argc,char* argv[])
{
    pthread_t t1,t2;
    
    pthread_mutex_init(&mutex,NULL);
    
    pthread_create(&t1, NULL, &routine1, NULL);
    pthread_create(&t2, NULL, &routine1, NULL);
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
    pthread_mutex_destroy(&mutex);
    
    printf("x = %d\n",x);

    return 0;
}
