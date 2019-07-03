#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
#include<stdlib.h>
int main()
{
    pid_t ret = fork();
    if(ret == 0)
    {

printf("I am child : %d\n", getpid());
        sleep(10);
    }
    else
    {
        printf("I am father: %d\n", getpid());
        sleep(3);
        exit(0);
    }

    return 0;
}
