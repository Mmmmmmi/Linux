//给定两个以字符串形式表示的非负整数 num1 和 num2，返回 num1 和 num2 的乘积，它们的乘积也表示为字符串形式。
//
//示例 1:
//
//输入: num1 = "2", num2 = "3"
//输出: "6"
//示例 2:
//
//输入: num1 = "123", num2 = "456"
//输出: "56088"
//说明：
//
//num1 和 num2 的长度小于110。
//num1 和 num2 只包含数字 0-9。
//num1 和 num2 均不以零开头，除非是数字 0 本身。
//不能使用任何标准库的大数类型（比如 BigInteger）或直接将输入转换为整数来处理。
//

//char* multiply(char* num1, char* num2) {
//    
//}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


char* multiply(char* num1, char* num2) {
    char *ret = NULL;
    int num1len = strlen(num1);
    int num2len = strlen(num2);
    int little = num1len; 
    int big = num2len;
    char temp1 = 0;
    char temp2 = 0;
    int carryflag = 0;
    int bit = 0;
    if (num1len > num2len) {
        little = num2len;
        big = num1len;
    }
    if (num1 == NULL || num2 == NULL) {
        return NULL;
    }    
    ret = (char *) malloc (sizeof(char) * (num1len + num2len + 1));
    memset(ret, '0', sizeof(char) + (num1len + num2len + 1));
    ret[num1len + num2len] = '\0';
    for (int i = little - 1; i >= 0; i--) {
        temp1 = little == num1len ? num1[i] : num2[i];
        bit = 0;
        for (int j = big - 1; j >= 0; j--) {
            temp2 = little == num1len ? num2[j] : num1[j];
           // 111
           //  23
           int mul = ((temp1 - '0') * (temp2 - '0'));
           int add = (ret[j - bit] - '0') + (mul % 10) + carryflag;
           carryflag = mul / 10;
           if (add > 10) {
                carryflag += add / 10;
                add %= 10;
           }
           ret[j - bit] = add + '0';
        }
    }
    return ret;
}




int main()
{
    char num1[] = "123";
    char num2[] = "126";
    char *ret = multiply(num1, num2);
    printf("%s\n", ret);
    return 0;
}
