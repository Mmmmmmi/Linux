/*
 *  给定一个正整数 n，生成一个包含 1 到 n2 所有元素，且元素按顺时针顺序螺旋排列的正方形矩阵。
 *
 *    示例:
 *       输入: 3
 *       输出:
 *       [
 *          [ 1, 2, 3 ],
 *          [ 8, 9, 4 ],
 *          [ 7, 6, 5 ]
 *       ]
 *
 *
 *  class Solution {
 *    public:
 *       vector<vector<int>> generateMatrix(int n) {
 *       }
 *   };
 *
 *
 */



#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> vRet;       
        if (n == 0) 
            return vRet;
        
        //先把要放的数组创建好
        for (int i = 0; i < n; ++i) {
            vector<int> temp;   
            temp.resize(n);
            vRet.push_back(temp);
        }

        //给数组中放值
        //
        //
        //四个变量分别表示当前操作的边界
        
        int left = 0;
        int right = n - 1;
        int up = 0;
        int down = n - 1;

        int value = 1;          //表示当前放到了几 

        while(value <= n * n) {

            int i = 0;

            //向右走
            for (i = left; i <= right; ++i) {
                vRet[up][i] = value++;
            }
            ++up;   //最上面放了，上面的边界向下走

            //向下走
            for (i = up; i <= down; ++i) {
                vRet[i][right] = value++;
            }
            --right;        //最右边放了右边边界向左走

            //向左走
            for (i = right; i >= left; --i) {
                if (up - 1!= down)     //防止只有一行的情况下重复走
                    vRet[down][i] = value++;
            }
            --down;

            //向上走
            for (i = down; i >= up; --i) {
                if (left != right + 1)
                    vRet[i][left] = value++;
            }
            ++left;

        }


        return vRet;
    }
};


int main()
{
    int a = 3;
    Solution s;
    vector<vector<int>> vRet = s.generateMatrix(a);
    for (const auto e: vRet) {
        for (const auto q: e) {
            cout<< q << "  ";
        }
        cout<<endl;
    }
    return 0;
}

