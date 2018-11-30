//编写一个函数，其作用是将输入的字符串反转过来。
//
//示例 1:
//
//输入: "hello"
//输出: "olleh"
//示例 2:
//
//输入: "A man, a plan, a canal: Panama"
//输出: "amanaP :lanac a ,nalp a ,nam A"
//
//char* reverseString(char* s) {
//}
//

#include <stdio.h>
#include <string.h>

void Swap(char *left, char *right)
{
    char temp = *left;
    *left = *right;
    *right = temp;
}

char* reverseString(char* s) {
    char *left = s;
    char *right = s + strlen(s) - 1;
    while(left < right) {
        Swap(left, right);
        ++left;
        --right;
    }
    return s;
}
int main()
{
    char array[] = "A man, a plan, a canal: Panama";
    printf("%s\n", reverseString(array));
    return 0;
}

