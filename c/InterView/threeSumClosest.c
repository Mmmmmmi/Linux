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
    int tmptarget = target;
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
        tmptarget = target;
        while(left < right) {
            if (i == 0) {
                ret = nums[i] + nums[left] + nums[right];
                closest = ret - tmptarget> 0 ? ret - tmptarget : tmptarget - ret;
            }
            else {
                int subtmp = 0;
                int add = nums[i] + nums[left] + nums[right];
                if (tmptarget < 0 && add < 0) {
                    subtmp = tmptarget - add > 0 ? tmptarget - add : add - tmptarget;
                } else if (tmptarget > 0 && add > 0) {
                    subtmp = tmptarget - add > 0 ? tmptarget - add : add - tmptarget;
                } else if (tmptarget < 0 && add > 0) {
                    subtmp = add - tmptarget;
                } else if (tmptarget > 0 && add < 0) {
                    subtmp = tmptarget - add;
               }
               if (subtmp > closest) {
                    return ret;
               }
               else {
                    closest = subtmp;
                    ret = add;
                    if (add > tmptarget && target > 0) right--;
                    if (add > tmptarget && target < 0) left++;
                    if (add < tmptarget && target > 0) left++;
                    if (add < tmptarget && target < 0) righ -lstdc++t--;
                    }
               }
            }
    }
    return ret;
}

int main()
{
    int num[] = {-2,0,0,2,2};
    int size = sizeof(num) / sizeof(num[0]);
    printf("%d\n", threeSumClosest(num, size, 0));
    return 0;
}

