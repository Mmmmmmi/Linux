/*
 * 假设你正在爬楼梯。需要 n 阶你才能到达楼顶。
 * 
 * 每次你可以爬 1 或 2 个台阶。你有多少种不同的方法可以爬到楼顶呢？
 * 
 * 注意：给定 n 是一个正整数。
 * 
 * 示例 1：
 * 
 * 输入： 2
 * 输出： 2
 * 解释： 有两种方法可以爬到楼顶。
 * 1.  1 阶 + 1 阶
 * 2.  2 阶
 * 示例 2：
 * 
 * 输入： 3
 * 输出： 3
 * 解释： 有三种方法可以爬到楼顶。
 * 1.  1 阶 + 1 阶 + 1 阶
 * 2.  1 阶 + 2 阶
 * 3.  2 阶 + 1 阶
 * 
 * class Solution {
 * public:
 *     int climbStairs(int n) {
 *         
 *     }
 * };
 * 
 */ 

#include <iostream>
using namespace std;

class Solution {
public:
/*     int climbStairs(int n) {
*         if (n == 1) {
*             return 1;
*         }
*         if (n == 2) {
*             return 2;
*         } 
*         return climbStairs(n - 1) + climbStairs(n - 2);
*     }
*/
    int climbStairs(int n) {
        int ret = 0;
        int a = 0;
        int b = 1;
        for (int i = 0; i < n; i++) {
            ret = a + b;
            a = b;
            b = ret;
        }
        return ret;
    }
};


int main()
{
    int n = 44;
    Solution s;
    int ret = s.climbStairs(n);
    cout << "n == " << n << "    ret == " << ret << endl;
    return 0;
}
