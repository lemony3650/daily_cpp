#include <iostream>
#include <string>
using namespace std;

// 抽象类，无具体实例化
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

// 主类
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
 		//释放CPU零件
		if (m_cpu != NULL)
		{
			delete m_cpu;
			m_cpu = NULL;
		}

		//释放显卡零件
		if (m_gpu != NULL)
		{
			delete m_gpu;
			m_gpu = NULL;
		}

		//释放内存条零件
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
        cout << "Intel的CPU开始计算了" << endl;
    }
};
class LenovoCPU :public CPU
{
public:
	virtual void calculate()
	{
		cout << "Lenovo的CPU开始计算了！" << endl;
	}
};
class IntelGPU :public GPU
{
public:
	virtual void display()
	{
		cout << "Intel的显卡开始显示了！" << endl;
	}
};
class LenovoGPU :public GPU
{
public:
	virtual void display()
	{
		cout << "Lenovo的显卡开始显示了！" << endl;
	}
};

class IntelMemory :public Memory
{
public:
	virtual void storage()
	{
		cout << "Intel的内存条开始存储了！" << endl;
	}
};
class LenovoMemory :public Memory
{
public:
	virtual void storage()
	{
		cout << "Lenovo的内存条开始存储了！" << endl;
	}
};

void test()
{
    CPU *intelCpu   = new IntelCPU;
    GPU * intel_Gpu = new IntelGPU;
    Memory * intel_mem = new IntelMemory;

	cout << "第一台电脑开始工作：" << endl;
	//创建第一台电脑
	Computer *computer1 = new Computer(intelCpu, intel_Gpu, intel_mem);
	computer1->work();
	delete computer1;
}