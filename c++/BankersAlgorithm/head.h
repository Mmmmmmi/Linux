#ifndef __HEAD_H__
#define __HEAD_H__


#include <vector>
#include <iostream>
#include <assert.h>
using namespace std;



//进程对象
//
//  每个对象都是一个进程
//  进程里面保存有自己的  max need  allocation request
//
class Process
{
public:
    //
    Process()
    {}

    //vector的大小应该与资源数相同
    void initValue(int resourcesnum)
    {
        _max.resize(resourcesnum);
        _allocation.resize(resourcesnum);
        _need.resize(resourcesnum);
     //   _request.reserve(resourcesnum);
    }

    //输入一开始的各进程的资源情况 // 
    void setValue()
    {
         //max
        cout << "请输入_max：";
        for (auto& e : _max) {
            cin >> e;
        }

        //allocation
        cout << "请输入_allocation：";
        for (auto& e : _allocation) {
            cin >> e;
        }
        
        //need
        for (size_t i = 0; i < _max.size(); ++i) {
            _need[i] = _max[i] - _allocation[i];
        }
    }

    //返回第ｎ个资源的max
    int getNMax(int n) const
    {
        assert(n < _max.size());
        return _max[n];
    }

    //返回第ｎ个资源的allocation
    int getNallocation(int n) const
    {
        assert(n < _allocation.size());
        return _allocation[n];
    }

    //返回第ｎ个资源的allocation
    int getNneed(int n) const
    {
        assert(n < _need.size());
        return _need[n];
    }
    
    //获取状态
    bool getState() const
    {
        return _state;
    }

    //修改状态
    void setState(bool state)
    {
        _state = state;
    }

    //试分配
    void doRequest(vector<int>& request)
    {
        //如果能满足条件，即request进行分配
        //need = need - request
        //allocation = allocation + request
        for (size_t i = 0; i < request.size(); ++i)
        {
            _need[i] -= request[i]; 
            _allocation[i] += request[i];
        }
    }

    //撤销试分配
    void undoRequest(vector<int>& request)
    {
        //如果能满足条件，即request进行分配
        //need = need - request
        //allocation = allocation + request
        for (size_t i = 0; i < request.size(); ++i)
        {
            _need[i] += request[i]; 
            _allocation[i] -= request[i];
        }
    }

    //输出本进程的信息
    void printValue() const
    {
        //max
        for (auto e : _max) {
            printf("%2d ", e);
        }

        //allocation
        cout << "     ";
        for (auto e : _allocation) {
            printf("%2d ", e);
        }

        //need
        cout << "     ";
        for (auto e : _need) {
            printf("%2d  ", e);
        }
        cout << endl;
    }

    ~Process()
    { 
        _max.clear();
        _allocation.clear();
        _need.clear();
        _max.shrink_to_fit();
        _allocation.shrink_to_fit();
        _need.shrink_to_fit();
      //_request.clear();
    }
//private:
    vector<int> _max;           //最大需求
    vector<int> _allocation;    //已分配的    
    vector<int> _need;          //尚需要的
 //   vector<int> _request;       //本次请求的   
    bool _state;                //进程状态
};

//系统中的资源对象
//
//  每个对象是一个资源
//  对象中保存的是资源的sum和available
//
class Resources
{
public:
    
    Resources()
    {}
    
    //vector的大小应该与资源的总数有关
    void initValue(int resourcesnum)
    {
        _sum = resourcesnum;
    }

    //输入资源值
    void setValue()
    {
        cout << "请输入_sum：";
        cin >> _sum;
        cout << "请输入_available：";
        cin >> _available;
    }
        
    //试分配
    void doRequest(int request)
    {
        _available -= request;
    }

    
    //撤销试分配
    void undoRequest(int request)
    {
        _available += request;
    }

    //获取资源总数
    int getSum() const
    {
        return _sum;
    }

    //获取资源总数
    int getAvailable()  const
    {
        return _available;
    }

    //输出资源值
    void printValue() const
    {
        printf("%2d       %2d\n", _sum, _available);
    }

    //析够函数
    ~Resources()
    {
        _sum = 0;
        _available = 0;
    }

//private:
    int _sum;           //资源总数
    int _available;     //可利用的资源数目
};

//解决方案
//
//
//  负责初始化进程和资源
//  输入初始状态的 资源和进程
//  负责程序主体
//
//
class Solution
{
public:
    Solution()
        :_processnum(0)
         ,_resourcesnum(0)
    {}

    ~Solution()
    {
        _processnum = 0;
        _resourcesnum = 0;
        for (auto& e : _process) {
            e.~Process();
        }
        for (auto& e : _resources) {
            e.~Resources();
        }
        _process.clear();
        _process.shrink_to_fit();
        _resources.clear();
        _resources.shrink_to_fit();
        _work.clear();
        _work.shrink_to_fit();
    }


