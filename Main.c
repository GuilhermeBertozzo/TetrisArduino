#include <stdio.h>
#include <stdlib.h>

int teste(int);

int main()
{
    teste(2);
    return 0;     
}


int teste(int a)
{
    printf("%d", a);
    return 0;
}