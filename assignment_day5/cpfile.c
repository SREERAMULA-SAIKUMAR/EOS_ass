#include<stdio.h>
#include<stdlib.h>
#include <sys/types.h>
#include <unistd.h>
int main(int argc, char *argv[])
{
    pid_t id,pa_id;
    id=getpid();
    pa_id=getppid();
    printf("process id = %d\nparent process id = %d\n",id,pa_id);
}