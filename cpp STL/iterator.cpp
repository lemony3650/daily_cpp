#include <iostream>
#include <vector>
#include <cstring>
#include <cctype>
using namespace std;

/*************************************************************
 * iterator迭代器
 * 类似于指针的方式对对象进行间接访问的过程
 * 对于不支持下标[]运算符的容器进行遍历
 * auto b = v.begin(),e = v.end()
 * b返回容器v的第一个位置，e返回容器v的最后位置的下一个不存在的尾端
***************************************************************/
void func_demo1()
{
    vector<string> s;
    for (auto item = s.begin(); item != s.end() && !isspace(*item); item++)
    {
        *item = toupper(*item);
    }

    auto mid = s.begin() + s.size()/2;
}