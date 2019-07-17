#include<stdio.h>
#include<unistd.h>

int main()
{
    mkfifo("ALA", 0644);
    return 0;
}
