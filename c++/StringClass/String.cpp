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
    _size = count;
    _capacity = _size;
    _str[_size] = '\0';
}

//构造函数
String::String(String const& other, size_t pos, size_t count)
    :_str(new char[count + 1])
{
    memcpy(_str, other._str + pos, count);
    _size = count;
    _capacity = _size;
    _str[_size] = '\0';
}

//构造函数
String::String(const char *s, size_t count)
    :_str(new char[count + 1])
{
    assert(s != NULL);
    memcpy(_str, s, count);
    _size = count;
    _capacity = _size;
    _str[_size] = '\0';
}

//构造函数
String::String(const Iterator first, const Iterator last)
{
    assert(first != NULL);
    assert(last != NULL);
    assert(last >= first);
    _size = last - first;
    _capacity = _size;
    _str = new char[_size + 1];    
    memcpy(_str, first, _size);
    _str[_size] = '\0';
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

//赋值运算符重载
String& String::operator=(const String& s)
{
    if (this != &s) {
        String temp(s._str);
        char *c = temp._str;
        temp._str = _str;
        _str = c;
        _size = s._size;
        _capacity = s._capacity;
    }
    return *this;
}

//输入运算符重载
istream& operator>>(istream& _cin, String& s)
{
    _cin >> s._str;
    return _cin;
}

//输出运算符重载
ostream& operator<<(ostream& _cout, String& s)
{
    _cout << s._str;
    return _cout;
}

//begin
String::Iterator String::begin()
{
    return _str;
}

//end
String::Iterator String::end()
{
    return _str + this->_size;
}

//cbegin
String::Iterator String::cbegin() const
{
   return _str;
}

