#include<stdio.h>
#include<stdlib.h>

int main()
{
    char* env = getenv("MYENV");
    printf("%s\n", env);
    return 0;

}
