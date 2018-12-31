#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> a = {1, 2, 3, 4, 5, 4,  5, 6, 3, 2,  4,  5, 3,23 ,2 ,2 ,2};
    cout << a.size() << endl;
    cout << a.capacity() << endl;
    a.clear();
    a.shrink_to_fit();
    cout << a.size() << endl;
    cout << a.capacity() << endl;
    return 0;
}

