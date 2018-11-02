#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/**
 * Return an array of arrays of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int** threeSum(int* nums, int numsSize, int* returnSize)
{
    int **ret = NULL;
    int **rettmp = NULL;
    int cur = 0;
    int i = 0;
    int retnum = 0;
    if (nums == NULL || numsSize == 0) {
        returnSize = NULL;
        return NULL;
    }
    rettmp = (int **) malloc (sizeof(int *) * numsSize);
    if (rettmp == NULL) {
        returnSize = 0;
        return NULL;
    }
    while (cur < numsSize - 2) {
        if (nums[cur] + nums[cur + 1] + nums[cur + 2] == 0) {                //如果满足条件就存储起来
            (rettmp[i]) = (int *) malloc (sizeof(int) * 3);
            (rettmp[i])[0] = nums[cur];
            (rettmp[i])[1] = nums[cur + 1];
            (rettmp[i])[2] = nums[cur + 2];
            retnum++;
            printf("rettmp[i][0] = %d rettmp[i][1] = %d rettmp[i][2] = %d retnum = %d \n", rettmp[i][0], rettmp[i][1], rettmp[i][2], retnum);
        }
        cur++;
    }

    if (retnum > 0) {         //有满足条件的
        ret = (int **) malloc (sizeof(int *) * retnum);
        memcpy(ret, rettmp, retnum);
        *returnSize = retnum;
    }
    free(rettmp);
    return ret;                  
}






int main()
{
    int num[] = {-1, 0, 1, 2, -1, -4};
    int returnSize = 0;
    int size = sizeof(num) / sizeof(num[0]);
    threeSum(num, size, &returnSize);
    return 0;
}

