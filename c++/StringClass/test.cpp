#include <iostream>
#include <string.h>
#include <stdio.h>
using namespace std;


int main()
{
    const char *test = "";
    cout << (void *)test  << endl;
    printf("%p\n", test);
    return 0;
}

