//ʾ������1.0 http://www.cnblogs.com/feng-sc/p/5710724.html
/*
 * shared_ptr �������ã������ڴ�й©��ptr_a��ptr_b�޷��ͷ�
*/
#include <memory>
#include <iostream>
class TestB;
class TestA
{
public:
	TestA()
	{
		std::cout << "TestA()" << std::endl;
	}
	void ReferTestB(std::shared_ptr<TestB> test_ptr)
	{
		m_TestB_Ptr = test_ptr;
	}
	~TestA()
	{
		std::cout << "~TestA()" << std::endl;
	}
private:
	std::shared_ptr<TestB> m_TestB_Ptr; //TestB������ָ��
};

class TestB
{
public:
	TestB()
	{
		std::cout << "TestB()" << std::endl;
	}

	void ReferTestB(std::shared_ptr<TestA> test_ptr)
	{
		m_TestA_Ptr = test_ptr;
	}
	~TestB()
	{
		std::cout << "~TestB()" << std::endl;
	}
	std::shared_ptr<TestA> m_TestA_Ptr; //TestA������ָ��
};


int main()
{
	std::shared_ptr<TestA> ptr_a = std::make_shared<TestA>();
	std::shared_ptr<TestB> ptr_b = std::make_shared<TestB>();
	ptr_a->ReferTestB(ptr_b);
	ptr_b->ReferTestB(ptr_a);
	return 0;
}