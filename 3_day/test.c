#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
int n = 0;

int main()
{
    pid_t id = fork();
    if(id == 0)
    {
        printf("child[%d] : %d : %p\n",getpid(), n, &n);
    }
    else
    {
        printf("parent[%d] : %d : %p\n", getpid(), n , &n);
    }
    sleep(1);
    return 0;
}
