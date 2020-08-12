#include <iostream>
#include <string>
#include <sstream>
#include <vector>

#include <assert.h>
#include <time.h>
#include <stdlib.h>

using namespace std;

/**********************************************
 * 一行输入 1 2 3 4 ...
 * 个数不定时需要手动判断
**********************************************/
void test01()
{
    char ch;
    int temp;
    vector<int> list;

    while ((ch = cin.get()) != '\n')
    {
        cin.putback(ch);            // 将数据再重新放回缓冲区中
        cin >> temp;
        list.push_back(temp);
    }
}

void test02()
{
    int n;
    string str;
    vector<int> list;

    getline(cin, str);
    stringstream ss(str);
    while(ss >> n) 
        list.push_back(n);
    
}


void test03()
{
    int tmp = 0;
    vector<vector<int>> vec;
    vector<int> v;

    while(cin >> tmp) {
        v.push_back(tmp);

        if(cin.get() == '\n') {
            vec.push_back(v);
            v.clear();
        }

        if(cin.peek() == '\n') {
            vec.push_back(v);
            break;
        }
    }   
}

/********************************************************
 * getline(cin, str) + stringstream ss(str)
3
1 2 3
2 3 4
3 4 5
********************************************************/
void test04()
{
	int n;  //目标个数
    vector<vector<int> > data;
	while (cin >> n)
	{
        //这里有坑，注意读取的第一行字符串会是缓冲区中存留下来的换行符
		for (int i = 0; i <= n; i++)
		{
			int temp;
			string str;
			vector<int> list;

			getline(cin, str);
			stringstream ss(str);
			while (ss >> temp)
				list.push_back(temp);

			data.push_back(list);
		}
        break;
    }

    for (auto v : data)
    {
        for (auto num : v)
            cout << num << " ";

        cout << '\n';
    }
}

// 随机数组生成
int* generateRandomArray(int n, int rangeL, int rangeR)
{
    assert(rangeL <= rangeR);

    int *arr = new int[n];
    srand(time(NULL));

    for (int i = 0; i < n; i++) {
        arr[i] = rand() % (rangeR - rangeL + 1) + rangeL;
    }

    return arr;
}

void test05()
{
    int *p = generateRandomArray(8,1,19);

    for (int i = 0; i < 8; i++)
        cout << p[i] << " ";

    cout << endl;
}

int main()
{
    test05();

    system("pause");
    return 0;
}