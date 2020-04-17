#include <iostream>
using namespace std;

#include "speechManager.h"
#include "speaker.h"

/******************************************************************************
- ѧУ����һ���ݽ�����������12���˲μӡ����������֣���һ��Ϊ��̭�����ڶ���Ϊ������
- ������ʽ�����������ÿ��6���ˣ�ѡ��ÿ��Ҫ������飬���б���
- ÿ��ѡ�ֶ��ж�Ӧ�ı�ţ��� 10001 ~ 10012 
- ��һ�ַ�Ϊ����С�飬ÿ��6���ˡ� ���尴��ѡ�ֱ�Ž��г�ǩ��˳���ݽ���
- ��С���ݽ������̭����������������ѡ�֣�ǰ����������������һ�ֵı�����
- �ڶ���Ϊ������ǰ����ʤ��
- ÿ�ֱ���������Ҫ��ʾ����ѡ�ֵ���Ϣ
*******************************************************************************/
int main()
{
	SpeechManager sm;
	int choice = 0; //�����洢�û���ѡ��

	while (true)
	{
		sm.show_Menu();

		cout << "����������ѡ�� " << endl;
		cin >> choice; // �����û���ѡ��

		switch (choice)
		{
		case 1:  //��ʼ����
            sm.startSpeech();
			break;
		case 2:  //�鿴��¼
            sm.showRecord();
			break;
		case 3:  //��ռ�¼
            sm.clearRecord();
			break;
		case 0:  //�˳�ϵͳ
            sm.exitSystem();
			break;
		default:
			system("cls"); //����
			break;
		}
	}

	system("pause");
	return 0;    
}