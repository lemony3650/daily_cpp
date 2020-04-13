#include <iostream>
using namespace std;

class building {
    // ȫ�ֺ�������Ԫ
    friend void func_demo1(building &tmp);
    // ��Ԫ��
    friend class fbuild;

    public:
        building(int a,int b):val_public(a),val_private(b){}
        int val_public;

    private:
        int val_private;
};


// ȫ�ֺ�������Ԫ
void func_demo1(building &tmp)
{
    cout << tmp.val_public << endl;
    cout << tmp.val_private << endl;
}


// ��Ԫ��,�ڲ�Ƕ��һ����building����Ҫ�������ڲ�˽�г�Ա
class fbuild {
    public:
        fbuild();
        void show();

    private:
        building *p;
};

fbuild::fbuild()
{
    // ���캯����ʼ��˽�б���ָ��p
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