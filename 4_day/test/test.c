#include<stdio.h>
#include<stdlib.h>

int main()
{
    int i = 0;
    for(; i < 10; i++)
    {
        printf("I can : %d, %s\n", i, getenv("ALA"));
    }
    return 0;
}
