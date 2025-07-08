#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

// Forward declaration
bool containsDuplicate(int* nums, int numsSize);

int main() {
    int nums[] = {1,2,3,4};
    printf("result is %s", containsDuplicate(nums, 4) ? "true" : "false");
    return 0;
}

// Comparison function for qsort
int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

bool containsDuplicate(int* nums, int numsSize) {
    // Handle edge cases
    if (numsSize <= 1) {
        return false;
    }
    
    // Sort the array
    qsort(nums, numsSize, sizeof(int), compare);
    
    // Check for adjacent duplicates
    for (int i = 1; i < numsSize; i++) {
        if (nums[i] == nums[i - 1]) {
            return true;
        }
    }
    
    return false;
}