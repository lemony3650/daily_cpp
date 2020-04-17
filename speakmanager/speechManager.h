#ifndef SPEECHMANAGER_H
#define SPEECHMANAGER_H

#include <vector>
#include <map>
#include "speaker.h"


class SpeechManager
{
public:
    SpeechManager();

    void show_Menu();
    // 1. exit
    void exitSystem();

    // 2. init_speaker
    void initSpeech();
    // 3. create_speaker
    void createSpeaker();

	//��ʾ�������
	void showScore();

	//��ǩ
	void speechDraw();
    //��ʼ���� - �������̿���
	void startSpeech();
	//����
	void speechContest();

	//�����¼
	void saveRecord();

	//��ȡ��¼
	void loadRecord();

	//��ʾ����÷�
	void showRecord();

	//��ռ�¼
	void clearRecord();
    
    // ~SpeechManager();

    map<int,Speaker> m_Speaker;

    vector<int> v1;             //12
    vector<int> v2;             //6
    vector<int> vVictory;       //3

    int m_Index;
    bool fileIsEmpty;

    // �����¼
    map<int, vector<string>> m_Record;
};




#endif