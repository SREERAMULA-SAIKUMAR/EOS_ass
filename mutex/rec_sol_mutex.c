#include<stdio.h>
#include <pthread.h>

int count = 10;
pthread_mutex_t mutexCount;
pthread_mutexattr_t mutexCountAttr;

void square()
{
        printf("IncThread: Grabbing mutex inside function square\n");

        pthread_mutex_lock(&mutexCount);
        printf("IncThread: Inside CS inside square\n");

        count = count * count;
        pthread_mutex_unlock(&mutexCount);
        printf("IncThread: Releasing mutex inside function square\n");
}

void *inc_thread(void *arg)
{
    while (1)
    {
        // LOCK
        printf("IncThread: Grabbing %d\n", count);
        pthread_mutex_lock(&mutexCount);
        printf("IncThread: Inside CS\n");
        count++;
        square();
        printf("IncThread: %d\n", count);
        pthread_mutex_unlock(&mutexCount);
        printf("IncThread: Releasing%d\n", count);

        // UNLOCK
    }
}

void *dec_thread(void *arg)
{
    while (1)
    {
        // LOCK
        printf("DecThread: Grabbing mutex\n");
        pthread_mutex_lock(&mutexCount);
        printf("DecThread: Inside CS\n");
        count--;
        printf("DecThread: %d\n", count);
        pthread_mutex_unlock(&mutexCount);
        printf("DecThread: Releasinging mutex\n");
        // UNLOCK
    }
}

int main(int argc, char const *argv[])
{
    pthread_t incID, decID;
    printf("Main thread: Before creating hello thread\n");
    pthread_mutex_init(&mutexCount, NULL);

    pthread_mutex_init(&mutexCountAttr, NULL);
    pthread_mutexattr_settype(&mutexCountAttr, PTHREAD_MUTEX_RECURSIVE);

    pthread_mutex_init(&mutexCount, &mutexCountAttr);
    pthread_create(&incID, NULL, inc_thread, NULL);
    pthread_create(&decID, NULL, dec_thread, NULL);

    pthread_join(incID, NULL);
    pthread_join(decID, NULL);
    pthread_mutex_destroy(&mutexCount);
    printf("Main thread: After creating hello thread\n");

    return 0;
}
