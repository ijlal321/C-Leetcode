#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdarg.h>

int sum_all(int count, ...);

int main() {

    int (*my_fun)(int, ...) = sum_all;
    printf("%d\n", sum_all(5, 1,2,3,4,5));
    printf("%d\n", sum_all(5, 1,1,1,1,1));
    printf("%d\n", sum_all(5, 2,2,2,2,1));
    return 0;
}


int sum_all(int count, ...){
    va_list arg1;
    va_start(arg1, count);


    int res = 0;
    for ( int i = 0; i < count; i++){
        res += va_arg(arg1, int);
    }
    return res;
}
