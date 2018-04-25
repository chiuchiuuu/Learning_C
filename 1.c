#include "stdio.h"


int main()
{
    int foo(int a);    
    int a = foo();
    bar();
}

double bar()
{
   foo(2);
}

int foo(int a) 
{
    printf("foo%d\n", a);
}
