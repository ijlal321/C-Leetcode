#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <setjmp.h>

void error_recovery();

jmp_buf env;

int main()
{
    int res = setjmp(env);
    if (res)
    {
        printf("function endeeded in error");
        return 0;
    }
    error_recovery();
    printf("function endeeded in peace");
    return 0;
}

void error_recovery()
{
    printf("Some very serious distasterous error happened\n");
    longjmp(env, 42);
}