#include<stdio.h>
#include<unistd.h>
#include<string.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<stdlib.h>
#include<fcntl.h>

int main()
{
    int op = open("ALA", O_WRONLY);
    char buf[1024];
    while(1)
    {
        printf("Please Enter : ");
        fflush(stdout);
        ssize_t s = read(0, buf, sizeof(buf) - 1);
        if(s > 0)
        {
            buf[s] = 0;
            write(op, buf, strlen(buf));
        }
    }
    close(op);
    return 0;
}
