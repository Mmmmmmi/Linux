/*
 * 假设按照升序排序的数组在预先未知的某个点上进行了旋转。

( 例如，数组 [0,1,2,4,5,6,7] 可能变为 [4,5,6,7,0,1,2] )。

搜索一个给定的目标值，如果数组中存在这个目标值，则返回它的索引，否则返回 -1 。

你可以假设数组中不存在重复的元素。

你的算法时间复杂度必须是 O(log n) 级别。

示例 1:

输入: nums = [4,5,6,7,0,1,2], target = 0
输出: 4
示例 2:

输入: nums = [4,5,6,7,0,1,2], target = 3
输出: -1


int search(int* nums, int numsSize, int target) {
    
}

*/


#include <unistd.h>
#include <stdio.h>

int search(int* nums, int numsSize, int target) {
    int left = 0;
    int right = numsSize - 1;
    int mid = 0;
    if (nums[0] <= nums[numsSize - 1]){
        if (target < nums[0] || target > nums[numsSize - 1])
        return -1;
    }   
    if (nums[0] < nums[numsSize - 1]) {
        while (left <= right) {
            mid = left + ((right - left) >> 1);
            if (nums[mid] == target) {
                return mid;
            }else {
                if (nums[mid] > target) {
                    right = mid - 1;
                }else {
                    left = mid + 1;
                }
            }
        }
    }else {
        while(left <= right) {
            mid = left + ((right - left) >> 1);
            printf("nums[left] == %d nums[right] == %d nums[mid] == %d\n", nums[left], nums[right], nums[mid]);
            if (nums[mid] == target) {
                return mid;
            }
            if (left == right && nums[mid] != target) {
                return -1;
            }else if (nums[mid] > target) {
                if (nums[left] > target) {
                    left = mid + 1 > numsSize - 1 ? numsSize - 1 : mid + 1;
                }else {
                    if (nums[left] == target) {
                        return left;
                    }
                    right = mid - 1 > 0 ? mid - 1 : 0;
                }
            }else {
                if (nums[left] < target) {
                    left = mid + 1 > numsSize - 1 ? numsSize - 1 : mid + 1;
                }else {
                    if (nums[left] == target) {
                        return left;
                    }
                    right = mid - 1 > 0 ? mid - 1 : 0;
                }
            }
        }
    }
    return -1;
}


int main()
{
//    int array[] = {1, 3};
    int array[] = {5, 1, 3};
//    int array[] = {4,5,6,7,0,1,2};
//    int array[] = {5,6,7,0,1,2,4};
    int size = sizeof(array) / sizeof(array[0]);
    printf("%d\n", search(array, size, 3));
    return 0;
}

