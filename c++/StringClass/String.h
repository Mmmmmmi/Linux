#ifndef __STRING_H__
#define __STRING_H__
class String
{
public:
    String(const char *str = "");
    ~String();

private:
    char *_str;
};

#endif
