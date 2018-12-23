#include <string.h>
#include <assert.h>
#include "String.h"
#include <iostream>
using namespace std;

//构造函数
String::String(const char *str)
{
    //str != NULL   确保指针合法
    assert(str != NULL);
    //如果没有传参的话，那么str = ""
    _str = new char[strlen(str) + 1];
    _size = strlen(str);
    _capacity = _size;
    strcpy(_str, str);
}

//构造函数
String::String(size_t count, char ch)
    :_str(new char[count + 1])
{
    memset(_str, ch, count);
    _str[count] = '\0';
}

//构造函数
String::String(String const& other, size_t pos, size_t count)
    :_str(new char[count + 1])
{
    memcpy(_str, other._str + pos, count);
    _str[count] = '\0';
}

//构造函数
String::String(const char *s, size_t count)
    :_str(new char[count + 1])
{
    assert(s != NULL);
    memcpy(_str, s, count);
    _str[count] = '\0';
}

//构造函数
String::String(Iterator first, Iterator last)
{
    assert(first != NULL);
    assert(last != NULL);
    _str = new char[last - first + 1];    
    _str[last - first] = '\0';
}

#if 0
//拷贝构造函数
String::String(const String& s)
    :_str(new char[strlen(s._str) + 1])
{
    strcpy(_str, s._str);
}

#else

//拷贝构造函数
String::String(const String& s)
    :_str(nullptr)  //这里的nullptr是为了保证交换后，可以正常的析够temp
                    //如果_str没有new，析够中的delete就会出错
{
    String temp(s._str);
    char *c = _str;
    _str = temp._str;
    temp._str = c;
}
#endif

//析够函数
String::~String()
{
    if (_str) {
        //如果_str != NULL;
        delete[] _str;
        _str = nullptr;

    }
}
