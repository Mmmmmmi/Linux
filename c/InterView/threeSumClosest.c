//给定一个包括 n 个整数的数组 nums 和 一个目标值 target。找出 nums 中的三个整数，使得它们的和与 target 最接近。返回这三个数的和。假定每组输入只存在唯一答案。

//例如，给定数组 nums = [-1，2，1，-4], 和 target = 1.

//与 target 最接近的三个数的和为 2. (-1 + 2 + 1 = 2).

//int threeSumClosest(int* nums, int numsSize, int target) {
    
//}

#include <stdio.h>



int threeSumClosest(int* nums, int numsSize, int target) {
    int ret = 0;
    int i = 0;
    int left = nums[0];
    int right = nums[numsSize - 1];
    int closest = 0;
    while(i < numsSize - 2) {
        left = nums[i];
        right = nums[numsSize - 1];
    }
}

int main()
{
    printf("Hello world\n");
    return 0;
}

