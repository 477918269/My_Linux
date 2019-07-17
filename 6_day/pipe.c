#include<unistd.h>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>


int main()
{
    int fd[2] = {0};
    pipe(fd);

    pid_t id = fork();
    if(id == 0)//子进程写
    {
        close(fd[0]);
        int count = 0;
        char buf[] = "I'm child";
        while(1)
        {
            write(fd[1], buf, strlen(buf));
            printf("%d\n", count += strlen(buf));
            //close(fd[1]);
            sleep(1);
            //break;
            //sleep(1);
        }
    }
    else//父进程读
    {
        close(fd[1]);
        char ret[1024];
        while(1)
        {
            sleep(1);
            ssize_t s = read(fd[0], ret, sizeof(ret) - 1);
            if(s < 0)
            {
                printf("printf error");
                break;
            }
            else if(s > 0)
            {
                ret[s] = 0;
                printf("parent get child : %s\n", ret);
            }
            else
            {
                printf("read file end!\n");
                break;
            }
            break;
        }
        close(fd[0]);
        int status = 0;
        waitpid(id, &status, 0);
        printf("sign : %d\n", status & 0x7F);
    }
    return 0;
}
