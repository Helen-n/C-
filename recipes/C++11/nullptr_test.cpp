//ʾ������1.0 http://www.cnblogs.com/feng-sc/p/5710724.html
/*
 *  NULL ��ʾ��ָ�룬���Ǳ�ʾ0��
 *  nullptr ��ʾ���ǿ�ָ�룻
*/

#include<iostream>
class Test
{
public:
	void TestWork(int index)
	{
		std::cout << "TestWork 1" << std::endl;
	}
	void TestWork(int * index)
	{
		std::cout << "TestWork 2" << std::endl;
	}
};

int main()
{
	Test test;
	test.TestWork(NULL); // TestWork 1
	test.TestWork(nullptr); // TestWork 2
	return 0;
}