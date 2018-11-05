#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/**
 * Return an array of arrays of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */

void Swap(int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void Print(int *array, int size)
{
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

int** threeSum(int* nums, int numsSize, int* returnSize)
{
    int **ret = NULL;
    int **rettmp = NULL;
    int i = 0;
    int j = 0;
    int flag = 0;
    int cur = 0;
    int retnum;
    int jmp = 0;
    int next = 0;
    if (nums == NULL || numsSize == 0) {
        returnSize = NULL;
        return NULL;
    }
    
    for (i = 0; i < numsSize - 1; i++) {
        flag = 1;
        for (j = 0; j < numsSize - 1 - i; j++) {
            if (nums[j] > nums[j + 1]) {
                Swap(nums + j, nums + j + 1);
                flag = 0;
            }
        }
        if (flag == 1) {
            break;
        }
    }


   rettmp = (int **) malloc (sizeof(int *) * numsSize);
    if (rettmp == NULL) {
        returnSize = 0;
        return NULL;
    }
    while (cur < numsSize - 2 && nums[cur] <= 0) {
        next = cur + 1;
        while(next < numsSize - 1) {
            jmp = next + 1;
            while(jmp < numsSize) {     
                if (nums[cur] + nums[next] + nums[jmp] == 0) {                //如果满足条件就存储起来
                    (rettmp[i]) = (int *) malloc (sizeof(int) * 3);
                    (rettmp[i])[0] = nums[cur];
                    (rettmp[i])[1] = nums[next];
                    (rettmp[i])[2] = nums[jmp];
                    printf("nums[cur] == %d nums[next] == %d nums[jmp] == %d\n", nums[cur], nums[next], nums[jmp]);
                    retnum++;
                }
                jmp++;
            }
            next++;
        }
        cur++;
    }
    printf("returnnum = %d\n", retnum);

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

