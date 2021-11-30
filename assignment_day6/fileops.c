#include<stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
int main()
{
    int fd;
    fd=open("desd.txt",O_WRONLY);

    if(-1==fd)
    {
        printf("Error\n");
    }
    write(fd,"DESD",4);
    close(fd);
    return 0;
}