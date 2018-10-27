#include <stdio.h>
#include <stdc-predef.h>
int Reverse(int x)
{
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


int main()
{
    int i = -123;
    i = Reverse(i);
    printf("Reverse i = %d\n", i);
    return 0;
}

