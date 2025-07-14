#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main()
{
    int num, shift;

    printf("enter num to input: ");
    scanf("%d", &num);

    printf("enter bit to shift: ");
    scanf("%d", &shift);

    if ((num >> shift) & 1)
        printf("Nth bit is 1 \n");
    else
        printf("Nth bit is 0 \n");

    printf("the res after setting nth bit is: %d", (1 << shift) | num);

    return 0;
}