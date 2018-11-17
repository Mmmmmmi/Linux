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


void Print(int *array[], int size)
{
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < 3; j++) {
            printf("array[%d][%d] == %d ", i, j, (array[i])[j]);
        }
       printf("\n"); 
    }
}

void Print1(int array[], int size)
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
        *returnSize = 0;
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
    Print1(nums, numsSize);
    if (nums[0] > 0 || nums[numsSize - 1] < 0) {
        *returnSize = 0;
        return NULL;
    }
    i = 0;
    j = 0;
    rettmp = (int **) malloc (sizeof(int *) * 1);
    if (rettmp == NULL) {
        returnSize = 0;
        return NULL;
    }
#if 1
    for (i = 0; i < numsSize; i++) {
        if (nums[i] > 0) {             //第一个为正数 就不用找了
            break;
        }
        if (i > 0 && nums[i] == nums[i - 1]) { continue;}          //防重复   从第二个开始
        int flag = 0 - nums[i];             //需要多大的数值 才能到0 
        int left = i + 1;
        int right = numsSize - 1;
        while(left < right) {
            printf("j == %d flag = %d nums[i] == %d nums[left] == %d nums[right] == %d\n", j, flag, nums[i], nums[left], nums[right]);
            if (nums[left] + nums[right] == flag) {          //如果两数字相加 与 i坐标的反相等 即和为0
                if (j != 0) {
                    if (nums[left] == rettmp[j - 1][1] && nums[right] == rettmp[j - 1][2]) {
                        left++;
                        right--;
                        continue;
                    }
                    int **tmp = (int **)realloc(rettmp, sizeof(int *) * (j + 1));
                    if (tmp == NULL) {
                        printf("realloc error\n");
                    }
                    rettmp = tmp;
                }
                (rettmp[j]) = (int *) malloc (sizeof(int) * 3);
                (rettmp[j])[0] = nums[i];
                (rettmp[j])[1] = nums[left];
                (rettmp[j])[2] = nums[right];
                printf("array[%d][0] == %d array[%d][1] == %d array[%d][2] == %d \n", j, rettmp[j][0], j, rettmp[j][1], j, rettmp[j][2]);
                left++;
                right--;
                j++;
            }
            else if (nums[left] + nums[right] < flag) left++;
            else right--;
        }
    }

#elif    
    while (cur < numsSize - 2 && nums[cur] <= 0) {
        next = cur + 1;
        while(next < numsSize - 1) {
            jmp = next + 1;
            while(jmp < numsSize) {     
                if (nums[cur] + nums[next] == nums[jmp]) {                //如果满足条件就存储起来
                    printf("nums[cur] == %d nums[next] == %d nums[jmp] == %d\n", nums[cur], nums[next], nums[jmp]);
                    if (i != 0 && Search(rettmp, i, nums[cur], nums[jmp])) {
                        jmp++;
                        continue;
                    }
                    if (i != 1) {
                        int **tmp = (int **)realloc(rettmp, sizeof(int *) * (i + 1));
                        if (tmp == NULL) {
                            printf("realloc error\n");
                        }
                        rettmp = tmp;
                    }
                    (rettmp[i]) = (int *) malloc (sizeof(int) * 3);
                    (rettmp[i])[0] = nums[cur];
                    (rettmp[i])[1] = nums[next];
                    (rettmp[i])[2] = nums[jmp];
                    printf("array[%d][0] == %d array[%d][1] == %d array[%d][2] == %d \n", i, rettmp[i][0], i, rettmp[i][1], i, rettmp[i][2]);
                    i++;
                }
                jmp++;
            }
            next++;
        }
        cur++;
    }
#endif
    *returnSize = j;
    return rettmp;  
}





int main()
{
    int num[] = {-2,0,0,2,2};
//    int num[] = {0};
//    int num[] = {-7,-4,-6,6,4,-6,-9,-10,-7,5,3,-1,-5,8,-1,-2,-8,-1,5,-3,-5,4,2,-5,-4,4,7};
//    int num[] = {-1,-2,-3,4,1,3,0,3,-2,1,-2,2,-1,1,-5,4,-3};
//    int num[] = {-1, 0, 1, 2, -1, -4};
    int returnSize = 0;
    int size = sizeof(num) / sizeof(num[0]);
    int ** ret = threeSum(num, size, &returnSize);
    Print(ret,returnSize);
    return 0;
}

