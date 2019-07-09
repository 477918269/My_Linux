#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>


int main()
{
    char*const env[]={"ALA=aoliao",NULL};

    execle("/home/aoliao/cmd/nALA/4_day/test/test", "test", NULL, env);
    printf("it's ok");
    exit(1);
}
