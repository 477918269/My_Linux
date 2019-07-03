#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>

int main()
{
    pid_t id = fork();
    if(id > 0)
    {

            printf("parent[%d] is sleeping", getpid());
            sleep(30);    
    }
    else
    {
            printf("child[%d] is begin", getpid());
            sleep(5);
            exit(EXIT_SUCCESS);
        
    }
    return 0;
}
