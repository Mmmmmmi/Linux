/* 给定一组不含重复元素的整数数组 nums，返回该数组所有可能的子集（幂集）。
 * 
 * 说明：解集不能包含重复的子集。
 * 
 * 示例:
 * 
 * 输入: nums = [1,2,3]
 * 输出:
 * [
 *   [3],
 *   [1],
 *   [2],
 *   [1,2,3],
 *   [1,3],
 *   [2,3],
 *   [1,2],
 *   []
 * ]
 * 
 * 
 * class Solution {
 * public:
 *     vector<vector<int>> subsets(vector<int>& nums) {
 * 
 *     }
 * };
 */ 

#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
           vector<vector<int>> vRet;         
           if (nums.size() == 0) {
               //如果nums.size() == 0
               //即数组为空
               return vRet;
           }
           getSubsets(nums, nums.size());
           return vRet;

    }
};



int main()
{

}
