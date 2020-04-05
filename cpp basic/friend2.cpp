#include <iostream>
using namespace std;

class building;

class fbuild {
    public:
        fbuild();
        void show();
    private:
        building *p;
};
class building {
    // 成员函数友元
    friend void fbuild::show();

    public:
        building(int a,int b):val_public(a),val_private(b){}

        int val_public;
    private:
        int val_private;
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
    fbuild val2;
    val2.show();

    return 0;
}