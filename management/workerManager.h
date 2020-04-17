#include <iostream>
#include <string>
#include <fstream>

using namespace std;

#define FILENAME "empFile.txt"

class Worker;
/**************************************
 * ����������
 * 1.�û���ͨ�������
 * 
***************************************/
class WorkerManager
{
    public:
        WorkerManager();

        void Show_Menu();               

        void exitSystem();                  // ϵͳ�˳�
        void Add_Emp();                     // ��ӳ�Ա
        void save();                        // �ļ�����
        int get_EmpNum();                   // �������
        void init_Emp();                    // ��ʼ������

        void Show_Emp();
        int IsExist(int id);
        void Del_Emp();

        void Mod_Emp();

        void Find_Emp();                    // ����ְ��
        void Sort_Emp();

        void Clean_File();

        ~WorkerManager();
        int m_EmpNum;                       // ϵͳԱ������
        Worker ** m_EmpArray;               // Ա�������ָ��

	    bool m_FileIsEmpty;                 //��־�ļ��Ƿ�Ϊ��
};

/*****************************
 * ְ��������
 * ����Ա������̳л���
*****************************/
class Worker
{
    public:
        // �麯���������ʵ�ַ���
        // ��ʾ������Ϣ
        virtual void showInfo() = 0;
        // ��ȡ��λ����
        virtual string getDeptName() = 0;

        int m_Id;
        string m_Name;
        int m_DeptId;
};