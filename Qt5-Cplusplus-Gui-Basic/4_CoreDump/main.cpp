#include <cstdlib>
#include <stdio.h>

void foo()
{
    int a;
    int *p = &a;
    *p = 1;
    printf("*p = %d\n", *p);
    free(p);
}

int main()
{
    foo();
    return 0;
}
