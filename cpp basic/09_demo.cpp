#include <iostream>
#include <string>
using namespace std;

// �����࣬�޾���ʵ����
class CPU
{
    public:
        virtual void calculate() = 0;
};

class GPU
{
    public:
        virtual void display() = 0;
};

class Memory
{
    public:
        virtual void storage() = 0;
};

// ����
class Computer
{
    public:
    Computer(CPU *cpu, GPU *gpu, Memory *mem)
	{
		m_cpu = cpu;
		m_gpu = gpu;
		m_mem = mem;
	}

    void work()
    {
        m_cpu->calculate();
        m_gpu->display();
        m_mem->storage();
    }

    ~Computer()
    {
 		//�ͷ�CPU���
		if (m_cpu != NULL)
		{
			delete m_cpu;
			m_cpu = NULL;
		}

		//�ͷ��Կ����
		if (m_gpu != NULL)
		{
			delete m_gpu;
			m_gpu = NULL;
		}

		//�ͷ��ڴ������
		if (m_mem != NULL)
		{
			delete m_mem;
			m_mem = NULL;
		}       
    }


    private:
        CPU *m_cpu;
        GPU *m_gpu;
        Memory *m_mem;
};

/*****************************************************
 *****************************************************/
class IntelCPU :public CPU
{
public:
    void calculate()
    {
        cout << "Intel��CPU��ʼ������" << endl;
    }
};
class LenovoCPU :public CPU
{
public:
	virtual void calculate()
	{
		cout << "Lenovo��CPU��ʼ�����ˣ�" << endl;
	}
};
class IntelGPU :public GPU
{
public:
	virtual void display()
	{
		cout << "Intel���Կ���ʼ��ʾ�ˣ�" << endl;
	}
};
class LenovoGPU :public GPU
{
public:
	virtual void display()
	{
		cout << "Lenovo���Կ���ʼ��ʾ�ˣ�" << endl;
	}
};

class IntelMemory :public Memory
{
public:
	virtual void storage()
	{
		cout << "Intel���ڴ�����ʼ�洢�ˣ�" << endl;
	}
};
class LenovoMemory :public Memory
{
public:
	virtual void storage()
	{
		cout << "Lenovo���ڴ�����ʼ�洢�ˣ�" << endl;
	}
};

void test()
{
    CPU *intelCpu   = new IntelCPU;
    GPU * intel_Gpu = new IntelGPU;
    Memory * intel_mem = new IntelMemory;

	cout << "��һ̨���Կ�ʼ������" << endl;
	//������һ̨����
	Computer *computer1 = new Computer(intelCpu, intel_Gpu, intel_mem);
	computer1->work();
	delete computer1;
}