#include<stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    pid_t id;
    printf("Before fork");
    id=fork();
    printf("After fork");
    return 0;
}