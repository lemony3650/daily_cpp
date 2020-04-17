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

	void initVector();                      //��ʼ������
	//����ظ� ����:(����id����������) ����ֵ��(true �������ظ���false����û���ظ�)
	bool checkRepeat(int id, int type);

 	//ѧ������
	vector<Student> vStu;
	//��ʦ����
	vector<Teacher> vTea;   

	//��������
	vector<ComputerRoom> vCom;
};
