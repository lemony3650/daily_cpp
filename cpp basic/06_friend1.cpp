#include <iostream>
using namespace std;

class building {
    // 全局函数做友元
    friend void func_demo1(building &tmp);
    // 友元类
    friend class fbuild;

    public:
        building(int a,int b):val_public(a),val_private(b){}
        int val_public;

    private:
        int val_private;
};


// 全局函数做友元
void func_demo1(building &tmp)
{
    cout << tmp.val_public << endl;
    cout << tmp.val_private << endl;
}


// 友元类,内部嵌套一个类building，想要访问其内部私有成员
class fbuild {
    public:
        fbuild();
        void show();

    private:
        building *p;
};

fbuild::fbuild()
{
    // 构造函数初始化私有变量指针p
    p = new building(3,4);
}

void fbuild::show()
{
    cout << p->val_public << endl;
    cout << p->val_private << endl;
}

int main()
{
    building val1(1,2);
    func_demo1(val1);

    fbuild val2;
    val2.show();

    return 0;
}