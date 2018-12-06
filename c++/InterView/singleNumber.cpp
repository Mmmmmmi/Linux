/*
给定一个非空整数数组，除了某个元素只出现一次以外，其余每个元素均出现两次。找出那个只出现了一次的元素。

说明：

你的算法应该具有线性时间复杂度。 你可以不使用额外空间来实现吗？

示例 1:

输入: [2,2,1]
输出: 1
示例 2:

输入: [4,1,2,1,2]
输出: 4


class Solution {
public:
    int singleNumber(vector<int>& nums) {
        
    }
};
*/

#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ret = nums[0];
        auto e = nums.begin() + 1;
        while (e != nums.end()) {
            ret ^= *e;
            ++e;
        }
        return ret;
    }
};


int main()
{
    Solution s1;
    vector<int>  v1 = {2,2,1};
    cout << s1.singleNumber(v1) <<endl;
    return 0;
}

