/*
给定一个没有重复数字的序列，返回其所有可能的全排列。

示例:

输入: [1,2,3]
输出:
[
  [1,2,3],
  [1,3,2],
  [2,1,3],
  [2,3,1],
  [3,1,2],
  [3,2,1]
]
 
 Return an array of arrays of size *returnSize.
 Note: The returned array must be malloced, assume caller calls free().



class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        
    }
};
*/



#include <vector>
#include <iostream>
using namespace std;
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> vRet;                  
        int index = nums.size();
        if (nums.empty()) {
            return vRet;
        }
        _getRet(vRet, nums, index);
         return vRet;
    }
private:
    void _getRet(vector<vector<int>>& vRet, const vector<int>& nums, int index)
    {
        if (index == 1) {
            vRet.resize(index);
            vRet[0].resize(index);
            vRet[0][0] = nums[0];
            return;
        }
        _getRet(vRet, nums, index - 1);
        size_t n = vRet.size();
        for (size_t i = 0; i < n; ++i) {
            for (int j = 1; j < index; ++j) {
                vRet.push_back(vRet[i]);
                (vRet.end() - 1)->insert((vRet.end() - 1)->begin() + j , nums[index - 1]);
            }
            vRet[i].insert(vRet[i].begin(), nums[index - 1]);
        }
    }
};
int main()
{
    vector<int> v1{1, 2, 3};
    Solution s1;
    vector<vector<int>> ret = s1.permute(v1);
    for (auto& e : ret) {
        for (auto& n : e) 
            cout<< n << " ";
        cout<<endl;
    }
    return 0;
}
