#include<stdio.h>
#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/shm.h>

int main()
{
    key_t k = ftok("Makefile", 0x6666);
    if(k < 0)
    {
        printf("ftok error\n");
        return 1;
    }
    int sh_mid = shmget(k, 4096, 0);
    if(sh_mid < 0)
    {
        printf("shmget error\n");
        return 2;
    }
    char* p = (char*)shmat(sh_mid, NULL, 0);
    int i = 0;
    while(i < 4096)
    {
        p[i] = 'a' + i;
        i++;
        p[i] = 0;
        sleep(1);
    }



    shmdt(p);
    return 0;
}
