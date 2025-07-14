#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

const int max_row = 4;
const int max_length = 9;
const int mid = 4;

int main()
{
    int row = 0;

start_row:

    int col = 0;

start_col:
    if (col == mid + row || col == mid - row)
    {
        printf("*");
    }
    else
    {
        printf(" ");
    };
    col++;

    if (col == max_length)
    {
        printf("\n");
        row ++;
        if (row == max_row)
        {
            ;
        }
        else
        {
            goto start_row;
        }
    }
    else
    {
        goto start_col;
    }

    col = 0;
last_print:
    if (col != max_length){
        printf("*");
        col ++;
        goto last_print;
    }

    return 0;
}