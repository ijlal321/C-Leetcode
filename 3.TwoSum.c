#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int *twoSum(int *nums, int numsSize, int target, int *returnSize);

int main()
{
    int nums[] = {3, 2, 4};
    int returnSize = 2;
    int *result = twoSum(nums, 3, 6, &returnSize);

    if (result != NULL && returnSize == 2)
    {
        printf("result is [%d, %d]\n", result[0], result[1]);
        free(result); // don't forget to free malloc'ed memory
    }
    else
    {
        printf("No solution found.\n");
    }

    return 0;
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *twoSum(int *nums, int numsSize, int target, int *returnSize)
{
    int *res = (int *)malloc(2 * sizeof(int));

    for (int i = 0; i < numsSize; i++)
    {
        for (int j = i+1; j < numsSize; j++)
        {
            if (nums[i] + nums[j] == target)
            {
                res[0] = i;
                res[1] = j;
                *returnSize = 2;
                return res;
            }
        }
    }
    *returnSize = 0;
    return NULL;
}