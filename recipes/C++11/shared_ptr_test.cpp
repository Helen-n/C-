//ʾ������1.0 http://www.cnblogs.com/feng-sc/p/5710724.html
/*
  shread_ptr ����ڴ��ͷŵ����⣬��װ�ڲ�����ͳ���ֶΣ����ֶ�Ϊ0ʱ���Զ������������ڴ�
*/
#include <memory>
#include <iostream>
class Test
{
public:
	Test()
	{
		std::cout << "Test()" << std::endl;
	}
	~Test()
	{
		std::cout << "~Test()" << std::endl;
	}
};
int main()
{
	std::shared_ptr<Test> p1 = std::make_shared<Test>();
	std::cout << "1 ref:" << p1.use_count() << std::endl;        // 1 ref: 1
	{
		std::shared_ptr<Test> p2 = p1;
		std::cout << "2 ref:" << p1.use_count() << std::endl;    // 2 ref: 2
	}
	std::cout << "3 ref:" << p1.use_count() << std::endl;        // 3 ref: 1
	return 0;
}