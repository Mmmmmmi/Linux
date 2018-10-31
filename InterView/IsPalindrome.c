#include <stdio.h>
#include <stdbool.h>
#if 0
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

#else

int reverse(int x) {
    long long ret = 0;
    long long max1 = __INT_MAX__;
    long long max2 = -__INT_MAX__  - 1;
    while(x != 0) {
        ret *= 10;
        ret += (x % 10);
        if (ret > max1 || ret < max2) {
            return 0;
        }
        x /= 10;
    }
    return ret;
}

bool IsPalindrome(int x) {
    int tmp = 0;
    if (x == 0) {
        return true;
    }
    if (x < 0) {
        return false;
    }
    tmp = reverse(x);
    if (tmp == x) {
        return true;
    }
    return false;
}


#endif




int main()
{
    int i = 12621;
    printf("%d \n", IsPalindrome(i));
    return 0;
}

