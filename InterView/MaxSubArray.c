#include <stdio.h>

int MaxSubArray(int* nums, int numsSize) {
    int summax = nums[0];
    int nowmax = nums[0];
    int i = 1;
    while (i < numsSize) {
        if (nums[i] >= 0) {
            if (nowmax >= 0) {
                nowmax += nums[i];
            }
            else {
                nowmax = nums[i];
            }
        }
        else if (nums[i] < 0){
                if (nowmax >= 0) {
                    nowmax += nums[i];
                }
                else {
                    nowmax = nums[i];
                }
            }
        if (nowmax > summax) {
            summax = nowmax;
        }
        i++;
    }
    return summax;
}
int main()
{
    int nums[] = {-2,1,-3,4,-1,2,1,-5,4};
   // int nums[] = {1};
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    printf("numsSize = %d\n", numsSize);
    printf("%d\n", MaxSubArray(nums, numsSize));
    return 0;
}

