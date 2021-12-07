#include <stdio.h> 
#include <sys/types.h> 
#include <sys/stat.h> 
#include <fcntl.h> 
#include <unistd.h> 
#include <stdlib.h> 
#include <string.h> 

int main(int argc, char const *argv[])
{ 
    char buf; 
    int fd_one, fd_two; 
    fd_one = open("Source_file.txt", O_RDONLY); 
    if (fd_one == -1) 
    { 
        printf("Error opening first_file\n"); 
        close(fd_one); 
        return; 
    }
    //else
        fd_two = open("Destination_file.txt", O_WRONLY); 
        while(read(fd_one, &buf, 1)) 
        { 
            write(fd_two, &buf, 1); 
        } 
        printf("Successful copy"); 
        close(fd_one); 
        close(fd_two);
        return 0;
}