    void test()
    {
        _process[0]._max[0] = 7;
        _process[0]._max[1] = 5;
        _process[0]._max[2] = 3;
        _process[0]._allocation[0] = 0;
        _process[0]._allocation[1] = 1;
        _process[0]._allocation[2] = 0;
        _process[0]._need[0] = 7;
        _process[0]._need[1] = 4;
        _process[0]._need[2] = 3;


        _process[1]._max[0] = 3;
        _process[1]._max[1] = 2;
        _process[1]._max[2] = 2;
        _process[1]._allocation[0] = 2;
        _process[1]._allocation[1] = 0;
        _process[1]._allocation[2] = 0;
        _process[1]._need[0] = 1;
        _process[1]._need[1] = 2;
        _process[1]._need[2] = 2;

        _process[2]._max[0] = 9;
        _process[2]._max[1] = 0;
        _process[2]._max[2] = 2;
        _process[2]._allocation[0] = 3;
        _process[2]._allocation[1] = 0;
        _process[2]._allocation[2] = 2;
        _process[2]._need[0] = 6;
        _process[2]._need[1] = 0;
        _process[2]._need[2] = 0;

        _process[3]._max[0] = 2;
        _process[3]._max[1] = 2;
        _process[3]._max[2] = 2;
        _process[3]._allocation[0] = 2;
        _process[3]._allocation[1] = 1;
        _process[3]._allocation[2] = 1;
        _process[3]._need[0] = 0;
        _process[3]._need[1] = 1;
        _process[3]._need[2] = 1;

        _process[4]._max[0] = 4;
        _process[4]._max[1] = 3;
        _process[4]._max[2] = 3;
        _process[4]._allocation[0] = 0;
        _process[4]._allocation[1] = 0;
        _process[4]._allocation[2] = 2;
        _process[4]._need[0] = 4;
        _process[4]._need[1] = 3;
        _process[4]._need[2] = 1;

        _resources[0]._sum = 10;
        _resources[0]._available = 3;


        _resources[1]._sum = 5;
        _resources[1]._available = 3;


        _resources[2]._sum = 7;
        _resources[2]._available = 2;

    }



    //初始化各变量
    void initialize(int processnum = 0, int resourcesnum = 0)
    {
        //分别是进程数和资源类别数
        _processnum = processnum;
        _resourcesnum = resourcesnum;
        //提前预留空间
        _process.resize(processnum);
        _resources.resize(resourcesnum);
        _work.resize(resourcesnum);
        //初始化进程信息
        for(int i = 0; i < processnum; ++i) {
            //为每一个进程将资源列表大小初始化好
            _process[i].initValue(resourcesnum);
        }
        //初始化资源信息
        for(int i = 0; i < resourcesnum; ++i) {
            //为每一个进程将资源列表大小初始化好
            _resources[i].initValue(resourcesnum);
        }
        
    }
    
    //输入资源的各项值
    void setResources()
    {
        cout << "开始输入资源信息：" << endl;
        for (auto& e : _resources)
            e.setValue();
    }


    //输入进程的各项属性
    void setProcess()
    {
        cout << "开始输入进程信息：" << endl;
        for (auto& e : _process) {
            e.setValue();
        }
    }

    //检测输入的有效性  只在第一次输入的时候检测
    //即  进程的 max = need + allocation
    //    资源的 sum = available + allocation
    bool checkValidity() const
    {

        //检测进程信息合法性
        for (int i = 0; i < _processnum; ++i) {
            for (int j = 0; j < _resourcesnum; ++j) {
                if (_process[i].getNMax(j) < _process[i].getNallocation(j)) {
                    cout << "false for _processValidity" << endl;
                    return false;
                } 
            }
        }

        //检测资源合法性
        for (int j = 0; j < _resourcesnum; ++j) {
            int sum = 0;
            for (int i = 0; i < _processnum; ++i) {
                sum += _process[i].getNallocation(j);
            }
          //  cout << "sum == " << sum <<endl;
          //  cout << "_resources[j].getAvailable() == " << _resources[j].getAvailable() <<endl;
            if (sum + _resources[j].getAvailable() != _resources[j].getSum()) {
                cout << "false for _resourcesValidity" << endl;
                return false;
            }
        }

        return true;
    }

    //输出当前信息
    void printInfo() const
    {
        //输出进程信息
        cout << "process:" << endl;
        printf("max          allocation           need\n");
        for (auto e : _process) {
            e.printValue();
        }
        //输出资源信息
        cout << "resources:" << endl;
        printf("sum    _available\n");
        for (auto e : _resources) {
            e.printValue();
        }

        
       /* printf("work\n");
        for (auto e : _work) {
            cout << e << endl;
        }*/

    }

    //试分配  修改值
    void tryFinishRequest()
    {
        _process[_processid].doRequest(_request);
        for (int i = 0; i < _resourcesnum; ++i) {
           _resources[i].doRequest(_request[i]); 
        }
    }

    //获取所有进程的状态，如果有进程状态为false，那么就为false，如果所有进程都为true，那么就为true
    bool getProcessState() const
    {
        for (auto e : _process) {
            if (e.getState() == false) {
                return false;
            }
        }
        return true;
    }

