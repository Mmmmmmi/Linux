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
#include <string.h>
#include <iostream>
using namespace std;

class Solution {
public:
    string multiply(string num1, string num2) {
        string ret;
        size_t little = 0; 
        size_t big = 0;
        char temp1 = 0;
        char temp2 = 0;
        int carryflag = 0;
        int ibit = 0;
        int jbit = 0;
        //如果有空的 直接返回空字符串
        if (num1.empty() || num2.empty()) {
            ret = "";
            return ret;
        }   
        //如果有一个为0  直接返回0  
        if (num1[0] == '0' || num2[0] == '0') {
            ret = "0";
            return ret;
        }    
        little = num1.size();
        big = num2.size();
        if (num1.size() < num2.size()) {
            little = num1.size();
            big = num2.size();
        }
        //先给字符串中全部放上'0' 
        ret.resize((num1.size() + num2.size()), '0');
        //little 是小的数字         big 是大的数字
        for (int i = little - 1; i >= 0; i--) {
            temp1 = little == num1.size() ? num1[i] - '0' : num2[i] - '0';
            jbit = ibit; 
            for (int j = big - 1; j >= 0; j--) {
                temp2 = little == num1.size() ? num2[j] - '0' : num1[j] - '0';
                int mul = temp1 * temp2;
                int add = (ret[num1.size() + num2.size() - 1 - jbit] - '0');
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
                ret[num1.size() + num2.size() - 1 - jbit] = add + '0'; 
                jbit++;
                if (carryflag != 0) {
                    ret[num1.size() + num2.size() - 1 - jbit] += carryflag;
                }
            }
            ibit++;
        }
        if (ret[0] == '0') {
            ret.erase(0, 1);
        }
        return ret;
    }
};



int main()
{
    string num1("1");
    string num2("3");
    string ret;
    Solution a1;
    ret = a1.multiply(num1, num2);
    cout << ret << endl;
    return 0;
}
