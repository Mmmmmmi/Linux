#include <stdio.h>
double FindMedianSortedArrays(int *nums1, int nums1Size, int* nums2, int nums2Size)
{
    double ret = 0;
    int num = nums1Size + nums2Size;    //总数
    int flag1 = (num + 1) / 2;
    int flag2 = (num + 2) / 2;
    int val1 = 0;
    int val2 = 0;
    int num1 = 0;   //增序列或减
    int num2 = 0;
    int now = 0;
    int cur1 = 0;
    int cur2 = 0;
    int tmp = 0;
    if (nums1Size == 0 || nums2Size == 0) {    //有一个数组为空
        if (nums1Size == 0) {
            val1 = nums2[flag1 - 1];
            val2 = nums2[flag2 - 1];
        }
        else if (nums2Size == 0) {
            val1 = nums1[flag1 - 1];
            val2 = nums1[flag2 - 1];
        }

    } 
    else {      //两个都不为空 
            num1 = nums1[0] <= nums1[nums1Size - 1] ? 1 : 0;
            num2 = nums2[0] <= nums2[nums2Size - 1] ? 1 : 0;
          //  printf("num1 = %d num2 = %d val1 = %d  val2 = %d now = %d\n", num1, num2, val1, val2, now);
            if (num1 == 1) {    //第一个为增数组
                if (num2 == 1) {
                    cur1 = 1;
                    cur2 = 1;
           //         printf("num1 = %d num2 = %d val1 = %d  val2 = %d now = %d\n", num1, num2, val1, val2, now);
                    while (cur1 <= nums1Size && now <= flag2) {
                        now++;
                        tmp = nums1[cur1 - 1]; 
                        if (cur2 <= nums2Size && nums2[cur2 - 1] <= nums1[cur1 - 1]) {
                            tmp = nums2[cur2 - 1];
                            cur2++;
                            cur1--;
                        }
                        cur1++;
                        if (now == flag1) {
                            val1 = tmp;
                        }
                        if (now == flag2) {
                            val2 = tmp;
                        }
                    }
                    printf("num1 = %d num2 = %d val1 = %d  val2 = %d now = %d cur1 = %d cur2 = %d\n", num1, num2, val1, val2, now, cur1, cur2);
                    while (cur2 <= nums2Size && now <= flag2) {
                        now++;
                        tmp = nums2[cur2 - 1];
                        cur2++;
                        printf("num1 = %d num2 = %d val1 = %d  val2 = %d now = %d cur1 = %d cur2 = %d\n", num1, num2, val1, val2, now, cur1, cur2);
                        if (now == flag1) {
                            val1 = tmp;
                        }
                        if (now == flag2) {
                            val2 = tmp;
                        }
                        printf("num1 = %d num2 = %d val1 = %d  val2 = %d now = %d cur1 = %d cur2 = %d\n", num1, num2, val1, val2, now, cur1, cur2);
                    }
                    printf("num1 = %d num2 = %d val1 = %d  val2 = %d now = %d cur1 = %d cur2 = %d\n", num1, num2, val1, val2, now, cur1, cur2);
                }
                else {
                    cur1 = 1;
                    cur2 = nums2Size;
                    while (cur1 <= nums1Size && now <= flag2) {
                        now++;
                        tmp = nums1[cur1 - 1]; 
                        if (cur2 >= 1 && nums2[cur2 - 1] <= nums1[cur1 - 1]) {
                            tmp = nums2[cur2 - 1];
                            cur2--;
                            cur1--;
                        }
                        cur1++;
                        if (now == flag1) {
                            val1 = tmp;
                        }
                        if (now == flag2) {
                            val2 = tmp;
                        }
                    }
                    while (cur2 >= 1  && now <= flag2) {
                        now++;
                        tmp = nums2[cur2 - 1];
                        cur2--;
                        if (now == flag1) {
                            val1 = tmp;
                        }
                        if (now == flag2) {
                            val2 = tmp;
                        }
                    }
                }
               // printf("val1 = %d  val2 = %d now = %d\n", val1, val2, now);
            }
            else if (num1 == 0) {
                if (num2 == 0) {
                    cur1 = 1;
                    cur2 = 1;
                    while (cur1 <= nums1Size && now <= flag2) {
                        now++;
                        tmp = nums1[cur1 - 1]; 
                        if (cur2 <= nums2Size && nums2[cur2 - 1] >= nums1[cur1 - 1]) {
                            tmp = nums2[cur2 - 1];
                            cur2++;
                            cur1--;
                        }
                        cur1++;
                        if (now == flag1) {
                            val1 = tmp;
                        }
                        if (now == flag2) {
                            val2 = tmp;
                        }
                    }
                    while (cur2 <= nums2Size && now <= flag2) {
                        now++;
                        tmp = nums2[cur2 - 1];
                        cur2++;
                        if (now == flag1) {
                            val1 = tmp;
                        }
                        if (now == flag2) {
                            val2 = tmp;
                        }
                    }
                }
                else {
                    cur1 = 1;
                    cur2 = nums2Size;
                    while (cur1 <= nums1Size && now <= flag2) {
                        now++;
                        tmp = nums1[cur1 - 1]; 
                        if (cur2 >= 0 && nums2[cur2 - 1] >= nums1[cur1 - 1]) {
                            tmp = nums2[cur2 - 1];
                            cur2++;
                            cur1--;
                        }
                        cur1++;
                        if (now == flag1) {
                            val1 = tmp;
                        }
                        if (now == flag2) {
                            val2 = tmp;
                        }
                    }
                    while (cur2 >= 0 && now <= flag2) {
                        now++;
                        tmp = nums2[cur2 - 1];
                        cur2--;
                        if (now == flag1) {
                            val1 = tmp;
                        }
                        if (now == flag2) {
                            val2 = tmp;
                        }

                    }
            
                }
            }
    }
    ret = (val1 + val2) / 2.0;
    return ret;
}
int main()
{
    int arr1[] = {1};
    int arr2[] = {2, 3, 4};
    int size1 = sizeof(arr1) / sizeof(arr1[0]);
    int size2 = sizeof(arr2) / sizeof(arr2[0]);
    printf("%d %d\n", size1, size2);
    double ret = FindMedianSortedArrays(arr1, size1, arr2, size2);
    printf("%f \n", ret);
    return 0;
}

