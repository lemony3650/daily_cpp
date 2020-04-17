#pragma once
#include<iostream>
using namespace std;

#include "identity.h"
#include "student.h"
#include "teacher.h"
#include "computer.h"

#include <fstream>
#include <vector>


class Manager: public Identity
{
public:
    Manager();
    Manager(string name,string passwd);

    virtual void operMenu();

    void addPerson();
    void showPerson();
	void showComputer();
	void cleanFile();

	void initVector();                      //初始化容器
	//检测重复 参数:(传入id，传入类型) 返回值：(true 代表有重复，false代表没有重复)
	bool checkRepeat(int id, int type);

 	//学生容器
	vector<Student> vStu;
	//教师容器
	vector<Teacher> vTea;   

	//机房容器
	vector<ComputerRoom> vCom;
};
