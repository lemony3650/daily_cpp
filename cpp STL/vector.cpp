#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*******************************************************
 * vector容器 using std::vector
 * 类模板,通过类模板进行实例化，因此需要包含类型vector<type>
 * 引用类型不能是vector，引用不是一个对象
 * vector<type> value
 * vector<vector<string> > value
******************************************************/

/******************************************************
 * vector 最常用的就是定义一个空的vector,然后一直添加元素
 * 初始化的是一个列表时，只能使用{}
 * ()初始化只能采用数量、默认值的直接初始化方式
 * vector<T> v;
 * vector(n,elem);
 * vector(v.begin(),v.end());
 * vector(const vector &vec);
*******************************************************/
void func_demo1()
{
    vector<int> v1;

    vector<int> v2(10);
    vector<int> v3(10,2);
    vector<int> v6{10};
    vector<int> v7{10,2};
    
    vector<int> v8(v7);

    vector<int> v4{1,2,3,4,5};
    vector<int> v5 = {1,2,3,4,5};

    vector<int>(v5.begin(),v5.end());

    vector<int> v10;
    v10.assign(v5.begin(),v5.end());

    vector<int> v11;
	v11.assign(10, 100);
}
/********************************************
 * 类型不匹配时的初始化需要考虑构造初始化
 * 编译器会自动识别v1{10}中的10代表数量
*********************************************/
void func_demo2()
{
    vector<string> v1(10);
    vector<string> v1{10};
    vector<string> v1{10,"hi"};
}

/***********************************************
 * 不能通过 for+i 的方式对vector进行初始化操作
 * vector只支持已经存在的元素值下标访问
 * push_back()添加元素，在队尾添加尾端元素
************************************************/
void func_demo3()
{
    string word;
    vector<string> text;
    while(cin >> word)
        text.push_back(word);
}
/**************************************
 * 统计分数段的占比情况
 * vector 下标可用于访问已经存在的元素
**************************************/
void func_demo4()
{
    vector<unsigned> scores(11,0);
    unsigned grade;
    while(cin >> grade) {
        if (grade <= 100)
            ++scores[grade/10];
    }
}

/*******************************************
 * 遍历容器vector的方式
 * 1.vector<int>::iterator it_b,it_e
 * 2.for(vector<int>::iterator it = v.begin())
 * 3.for_each(v.begin(),v.end(),function)
*******************************************/  
void MyPrint(int val)
{
    cout << val <<endl;
}
void test01()
{
    vector<int> v1;

    v1.push_back(10);
    v1.push_back(10);
    v1.push_back(10);
    v1.push_back(40);

    // first way
    vector<int>::iterator it_b = v1.begin();
    vector<int>::iterator it_e = v1.end();

    while(it_b != it_e)
        cout << *it_b << endl;
        it_b++;

    // second way
    for(vector<int>::iterator it=v1.begin();it!=v1.end();it++) {
        cout << *it << endl;
    }

    // third way
    for_each(v1.begin(),v1.end(),MyPrint);

}

/***************************************
 * 存放指针类型的自定义类型容器
 * it指针解引用之后的*it代表前面的数据类型
****************************************/
class Person {
    public:
        Person(string name,int age):mName(name),mAge(age){};

        string mName;
        int mAge;    
};
void test02()
{
    vector<Person*> v;

    Person p1("aaa", 10);
    Person p2("bbb", 20);
	Person p3("ccc", 30);

    v.push_back(&p1);
    v.push_back(&p2);
    v.push_back(&p3);

    for(vector<Person*>::iterator it = v.begin;it != v.end();it++) {
        // cout << (**it).mName << endl;
        Person *p = *it;
        cout << p->mName << endl;
    }
}

/*********************************
 * vector类型的vector容器遍历过程
*********************************/ 
void test03()
{
    vector<vector<int> > v;

    vector<int> v1;
	vector<int> v2;
	vector<int> v3;
	vector<int> v4;

	for (int i = 0; i < 4; i++) {
		v1.push_back(i + 1);
		v2.push_back(i + 2);
		v3.push_back(i + 3);
		v4.push_back(i + 4);
	}
	//将容器元素插入到vector v中
	v.push_back(v1);
	v.push_back(v2);
	v.push_back(v3);
	v.push_back(v4);

    for(vector<vector<int> >::iterator it = v.begin();it != v.end();it++)
        for(vector<int>::iterator vit = (*it).begin();vit != (*it).end;vit++)
            cout << *vit << endl;
}

/*************************************
 * vector capation v.capacity()
 * vector size     v.size()
 * vector empty    v.empty()
 * vector resize(int num)
 * vector resize(int num , elem)
 * vector reserve(int len)
 * vector swap(vec);
**************************************/
void test04()
{
 	vector<int> v;
	for (int i = 0; i < 100000; i++) {
		v.push_back(i);
	}

	cout << "v的容量为：" << v.capacity() << endl;
	cout << "v的大小为：" << v.size() << endl;

	v.resize(3);
    //收缩内存
	vector<int>(v).swap(v); //匿名对象

	cout << "v的容量为：" << v.capacity() << endl;
	cout << "v的大小为：" << v.size() << endl;
}

/*****************************************************
 * push_back(elem);
 * pop_back();
 * insert(const_iterator pos,elem);
 * insert(const_iterator pos,int num , elem);
 * erase(const_iterator pos);
 * erase(const_iterator start, const_iterator end);
 * clean();
******************************************************/

/****************************************
 * front()
 * back()
 * at(int idx)
 * operator[]
****************************************/