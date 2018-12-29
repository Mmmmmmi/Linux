#ifndef __HEAD_H__
#define __HEAD_H__


#include <vector>
#include <istream>
using namespace std;
//进程对象
class press
{
public:
    press() {}
    ~press() {}
private:
    vector<vector<int>> _max;           //最大需求
    vector<vector<int>> _allocation;    //已分配的    
    vector<vector<int>> _need;          //尚需要的
    vector<vector<int>> _request;       //本次请求的   
};

//系统中的资源对象
class resources
{
public:
    resources() {}
    ~resources() {}
private:
    vector<vector<int>> _available;     //可利用的资源数目
};

#endif
