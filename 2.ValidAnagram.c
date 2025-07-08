#include <stdbool.h>
#include <stdio.h>
#include <string.h>

bool isAnagram(char* s, char* t);
bool is_all_zero(int * arr, int size);

int main() {
    char s[] = "anagram", t[] = "nagaram";
    printf("result is %s", isAnagram(s, t) ? "true" : "false");
    return 0;
}

bool isAnagram(char* s, char* t) {

    if (strlen(s) != strlen(t)){
        return false;
    }

   int res[26] = {0};

   for (int i = 0; i < strlen(s); i++){
    res[s[i] - 'a'] ++;
    res[t[i] - 'a'] --;
   };

   return is_all_zero(res, 26);
}


bool is_all_zero(int * arr, int size){
    for (int i = 0; i < size; i++){
        if (arr[i] != 0) {
            return false;
        }
    }
    return true;
}