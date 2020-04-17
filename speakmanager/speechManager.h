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

	//显示比赛结果
	void showScore();

	//抽签
	void speechDraw();
    //开始比赛 - 比赛流程控制
	void startSpeech();
	//比赛
	void speechContest();

	//保存记录
	void saveRecord();

	//读取记录
	void loadRecord();

	//显示往届得分
	void showRecord();

	//清空记录
	void clearRecord();
    
    // ~SpeechManager();

    map<int,Speaker> m_Speaker;

    vector<int> v1;             //12
    vector<int> v2;             //6
    vector<int> vVictory;       //3

    int m_Index;
    bool fileIsEmpty;

    // 往届记录
    map<int, vector<string>> m_Record;
};




#endif