#include <stdio.h>

int MaxArea(int *height, int heightSize) 
{
    int a = 0;
    int b = 0;
    int maxarea = 0;
    int area = 0;
    if (height == NULL || heightSize == 0) {
        return 0;
    }
#if 0    
    for (int i = 0; i < heightSize; i++) {
        for (int j = i + 1; j < heightSize; j++) {
            a = height[i] > height[j] ? height[j] : height[i];         //高为两个边中小的
            b =  j - i;
            area = a * b;
            maxarea = maxarea > area ? maxarea : area;
        }
    }
    return maxarea;
#else
    int left = 0;
    int right = heightSize - 1;
    maxarea = 0;
    while(left < right) {
        
        a = height[left] > height[right] ? height[right] : height[left];
        b = right - left;
        
        area = a * b;

        maxarea = maxarea > area ? maxarea : area;
        
        if (height[left] <= height[right]) {
            left++;
        }
        else {
            right--;
        }

    }
    
    return maxarea;


#endif


}


int main()
{
    int height[] = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    int heightSize = sizeof(height) / sizeof(height[0]);
    printf("MaxArea = %d\n", MaxArea(height, heightSize));
    return 0;
}

