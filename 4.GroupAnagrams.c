#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

char ***groupAnagrams(char **strs, int strsSize, int *returnSize, int **returnColumnSizes);

bool isAnagram(char *s, char *t);
bool is_all_zero(int *arr, int size);

int main()
{
    char *strs[] = {"eat", "tea", "tan", "ate", "nat", "bat"};
    int returnSize;
    int *returnColumnSizes;
    char **strs_ptr = strs;
    printf("result is %s", groupAnagrams(strs_ptr, 6, &returnSize, &returnColumnSizes));
    return 0;
}

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
char ***groupAnagrams(char **strs, int strsSize, int *returnSize, int **returnColumnSizes)
{
    char ***res = malloc(strsSize * sizeof(char **));
    *returnColumnSizes = malloc(strsSize * sizeof(int));
    int cur_row_nr = 0;

    // this to make sure we dont check again if an element is already in some array
    int *visited = malloc(strsSize * sizeof(int));
    for (int i = 0; i < strsSize; i++)
    {
        visited[i] = i; // we will mark the element at index i as -1, meaning we have already gone there
    }

    for (int i = 0; i < strsSize; i++)
    {
        if (visited[i] == -1)
            continue;

        // mark as visited
        visited[i] = -1;

        // lets create a new array of size strsize
        char **row = malloc(strsSize * sizeof(char *));
        row[0] = strs[i];
        int row_size = 1;
        for (int j = i + 1; j < strsSize; j++)
        {
            if (visited[j] == -1)
                continue;
            if (isAnagram(strs[i], strs[j]))
            {
                // mark as visited
                visited[j] = -1;

                // add to row
                row[row_size] = strs[j];

                // increae row_size
                row_size += 1;
            }
        }
        res[cur_row_nr] = row;

        (*returnColumnSizes)[cur_row_nr] = row_size;
        cur_row_nr += 1;

    };

    free(visited);
    
    *returnSize = cur_row_nr;
    return res;
}

bool isAnagram(char *s, char *t)
{

    if (strlen(s) != strlen(t))
    {
        return false;
    }

    int res[26] = {0};

    for (int i = 0; i < strlen(s); i++)
    {
        res[s[i] - 'a']++;
        res[t[i] - 'a']--;
    };

    return is_all_zero(res, 26);
}

bool is_all_zero(int *arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        if (arr[i] != 0)
        {
            return false;
        }
    }
    return true;
}