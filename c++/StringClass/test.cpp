#include <iostream>
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include <string>
#include "String.h"
using namespace std;

int main()
{
    char var1[] = "123";   //123
    String s1(var1);       //123
    String s2(5, 'a');     //aaaaa
    String s3(s2, 1, 2);   //aa
    String s4(var1, 2);    //12
    String s5(var1, var1 + 2);   //123
    cout << s1 << endl;
    cout << s2 << endl;
    cout << s3 << endl;
    cout << s4 << endl;
    cout << s5 << endl;
    return 0;
}

