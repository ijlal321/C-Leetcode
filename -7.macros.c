#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define findSum(x, y) (x + y)
#define findCube(x, y, c) (findSum(x, y) + c)
#define isUpperCase(x) \
    (x >= 'A' && x <= 'Z')

int main()
{

    printf("%d\n", __LINE__);
    printf("%s\n", __FILE__);
    printf("%s\n", __DATE__);
    printf("%s\n", __TIME__);
#ifdef __STDC__
    printf("%d\n", __STDC__);
#else
    printf("__STDC__ NOT DEFINED");
#endif

    printf("%d\n", findSum(1, 11));
    printf("%d\n", findCube(1, 2, 3));
    printf("%d\n", isUpperCase('A'));

    return 0;
}