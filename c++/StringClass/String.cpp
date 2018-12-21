#include <string.h>
#include "String.h"

//构造函数
String::String(const char *str)
{
    //如果没有传参的话，那么str = ""
    if (str == nullptr) {
        _str = new char[1];
        *_str = '\0';
    }
    _str = new char[strlen(str) + 1];
    strcpy(_str, str);
}

//拷贝构造函数





//析够函数
String::~String()
{
    if (_str) {
        //如果_str != NULL;
        delete[] _str;
        _str = nullptr;

    }
}


