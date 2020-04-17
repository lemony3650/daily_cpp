#include <iostream>
#include "person_type.h"

/*****************************************************************
 *���̳���Ҫ����C++��ʵ��һ�����ڶ�̬��ְ������ϵͳ
- ��˾��ְ����Ϊ���ࣺ��ͨԱ���������ϰ壬��ʾ��Ϣʱ��
  ��Ҫ��ʾְ����š�ְ��������ְ����λ���Լ�ְ��
    ��ͨԱ��ְ����ɾ�����������
    ����ְ������ϰ彻�������񣬲��·������Ա��
    �ϰ�ְ�𣺹���˾��������

����ϵͳ����Ҫʵ�ֵĹ������£�
- �˳���������˳���ǰ����ϵͳ
- ����ְ����Ϣ��ʵ���������ְ�����ܣ�����Ϣ¼�뵽�ļ��У�
  ְ����ϢΪ��ְ����š����������ű��
- ��ʾְ����Ϣ����ʾ��˾�ڲ�����ְ������Ϣ
- ɾ����ְְ�������ձ��ɾ��ָ����ְ��
- �޸�ְ����Ϣ�����ձ���޸�ְ��������Ϣ
- ����ְ����Ϣ������ְ���ı�Ż���ְ�����������в�����ص���Ա��Ϣ
- ���ձ�����򣺰���ְ����ţ�������������������û�ָ��
- ��������ĵ�������ļ��м�¼������ְ����Ϣ �����ǰ��Ҫ�ٴ�ȷ�ϣ���ֹ��ɾ��
***********************************************************************/

int main()
{
    WorkerManager vm;
    int choice = 0;

    while(true) 
    {    
        vm.Show_Menu();
        cout << "please input your choice: "  << endl;
        cin >> choice;

        switch (choice) {
            case 0:
                vm.exitSystem();
                break;
            case 1:
                vm.Add_Emp();
                break;
             case 2:
                 vm.Show_Emp();
                break;
             case 3:
                vm.Del_Emp();
                break;
             case 4:
                vm.Mod_Emp();
                break;
             case 5:
                vm.Find_Emp();
                break;
             case 6:
                vm.Sort_Emp();
                break;
            case 7:
                vm.Clean_File();
                break;
            default:
                system("cls");
                break;
        }    
    }

    system("pause");
    return 0;
}



void test()
{
    Worker * worker = NULL;
	worker = new Employee(1, "����", 1);
	worker->showInfo();
	delete worker;
	
	worker = new Manager(2, "����", 2);
	worker->showInfo();
	delete worker;

	worker = new Boss(3, "����", 3);
	worker->showInfo();
	delete worker;
}