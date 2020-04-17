#pragma once
#include <iostream>
using namespace std;
#include "identity.h"

#include <string>

class Teacher: public Identity
{
public:
    Teacher();
    Teacher(int empId, string name,string passwd);

    virtual void operMenu();

    void showAllOrder();

    void validOrder();

    int m_EmpId;
};