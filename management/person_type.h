#include <iostream>
using namespace std;

#include "workerManager.h"


// 员工类
class Employee :public Worker
{
    public:
        Employee(int id, string name, int dId);

        virtual void showInfo();
        virtual string getDeptName();
};

//经理类
class Manager :public Worker
{
    public:
	    Manager(int id, string name, int dId);

        //显示个人信息
        virtual void showInfo();
        //获取职工岗位名称
        virtual string getDeptName();
};

//老板类
class Boss :public Worker
{
    public:
        Boss(int id, string name, int dId);

        //显示个人信息
        virtual void showInfo();
        //获取职工岗位名称
        virtual string getDeptName();
};
