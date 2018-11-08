#include <stdio.h>
#include <string.h>
#include <stdlib.h>
char* longestCommonPrefix(char** strs, int strsSize) {
    int min = 0;
    int minlen = 0;
    int i = 0;
    int j = 0;
    if (strs == NULL || *strs == NULL) {       //strs为空 或者为空数组
        return NULL;
    }

    minlen = strlen(strs[0]);
    for (i = 1; i < strsSize; i++) {
        int curlen = strlen(strs[i]);
        if (curlen < minlen) {
            min = i;
        }
    }
    minlen = strlen(strs[min]);
  //  printf("min = %d minlen = %d\n", min, minlen);
    for (i = 0; i < minlen; i++) {
        for (j = 0; j < strsSize - 1; j++) {
            char *cur = strs[j];
            char *next = strs[j + 1];
            if (cur[i] != next[i]) {
                break;
            }
   //         printf("i = %d j = %d cur[i] = %c next[i] = %c\n", i, j, cur[i], next[i]);
        }
        if (j < strsSize - 1) {
            i--;
            break;
        }
    }
  //  printf("i == %d\n", i);
    char *tmp  = (char *) malloc (sizeof(char) * (i + 2));
    if (tmp == NULL) {
        return NULL;
    }

    memcpy(tmp, strs[min], i + 1);
    tmp[i + 1] = 0;
    return tmp;
    
}


int main()
{
    char a1[] = "flower";
    char a2[] = "flow";
    char a3[] = "flight";
    char *array[] = {a1, a2, a3};
    int size = sizeof(array) / sizeof(array[0]);
    printf("%s\n", longestCommonPrefix(array, size));
    return 0;
}

