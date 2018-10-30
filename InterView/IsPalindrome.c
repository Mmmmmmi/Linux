#include <stdio.h>
#include <stdbool.h>
bool IsPalindrome(int x) {
    int count = 0;
    int tmp = 0;
    int newtmp = 0;
    int newcount = 0;
    if (x == 0) {
        return true;
    }
    if (x < 0) {
        return false;
    }
    tmp = x;
    while(tmp) {
        tmp /= 10;
        count++;      //位数
    }
    newcount = count / 2;
  //  printf("count = %d newcount = %d\n", count, newcount);
    while(newcount) {
        newtmp = (newtmp * 10 +  x % 10);
        x /= 10;
        newcount--;
    }
    if (count % 2 != 0) {
        x /= 10;
    }
    if (newtmp == x) {
        return true;
    }
    return false;
}



int main()
{
    int i = 12621;
    printf("%d \n", IsPalindrome(i));
    return 0;
}

