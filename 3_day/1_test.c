#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
int n = 0;

int main()
{
    pid_t id = fork();
    if(id == 0)
    {
        n = 100;
        printf("child[%d] : %d : %p\n",getpid(), n, &n);
    }
    else
    {
        sleep(3);
        printf("parent[%d] : %d : %p\n", getpid(), n , &n);
    }
    sleep(1);
    return 0;
}
