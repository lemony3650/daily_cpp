#include <iostream>
#include <vector>
#include <cstring>
#include <cctype>
using namespace std;

/*************************************************************
 * iterator������
 * ������ָ��ķ�ʽ�Զ�����м�ӷ��ʵĹ���
 * ���ڲ�֧���±�[]��������������б���
 * auto b = v.begin(),e = v.end()
 * b��������v�ĵ�һ��λ�ã�e��������v�����λ�õ���һ�������ڵ�β��
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