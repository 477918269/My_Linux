#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<stdlib.h>
#include<sys/wait.h>

int main()
{
    pid_t id = fork();
    if(id == 0)
    {
        printf("I am child :.. %d\n", getpid());
        sleep(5);
        exit (13);
    }
    else
    {
        printf("father : pid : %d, ppid : %d\n", getpid(),getppid());
        int status = 0;
        while(1)
        {
            int ret = waitpid(id, &status, WNOHANG);
            if(ret < 0)
            {
                printf("wait error, wait ret : %d\n", ret);
            }
            else if(ret > 0)
            {
                printf("wait success...%d\n", ret);
                printf("wait status   :%d\n", ((status) >> 8) & 0xFF);
                printf("exit signal   :%d\n", status & 0x7F);
                break;
            }
            else
            {
                sleep(1);
                printf("parent wait again! \n");
            }
        }
    }
    return 0;
}
