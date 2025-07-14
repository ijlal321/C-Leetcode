#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>


typedef struct
{
    unsigned int transparency: 1;
    unsigned int color: 3;
    unsigned int border: 1;
    unsigned int border_color: 3;
    unsigned int border_style: 2;
} Box;



int main() {
    Box b1 = {0, 7, 1, 7, 2};

    return 0;
}