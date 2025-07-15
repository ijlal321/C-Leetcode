#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

union Student
{
    char letterGrade;
    int roundedGrade;
    float exactGrade;
};


int main() {

    union Student var1, var2;
    var1.roundedGrade = 20;

    printf("var1 grade is: %d", var1.roundedGrade);

    return 0;
}