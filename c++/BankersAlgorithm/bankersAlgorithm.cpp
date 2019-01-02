
#include "head.h"
#include <iostream>
using namespace std;


/*
 *      初始化
 *      初始化进程个数  进程各项属性 资源类型数   资源初始个数
 *      判断状态是否安全   输完之后就判断一次
 *      进入循环    选择功能  ：
 *      while(1) {
 *          1. 分配   2. 查看当前资源数    3. 查看当前进程需求情况    4.退出
 *          1. 分配：
 *              a. 输入合法性判断
 *              b. 是否满足判断
 *              c. 满足情况下 试分配  判断状态是否安全
 *          2. 输出当前资源数
 *          3. 输出当前进程需求的情况
 *          4. 退出
 *      }
 * 
 */


void test()
{
    int a = 0;
    int processnum;
    int resourcesnum;
    Solution s;
    //输入进程数
    while(1) {
        cout << "请输入进程数：";
        cin >> processnum;
        cout << "请输入资源类型数 ：";
        cin >> resourcesnum;
        s.initialize(processnum, resourcesnum);
        s.setProcess();
        s.setResources();
      //  s.test();
        cout << "数据合法性检测中～～～" << endl;
        if (s.checkValidity()) {     //确保输入数据的正确
            cout << "数据合法!" << endl;    //下面要进行安全性检测　所以不能ｂｒｅａｋ
        }else {
            cout << "数据不合法，请重新输入!" << endl;
            continue;
        }
        cout << "当前状态安全性检测中～～～" << endl;
        if (s.checkSecurity()) {     //确保状态安全 
            cout << "当前状态安全!" << endl;
            break;
        }else {
            cout << "当前状态不安全，请重新输入!" << endl;
        }
    }
    //银行家算法的循环
    while(1) {
        cout << "1. 请求分配资源   2. 输出进程及资源信息   3. 退出" << endl;
        cout << "请选择功能：";
        cin >> a;
        switch(a) {
        case 1:s.allocationResources();
        case 2:s.printInfo();break;
        case 3:cout << "程序退出成功!"<< endl;return;
        default:cout << "输入有误，请重新输入!" << endl;break;
        }
    }
}

int main()
{
    test();
    return 0;
}
