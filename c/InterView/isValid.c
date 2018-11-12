//给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串，判断字符串是否有效。

//有效字符串需满足：

//左括号必须用相同类型的右括号闭合。
//左括号必须以正确的顺序闭合。
//注意空字符串可被认为是有效字符串。

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

bool isValid(char* s) {
    int len = strlen(s);
    int i = 0;
    int cur = 0;
    if (s == NULL || len <= 1) {
        if (len == 0) {
            return true;
        }
        return false;
    }
    char *tmp = (char *) malloc (sizeof(char) * len);
    while (cur < len) {
        switch(s[cur]) {
            case '(':
            case '[':
            case '{':
            tmp[i++] = s[cur++];break;
            case ')':
                if (i == 0 || tmp[i - 1] != '(') {
                    free(tmp);
                    return false;
                }
                i--;
                cur++;
                break;
            case ']':
                if (i == 0 || tmp[i - 1] != '[') {
                    free(tmp);
                    return false;
                }
                i--;
                cur++;
                break;
            case '}':
                if (i == 0 || tmp[i - 1] != '{') {
                    free(tmp);
                    return false;
                }
                i--;
                cur++;
                break;
            default:free(tmp);return false;
        }
    }
    free(tmp);
    return i == 0;
}






int main()
{
    char *array = "()[]{}";
    printf("%d\n", isValid(array));
    return 0;
}

