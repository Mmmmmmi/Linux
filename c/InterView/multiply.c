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
    int ibit = 0;
    int jbit = 0;
    if (num1len > num2len) {
        little = num2len;
        big = num1len;
    }
    if (num1 == NULL || num2 == NULL) {
        return NULL;
    }    
    //先给字符串中全部放上\0 
    ret = (char *) malloc (sizeof(char) * (num1len + num2len + 1));
    memset(ret, '0', sizeof(char) + (num1len + num2len + 1));
    ret[num1len + num2len] = '\0';
    //little 是小的数字         big 是大的数字

    if (num1len == 1 || num2len == 1) {
        if ((*num1 == '0') || (*num2 == '0')) {
            ret[0] = '0';
            ret[1] = '\0';
            return ret;

        }
    }

    for (int i = little - 1; i >= 0; i--) {
        temp1 = little == num1len ? num1[i] - '0' : num2[i] - '0';
        printf("temp1 == %d ", temp1);
        jbit = ibit; 
        for (int j = big - 1; j >= 0; j--) {
            temp2 = little == num1len ? num2[j] - '0' : num1[j] - '0';
            int mul = temp1 * temp2;
            int add = (ret[num1len + num2len - 1 - jbit] - '0');
            carryflag = 0;
            //如果乘完有进位，保存进位，让乘的结果只剩个位
            if (mul > 9) {
                carryflag += (mul / 10);
                mul %= 10;
            }
            //将乘完的结果加上
            add += mul;
            if (add > 9) {
                carryflag += (add / 10);
                add %= 10;
            }
            ret[num1len + num2len - 1 - jbit] = add + '0'; 
            printf("temp2 == %d ", temp2);
            printf("mul == %d add == %d carryflag == %d \nret[num1len + num2len - 1 - jbit] == %d num1len + num2len - 1 - jbit == %d jbit == %d\n\n", mul, add, carryflag, ret[num1len + num2len - 1 - jbit] - '0', num1len + num2len - 1 - jbit, jbit);
            jbit++;
            if (carryflag != 0) {
                ret[num1len + num2len - 1 - jbit] += carryflag;
            }
        }
        printf("%s", ret);
        ibit++;
        printf("\n");
    }
    if (ret[0] == '0') {
        for (int i = 0; i < strlen(ret); i++) {
            ret[i] = ret[i + 1];
        }
    }
    return ret;
}




int main()
{
    char num1[] = "78494931482444206733490681";
    char num2[] = "7005919951485201943123477373408130621818958609915320";
    //00000
    char *ret = multiply(num1, num2);
    printf("%s\n", ret);
    free(ret);
    return 0;
}
