#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
int main()
{
    printf("cpp foever");
    sleep(1);    
    _exit(10);
     //exit(10);
    return 1000;
}

