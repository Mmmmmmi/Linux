#ifndef __STRING_H__
#define __STRING_H__
#include <iostream>
class String
{
    friend std::istream& operator>>(std::istream& _cin, String& s);
    friend std::ostream& operator<<(std::ostream& _cout, String& s);
public:
    typedef char* Iterator;
public:
    //构造函数  用c字符串或者空指针或者无参构造
    //string::string()
    //string::string(charT const* s)
    String(const char *str = ""); 
    //构造函数  用count个ch字符构造
    //string::string(size_type count, charT ch)
    String(size_t count, char ch);     
    //构造函数 一个对象的pos到count位 
    //string::string(string const& other, size_type pos, size_type count)
    String(String const& other, size_t pos, size_t count);
    //构造函数  用c字符串的前count个
    //string::string(charT const* s, size_type count)
    String(const char *s, size_t count);   
    //构造函数  用一段序列
    //string::string(InputIt first, InputIt last)
    String(Iterator first, Iterator last);
    //构造函数  用参数列表
    //string(std::initializer_list<charT> ilist)
    //构造函数  对象引用的引用
    //string::string(string&& str)
    //拷贝构造函数
    String(const String& s);      
    //析够函数
    ~String();                    
    //赋值运算符重载
    String& operator=(const String& s);

private:
    char *_str;
    //capacity 比真实的小1,因为要用一个来表示'\0'
    size_t _capacity;
    //size不包括那个隐藏的'\0'
    size_t _size;
};

#endif
