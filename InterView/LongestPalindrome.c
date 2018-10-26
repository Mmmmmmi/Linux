#include <stdio.h>
#include <string.h>
#include <stdlib.h>
char * LongestPalindrome(char *s)
{
    int i = 0;
    int tmp[1000] = {0};
    int cur = 0;
    int len = 0;
    int now = 0;
    int jmp = 0;
    int left = 0;
    int right = 0;
    int max = 0;
    char *ret = NULL;
    if (s == NULL) {
        return NULL;
    }
    len = strlen(s);
    while(cur < len) {  //总体指针
        now = cur;
        jmp = 0;
        left = 0;
        right = 0;
        while (now < len) {         //往前找与头相等的
            if(now != cur && s[now] == s[cur]) {    //从两头往中间走
                left = cur;
                right = now;
                while (left < right && s[left] == s[right]) {             
                    left++;
                    right--;
                }
                if (left >= right) {         //走到中间
                    tmp[cur] = jmp;
                    if (jmp > tmp[max]) {
                        max = cur;
                    }
                }
            }
            now++;
            jmp++;
        }
        cur++;
    }
    ret = (char *) malloc (sizeof(char) * (tmp[max] + 2));  //大小比小标多1 再多出一个空间 放 \0
    if (ret == NULL) {
        return NULL;
    }
    for (i = 0; i <= tmp[max]; i++) {
        ret[i] = s[max + i];
    }
    return ret;
}


int main()
{
    char s[] = "bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb";
    char *ret = LongestPalindrome(s);
    printf("%s\n", ret);
    return 0;
}

