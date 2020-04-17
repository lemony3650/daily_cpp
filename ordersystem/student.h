#pragma once
#include<iostream>
using namespace std;
#include "identity.h"
#include "computer.h"

#include <vector>

class Student :public Identity
{
public:
    Student();
    Student(int id, string name, string passwd);

    virtual void operMenu();

    void applyOrder();

    void showMyOrder();

    void showAllOrder();

    void cancelOrder();


    int m_Id;
	//»ú·¿ÈÝÆ÷
	vector<ComputerRoom> vCom;
};
