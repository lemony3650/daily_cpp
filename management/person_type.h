#include <iostream>
using namespace std;

#include "workerManager.h"


// Ա����
class Employee :public Worker
{
    public:
        Employee(int id, string name, int dId);

        virtual void showInfo();
        virtual string getDeptName();
};

//������
class Manager :public Worker
{
    public:
	    Manager(int id, string name, int dId);

        //��ʾ������Ϣ
        virtual void showInfo();
        //��ȡְ����λ����
        virtual string getDeptName();
};

//�ϰ���
class Boss :public Worker
{
    public:
        Boss(int id, string name, int dId);

        //��ʾ������Ϣ
        virtual void showInfo();
        //��ȡְ����λ����
        virtual string getDeptName();
};
