#include<stdio.h>
#include <pthread.h>

int count = 10;
pthread_mutex_t mutexCount;

void *inc_thread(void *arg)
{
    while (1)
    {
        // LOCK
        pthread_mutex_lock(&mutexCount);
        count++;
        printf("IncThread: %d\n", count);
        pthread_mutex_unlock(&mutexCount);
        // UNLOCK
    }
}

void *dec_thread(void *arg)
{
    while (1)
    {
        // LOCK
        pthread_mutex_lock(&mutexCount);
        count--;
        printf("DecThread: %d\n", count);
        pthread_mutex_unlock(&mutexCount);
        // UNLOCK
    }
}

int main(int argc, char const *argv[])
{
    pthread_t incID, decID;
    printf("Main thread: Before creating hello thread\n");
    pthread_mutex_init(&mutexCount, NULL);
    pthread_create(&incID, NULL, inc_thread, "Hello");
    pthread_create(&decID, NULL, dec_thread, "Bye");
    pthread_join(incID, NULL);
    pthread_join(decID, NULL);

    printf("Main thread: After creating hello thread\n");

    return 0;
}
