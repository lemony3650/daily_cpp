#include <iostream>
using namespace std;

// operator+

/*************************************************
 * ���������
 * �Զ����������͵����������
 * 1.�������Լ�ʵ����Ӳ�����������ʵ��һ��ͨ�õķ���
 * 2.�����Լ�����
**************************************************/
class Person
{
    public:

        // ��Ա��������+
        Person operator+(Person &p)
        {
            Person tmp;
            tmp.m_A = this->m_A + p.m_A;
            tmp.m_B = this->m_B + p.m_B;
            return tmp;
        }
        
        // ��Ա��������++ 
        // ����++i  i++  �����ص��Ǳ�������ǰ��¼һ��tmp
        Person& operator++()
        {
            m_A++;
            m_B++;
            return *this;
        }

        // ��Ա��������=
        Person & operator=(Person &p)
        {
            if(m_C != NULL)
                delete m_C;

            m_C = new int (*p.m_C);

            return *this;
        }   

        //�Ƚ����㷢����==
        bool operator==(Person &p)
        {
            if ( this->m_A == p.m_A && this->m_B == p.m_B )
                return true;
            else 
                return false;
        }

        // �º���()
        void operator()(string name)
        {
            cout << name << endl;
        }

        int m_A;
        int m_B;
        int *m_C;
};

// ȫ�ֺ���ʵ������+�� �����������Ҳ���Է�����������
/*
Person operator+(Person &p1,Person &p2)
{
    Person temp;
    temp.m_A = p1.m_A + p2.m_A;
    temp.m_B = p1.m_B + p2.m_B;

    return temp;
}
*/

int main()
{
    Person p1 = {1,2};
    Person p2 = {3,4};

    // Person p3 = p1.operator+(p2)
    Person p3 = p1 + p2;

    cout << p3.m_A << " " << p3.m_B << endl;

    p1("jerry");     // �º��� ����()

}

/***********************************************
 * ȫ�ֺ��� �������������,�������������
 * ����Զ������͵�<< 
 * ����ֵ���ͱ�֤���Լ������
************************************************/
ostream& operator<<(ostream &cout,Person &p)
{
    cout << p.m_A << " " << p.m_B << endl;
    return cout;
}