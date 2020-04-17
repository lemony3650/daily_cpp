#include <iostream>
#include <string>
#include <fstream>

using namespace std;

#define FILENAME "empFile.txt"

class Worker;
/**************************************
 * 公共管理类
 * 1.用户沟通管理界面
 * 
***************************************/
class WorkerManager
{
    public:
        WorkerManager();

        void Show_Menu();               

        void exitSystem();                  // 系统退出
        void Add_Emp();                     // 添加成员
        void save();                        // 文件保存
        int get_EmpNum();                   // 构造计数
        void init_Emp();                    // 初始化数组

        void Show_Emp();
        int IsExist(int id);
        void Del_Emp();

        void Mod_Emp();

        void Find_Emp();                    // 查找职工
        void Sort_Emp();

        void Clean_File();

        ~WorkerManager();
        int m_EmpNum;                       // 系统员工人数
        Worker ** m_EmpArray;               // 员工数组的指针

	    bool m_FileIsEmpty;                 //标志文件是否为空
};

/*****************************
 * 职工抽象类
 * 其他员工种类继承基类
*****************************/
class Worker
{
    public:
        // 虚函数，不设计实现方法
        // 显示个人信息
        virtual void showInfo() = 0;
        // 获取岗位名称
        virtual string getDeptName() = 0;

        int m_Id;
        string m_Name;
        int m_DeptId;
};