#include <iostream>
#include <string>
using namespace std;

template<typename T>
class MyArray
{
public:
    MyArray(int capacity)
    {
        this->m_Capacity = capacity;
        this->m_Size = 0;
        this->pAddress = new T[this->m_Capacity];
    }

    // ��������
    MyArray(const MyArray &arr)
    {
		this->m_Capacity = arr.m_Capacity;
		this->m_Size = arr.m_Size;
		this->pAddress = new T[this->m_Capacity];
		for (int i = 0; i < this->m_Size; i++)
		{
			//���TΪ���󣬶��һ�����ָ�룬������Ҫ���� = ����������Ϊ����ȺŲ��� ���� ���Ǹ�ֵ��
			// ��ͨ���Ϳ���ֱ��= ����ָ��������Ҫ���
			this->pAddress[i] = arr.pAddress[i];
		}
    }

    // ����=������
    MyArray& operator=(const MyArray &arr)
    {
 		if (this->pAddress != NULL) {
			delete[] this->pAddress;
			this->m_Capacity = 0;
			this->m_Size = 0;
		}

		this->m_Capacity = arr.m_Capacity;
		this->m_Size = arr.m_Size;
		this->pAddress = new T[this->m_Capacity];
		for (int i = 0; i < this->m_Size; i++) {
			this->pAddress[i] = arr[i];
		}
		return *this;       
    }

    T& operator[](int index)
    {
        return this->pAddress[index];
    }

    void Push_back(const T& val)
    {
		if (this->m_Capacity == this->m_Size)   return;
		this->pAddress[this->m_Size] = val;
		this->m_Size++;        
    }
    void Pop_back()
    {
 		if (this->m_Size == 0)  return;
		this->m_Size--;       
    }


    int getCapacity(){return this->m_Capacity;}
    int getSize(){return this->m_Size;}

    ~MyArray()
    {
        if (this->pAddress != NULL){
			delete[] this->pAddress;
			this->pAddress = NULL;
			this->m_Capacity = 0;
			this->m_Size = 0;
		}
    }

private:
	T *pAddress;    //ָ��һ���ѿռ䣬����ռ�洢����������
	int m_Capacity; //����
	int m_Size;     //��С
};