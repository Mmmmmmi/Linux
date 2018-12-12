/*
*   给定一个包含 m x n 个元素的矩阵（m 行, n 列），请按照顺时针螺旋顺序，返回矩阵中的所有元素。
*
*   示例 1:
*
*   输入:
*   [
*       [1, 2, 3 ],
*       [ 4, 5, 6 ],
*       [ 7, 8, 9 ]
*   ]
*   输出: [1,2,3,6,9,8,7,4,5]
*   示例 2:
*
*   输入:
*   [
*       [1, 2, 3, 4],
*       [5, 6, 7, 8],
*       [9,10,11,12]
*   ]
*   输出: [1,2,3,4,8,12,11,10,9,5,6,7]
*
*   class Solution {
*       public:
*           vector<int> spiralOrder(vector<vector<int>>& matrix) {
*           }
*   };
*
*
*/


#include <vector>
#include <iostream>
using namespace std;


class Solution {                                                 
    public:                                                      
        vector<int> spiralOrder(vector<vector<int>>& matrix) {   
            vector<int> vRet;
            if (matrix.empty()) {
                return vRet; 
            }
            int right = matrix[0].size() - 1;
            int down = matrix.size() - 1;
            int left = 0;
            int up = 0;
            while(left <= right && up <= down) {
                int i = 0;
                //向右走
                for (i = left; i <= right; ++i) {
                    vRet.push_back(matrix[up][i]);
                }
                ++up;
                //向下走
                for (i = up; i <= down; ++i) {
                    vRet.push_back(matrix[i][right]);
                }
                --right;
                //向左走
                for (i = right; i >= left; --i) {
                    if (up - 1 != down)      //不输出同一行
                    vRet.push_back(matrix[down][i]);
                }
                --down;
                //向上走
                for (i = down; i >= up; --i) {
                    if (left != right + 1)   //不输出同一行
                    vRet.push_back(matrix[i][left]);
                }
                ++left;
            }
            return vRet;
        }                                                        
};                                                               
int main()
{
    vector<int> a{1, 2, 3, 4};
    vector<int> b{5, 6, 7, 8};
    vector<int> c{9, 10, 11, 12};
    vector<vector<int>> v{a, b, c};
    Solution s;
    vector<int> vRet = s.spiralOrder(v);
    for (auto e : vRet) {
        cout<< e<< " ";
    }
    cout<<endl;
    return 0;
}

