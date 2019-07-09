#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>


int main()
{
    //execlp("ls", "ls",NULL);
    //execl("/usr/bin/ls", "ls", "-a", "-l", "-i", NULL);   
    char *argv[] = {"ls", "-a", "-l", "-i", NULL};
    //execv("/usr/bin/ls", argv);
    execvp("ls", argv);
    return 0;
}
