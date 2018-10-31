#include <stdio.h>

int MaxArea(int *height, int heightSize) 
{

}


int main()
{
    int height[] = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    int heightSize = sizeof(height) / sizeof(height[0]);
    printf("MaxArea = %d\n", MaxArea(height, heightSize));
    return 0;
}

