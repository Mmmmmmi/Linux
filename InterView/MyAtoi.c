#include <stdio.h>
#include <limits.h>
int MyAtoi(char *str)
{
    long long ret = 0;
    int carryflag = 1;
    if (str == NULL || (*str == '\0')) { //空串或空指针
        return 0;
    }
    while(*str == ' ') {  //前面的空白字符跳过
        str++;
    }
    if (*str == '-') {    //正负判断
        carryflag = -1;
        str++;
    }else if (*str == '+') {
        str++;
    }
    while (*str) {        //当str串未走完时
        if (*str < '0' || *str > '9') {       //如果第一个就不是数字  或者后面遇见了非数字字符   都返回0;
            return ret;               //如果第一个就不是数字，本因转换失败返回0 但这里ret 默认为0 也可以返回;
        }   
        ret = ret * 10 + (carryflag * (*str - '0'));            //走到这里，*str 就是数字;
        printf("*str - '0' = %d\n", *str - '0');
        printf("ret = %lld\n", ret);
        if (ret > (INT_MAX)) {               //判断溢出
            return INT_MAX;               //正溢出
        }
        if (ret < (INT_MIN)) {            //负溢出
            return INT_MIN;
        }
        str++;
    }
    return ret;
}
int main()
{
    char input[] = "-42";
    int ret = MyAtoi(input);
    printf("ret = %d\n", ret);
    return 0;
}

