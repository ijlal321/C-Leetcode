#include <stdlib.h>
#include <stdio.h>
#include "loopDisplay.h"

static void only_this_file();
int sum(int num);

int loop_counter = 5;

static double this_file_only  = 10.25;
float whole_program  = 10.25f;

int main(){
    int temp1 = 10;
    static float per_storage = 10.2f;

    register int reg = 10;
    only_this_file();
    printf("%d ", sum(25));
    printf("%d ", sum(15));
    printf("%d ", sum(30));

    printf("\n");
    for (int i = 0; i < loop_counter; i++){
        Display();
    }
}


static void only_this_file(){
    printf("this file only");
}

int sum(int num){
    static int res = 0;
    res += num;
    return res;
}