    //搜索可以完成的进程  找到返回进程号， 找不到返回-1 
    int searchProcess() const
    {
        for (int i = 0; i < _processnum; ++i) {
            if (_process[i].getState() == false) {      // 进程为未完成状态 
                //接下来要判断的是 进程所需的资源小于work中的资源
                size_t flag = 0; 
                for (int j = 0; j < _resourcesnum; ++j) {
                   // cout << "i == " << i << "   j == " << j  << endl;
                   // cout << "_process[i].getNneed(j) == " << _process[i].getNneed(j) << "   _work[j] == " << _work[j] << endl;
                    if (_process[i].getNneed(j) > _work[j]) {
                        break;
                    }else {
                        flag++;
                    }
                }    
               // cout << "flag == " <<flag << endl;
                //走到这里来有两个结果：1.满足条件  2. 有的资源不满足条件 break出
                if (flag == _work.size()) {
                  //  cout << "返回了" << endl;
                    //flag == _work.size()  说明 每个条件都比较过了  并且都满足了
                    return i;
                }
            }
        }
        cout << "false for searchProcess() !" << endl;
        return -1;
    }
    
    void checkFinish()
    {
        for (int i = 0; i < _processnum; ++i) {
            int flag = 0;
            for (int j = 0; j < _resourcesnum; ++j) {
                if (_process[i].getNneed(j) != 0) {
                    break;
                }else {
                    flag++;
                }
            }
            if (flag == _resourcesnum) {
               _process.erase(_process.begin() + i);   
               _processnum -= 1;
               cout << "进程" << i << "完成，从队列中删除" << endl;
            }
        }
    }


    //安全性检测
    bool checkSecurity()
    {
        
        //设置work
        for (int j = 0; j < _resourcesnum; ++j) {
            _work[j] = _resources[j].getAvailable();
        }
        
        //先设置所有进程为false状态
        for (auto& e : _process) {
            e.setState(false);
        }

        //当有进程未完成时，返回false
        while(!getProcessState()) {
            //既然有未完成的进程，就从其中找到一个可以完成的去完成
            int retprocessid = searchProcess(); 
            if (retprocessid == -1) {
                //有进程未完成，但是根据当前的资源情况，无法完成，状态不安全
                cout << "false for checkSecurity() !" << endl;
                return false;
            }
            //找到了一个进程
            //说明这条进程可以执行 将它输出 
            cout << "进程Ｉｄ　＝＝　" << retprocessid << endl;
            //进程的状态为完成
            _process[retprocessid].setState(true);
            //执行完之后work发生变化
            for (int i = 0; i < _resourcesnum; ++i) {
                _work[i] += _process[retprocessid].getNallocation(i);
            }
        }
        //能走出来 说明都完成了
        return true;
    }


    //试分配资源
    //先输入进程号　    如果没有错误　　　再输入ｒｅｑｕｅｓ
    //
    void allocationResources()
    {
        //选择进程
        while(1) {
            cout << "请输入进程序号：";
            cin >> _processid;
            if (_processid >= 0 && _processid < _processnum) {
                break;
            }
        }

        //request 的大小和_resourcesnum
        _request.resize(_resourcesnum);

        cout << "请输入请求向量：";
        //接收到了request的信息
        for (auto& e: _request) {
           cin >> e;  
        }
        
        //判断
        // 4 中情况
        
        // 输入的 大于 need    输入非法
        for (int j = 0; j < _resourcesnum; ++j) {
            if (_request[j] > _process[_processid].getNneed(j)) {
                cout << "输入有误，request > need" << endl;
                //从这里直接跳出，重新进行下一次
                return;
            }             
        }

        // 输入的 大于 available  不能满足
        for (int j = 0; j < _resourcesnum; ++j) {
            if (_request[j] > _resources[j].getAvailable()) {
                cout << "资源不足，无法分配，request > available" << endl;
                //从这里直接跳出，重新进行下一次
                return;
            }             
        }

        //走到这里，就能进行试分配了
        //输入的正常  不能通过安全性检测算法  不安全
        //输入的正常  能通过安全性检测算法  安全
        
        //试分配
        //tryFinishRequest(); 
        _process[_processid].doRequest(_request);
        for (int i = 0; i < _resourcesnum; ++i) {
            _resources[i].doRequest(_request[i]); 
        }

   /*     //设置work----------------放到安全性检测算法内部了
        for (int j = 0; j < _resourcesnum; ++j) {
            _work[j] = _resources[j].getAvailable();
        }*/
        
        //work中 是执行过试分配的available的值
        //安全性检测
        if (!checkSecurity()) {
            _process[_processid].undoRequest(_request);
            for (int i = 0; i < _resourcesnum; ++i) {
                _resources[i].undoRequest(_request[i]); 
            }
            cout << "分配后状态不安全，不执行分配！" << endl;
        }else {
            cout << "分配后状态安全，已执行分配！" << endl;
            checkFinish();
        }
    }

private:
    int _processnum;                    //进程数
    vector<Process> _process;           //用来存储进程
    int _resourcesnum;                  //资源类型数
    vector<Resources> _resources;       //用来存储资源
    int _processid;                      //发出request的进程id
    vector<int> _work;                  //工作状态资源数
    vector<int> _request;               //会接收到的请求
};


#endif
