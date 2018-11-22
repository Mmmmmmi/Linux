//给定一个包括 n 个整数的数组 nums 和 一个目标值 target。找出 nums 中的三个整数，使得它们的和与 target 最接近。返回这三个数的和。假定每组输入只存在唯一答案。

//例如，给定数组 nums = [-1，2，1，-4], 和 target = 1.

//与 target 最接近的三个数的和为 2. (-1 + 2 + 1 = 2).

//int threeSumClosest(int* nums, int numsSize, int target) {
    
//}

#include <stdio.h>


void Swap(int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

int threeSumClosest(int* nums, int numsSize, int target) {
    int ret = 0;
    int i = 0;
    int closest = 0;
    for (i = 0; i < numsSize - 1; i++) {
        int flag = 1;
        for (int j = 0; j < numsSize - 1 - i; j++) {
            if (nums[j] > nums[j + 1]) {
                Swap(nums + j, nums + j + 1);
                flag = 0;
            }
        }
        if (flag == 1) {
            break;
        }
    }
    i = 0;
    while(i < numsSize - 2) {
        int left = i + 1;
        int right = numsSize - 1;
        int flag = target - nums[i];
        if (i == 0) {
            ret = nums[left] + nums[right] + nums[i];
            closest = target - ret > 0 ? target - ret : ret - target;
        }
        while(left < right) {
            int sub = nums[left] + nums[right] - flag;
            printf("nums[i] = %d nums[left] = %d nums[right] = %d flag = %d sub = %d", nums[i], nums[left], nums[right], flag, sub);
            if (sub == 0) {
                return nums[left] + nums[right] + nums[i];
            }
            else if (sub > 0){
                if (sub < closest) {
                    closest = sub;
                    ret = nums[left] + nums[right] + nums[i];
                }
                right--;
               }
            else if (sub < 0){
                if (-sub < closest) {
                    closest = -sub;
                    ret = nums[left] + nums[right] + nums[i];
                }
                left++;
               }
            printf("    closest = %d ret = %d\n", closest, ret);
            }
        i++;
    }
    return ret;
}

int main()
{
//      int num[] = {-2,0,0,2,2};
//    int num[] = {0,0,0};
//    int num[] = {0,1,2};
//    int num[] = {1,1,1,0};
    int num[] = {-2,-1,0,1,5};
//
    int size = sizeof(num) / sizeof(num[0]);
    for (int i = 0; i < size; i++) {
        printf("%d   ", num[i]);
    }
    printf("\n");
    printf("%d\n", threeSumClosest(num, size, 1));
    return 0;
}

