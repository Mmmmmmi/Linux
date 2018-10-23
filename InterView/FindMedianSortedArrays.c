#include <stdio.h>
double FindMedianSortedArrays(int *nums1, int nums1Size, int* nums2, int nums2Size)
{
    double ret = 0;
    int num = nums1Size + nums2Size;    //总数
    int flag1 = (num + 1) / 2;
    int flag2 = (num + 2) / 2;
    int val1 = 0;
    int val2 = 0;
    int cur1 = 1;
    int cur2 = 1;
    int tmp1 = 0;
    int tmp2 = 0;
    int tmp = 0;
    int now = 1;
    if (nums1Size == 0 || nums2Size == 0) {
        if (nums1Size == 0) {
            val1 = nums2[flag1 - 1];
            val2 = nums2[flag2 - 1];
        }
        else if (nums2Size == 0) {
            val1 = nums1[flag1 - 1];
            val2 = nums1[flag2 - 1];
        }

    } 
    else {
        while (cur1 <= nums1Size && cur2 <= nums2Size && now <= flag2) {
            tmp1 = nums1[cur1 - 1];
            tmp2 = nums2[cur2 - 1];
            tmp = tmp1 >= tmp2 ? tmp2 : tmp1;
            if (now == flag1) {
                val1 = tmp;
                now++;
            }
            printf("cur1 = %d cur2 = %d now = %d val1 = %d val2 = %d\n", cur1, cur2, now, val1, val2);
            if (now == flag2) {
                val2 = tmp;
            }

        }
        //    printf("cur1 = %d cur2 = %d now = %d val1 = %d val2 = %d\n", cur1, cur2, now, val1, val2);
            now++;
            cur1++;
        }
       // printf("cur1 = %d cur2 = %d now = %d val1 = %d val2 = %d\n", cur1, cur2, now, val1, val2);
        while (cur1 <= nums1Size && now <= flag2) {   //cur1 没走完 并且还未到中位数
            tmp1 = nums1[cur1 - 1];
            if (now == flag1) {
                val1 = tmp1;
            }
            if (now == flag2) {
                val2 = tmp1;
                break;
            }
            now++;
            cur1++;
        }
        while (cur2 <= nums2Size && now <= flag2) {   //cur2 没走完 并且还未到中位数
            tmp2 = nums2[cur2 - 1];
            if (now == flag1) {
                val1 = tmp2;
            }
            if (now == flag2) {
                val2 = tmp2;
                break;
            }
            now++;
            cur2++;
        }
    }
    ret = (val1 + val2) / 2.0;
    return ret;
}

int main()
{
    int arr1[] = {1, 3};
    int arr2[] = {2};
    int size1 = sizeof(arr1) / sizeof(arr1[0]);
    int size2 = sizeof(arr2) / sizeof(arr2[0]);
    printf("%d %d\n", size1, size2);
    double ret = FindMedianSortedArrays(arr1, size1, arr2, size2);
    printf("%f \n", ret);
    return 0;
}

