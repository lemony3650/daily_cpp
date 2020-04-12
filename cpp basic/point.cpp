#include <iostream>
using namespace std;

#define MAX 1000

struct Person
{
	string m_Name; 
	int m_Sex; 
	int m_Age; 
	string m_Phone;
	string m_Addr; 
};
//ͨѶ¼�ṹ��
struct Addressbooks
{
	struct Person personArray[MAX]; //ͨѶ¼�б������ϵ������
	int m_Size;                     //ͨѶ¼����Ա����
};

void addPerson(Addressbooks *abs);
void showPerson(Addressbooks * abs);
void deletePerson(Addressbooks * abs);
void findPerson(Addressbooks * abs);
void modifyPerson(Addressbooks * abs);
void cleanPerson(Addressbooks * abs);
void showMenu();


int main()
{
    int val = 0;
    struct Addressbooks abs;
    abs.m_Size = 0; 

    showMenu();

    while(1)
    {
        cin >> val;

        switch (val) {
            case 1:
                addPerson(&abs);
                break;
             case 2:
                showPerson(&abs);
                break;
             case 3:
                deletePerson(&abs);
                break;
             case 4:
                findPerson(&abs);
                break;
             case 5:
                modifyPerson(&abs);
                break;
             case 6:
                cleanPerson(&abs);
                break;
            case 7:
                cout << "welcome again..." << endl;
                return 0;
                break;
        }    
    }


    return 0;
}


//1�������ϵ����Ϣ
void addPerson(Addressbooks *abs)
{
	if (abs->m_Size == MAX) {
		cout << "ͨѶ¼�������޷����" << endl;
		return;
	}else {
		string name;
		cout << "������������" << endl;
		cin >> name;
		abs->personArray[abs->m_Size].m_Name = name;

		cout << "�������Ա�" << endl;
		cout << "1 -- ��" << endl;
		cout << "2 -- Ů" << endl;
		int sex = 0;

		while (true)
		{
			cin >> sex;
			if (sex == 1 || sex == 2)
			{
				abs->personArray[abs->m_Size].m_Sex = sex;
				break;
			}
			cout << "������������������";
		}

		//����
		cout << "���������䣺" << endl;
		int age = 0;
		cin >> age;
		abs->personArray[abs->m_Size].m_Age = age;

		//��ϵ�绰
		cout << "��������ϵ�绰��" << endl;
		string phone = "";
		cin >> phone;
		abs->personArray[abs->m_Size].m_Phone = phone;

		//��ͥסַ
		cout << "�������ͥסַ��" << endl;
		string address;
		cin >> address;
		abs->personArray[abs->m_Size].m_Addr = address;

		//����ͨѶ¼����
		abs->m_Size++;

		cout << "��ӳɹ�" << endl;
		system("pause");
		system("cls");
	}
}

//2����ʾ������ϵ����Ϣ
void showPerson(Addressbooks * abs)
{
	if (abs->m_Size == 0) {
		cout << "��ǰ��¼Ϊ��" << endl;
	}else {
		for (int i = 0; i < abs->m_Size; i++) {
			cout << "������" << abs->personArray[i].m_Name << "\t";
			cout << "�Ա�" << (abs->personArray[i].m_Sex == 1 ? "��" : "Ů") << "\t";
			cout << "���䣺" << abs->personArray[i].m_Age << "\t";
			cout << "�绰��" << abs->personArray[i].m_Phone << "\t";
			cout << "סַ��" << abs->personArray[i].m_Addr << endl;
		}
	}
	
	system("pause");
	system("cls");
}

//3��ɾ��ָ����ϵ����Ϣ
//�ж��Ƿ���ڲ�ѯ����Ա�����ڷ���������������λ�ã������ڷ���-1
int isExist(Addressbooks * abs, string name)
{
	for (int i = 0; i < abs->m_Size; i++){
		if (abs->personArray[i].m_Name == name)
			return i;
	}
	return -1;
}
void deletePerson(Addressbooks * abs)
{
	cout << "��������Ҫɾ������ϵ��" << endl;
	string name;
	cin >> name;

	int ret = isExist(abs, name);
	if (ret != -1) {
		for (int i = ret; i < abs->m_Size; i++)
		{
			abs->personArray[i] = abs->personArray[i + 1];
		}
         abs->m_Size--;
		cout << "ɾ���ɹ�" << endl;
	}else
		cout << "���޴���" << endl;


	system("pause");
	system("cls");
}

//4������ָ����ϵ����Ϣ
void findPerson(Addressbooks * abs)
{
	cout << "��������Ҫ���ҵ���ϵ��" << endl;
	string name;
	cin >> name;

	int ret = isExist(abs, name);
	if (ret != -1) {
		cout << "������" << abs->personArray[ret].m_Name << "\t";
		cout << "�Ա�" << abs->personArray[ret].m_Sex << "\t";
		cout << "���䣺" << abs->personArray[ret].m_Age << "\t";
		cout << "�绰��" << abs->personArray[ret].m_Phone << "\t";
		cout << "סַ��" << abs->personArray[ret].m_Addr << endl;
	}else
		cout << "���޴���" << endl;

	system("pause");
	system("cls");

}

//5���޸�ָ����ϵ����Ϣ
void modifyPerson(Addressbooks * abs)
{
	cout << "��������Ҫ�޸ĵ���ϵ��" << endl;
	string name;
	cin >> name;

	int ret = isExist(abs, name);
	if (ret != -1)
	{
		//����
		string name;
		cout << "������������" << endl;
		cin >> name;
		abs->personArray[ret].m_Name = name;

		cout << "�������Ա�" << endl;
		cout << "1 -- ��" << endl;
		cout << "2 -- Ů" << endl;

		//�Ա�
		int sex = 0;
		while (true)
		{
			cin >> sex;
			if (sex == 1 || sex == 2)
			{
				abs->personArray[ret].m_Sex = sex;
				break;
			}
			cout << "������������������";
		}

		//����
		cout << "���������䣺" << endl;
		int age = 0;
		cin >> age;
		abs->personArray[ret].m_Age = age;

		//��ϵ�绰
		cout << "��������ϵ�绰��" << endl;
		string phone = "";
		cin >> phone;
		abs->personArray[ret].m_Phone = phone;

		//��ͥסַ
		cout << "�������ͥסַ��" << endl;
		string address;
		cin >> address;
		abs->personArray[ret].m_Addr = address;

		cout << "�޸ĳɹ�" << endl;
	}else
		cout << "���޴���" << endl;


	system("pause");
	system("cls");

}

//6�����������ϵ��
void cleanPerson(Addressbooks * abs)
{
	abs->m_Size = 0;
	cout << "ͨѶ¼�����" << endl;
	system("pause");
	system("cls");
}


void showMenu()
{

    cout << "------------------------" << endl;

    cout << "1.xxxxADDxxxx" << endl;
    cout << "2.xxxxSHOWxxx" << endl;
    cout << "3.xxxxDELxxxx" << endl;
    cout << "4.xxxxFINDxxx" << endl;
    cout << "5.xxxxMODxxxx" << endl;
    cout << "6.xxxxCLSxxxx" << endl;
    cout << "7.xxxxEXITxxxx" << endl;

    cout << "------------------------" << endl;
}
