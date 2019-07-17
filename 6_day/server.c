#include<stdio.h>
#include<unistd.h>
#include<string.h>
#include<sys/types.h>
#include<fcntl.h>
#include<stdio.h>
#include<sys/stat.h>
int main()
{
    umask(0);
    mkfifo("ALA", 0644);
    int op = open("ALA", O_RDONLY);
    char buf[1024];
    while(1)
    {
        printf("wait ....");
        ssize_t s = read(op, buf, sizeof(buf) - 1);
        if(s > 0)
        {
            buf[s] = 0;
            printf("client read : %s", buf);
        }
        else if(s == 0)
        {
            printf("client quit!\n");
            break;
        }
        else
        {
            printf("read error!\n");
            break;
        }
    }
    close(op);
    return 0;
}
