//ʾ������1.0 http://www.cnblogs.com/feng-sc/p/5710724.html
/*
 *  A��auto�ؼ�������ʲô��
 *    ֻ��ʹ��auto��ʱ�򣬱��������������������ȷ��auto�������������͡�
 *  B��auto������ʲô��
 *    auto��Ϊ��������ֵʱ��ֻ�����ڶ��庯����������������������
*/

#include <iostream>
auto AddTest(int a, int b)
{
	return a + b;
}
int main()
{
	auto index = 10;
	auto str = "abc";
	auto ret = AddTest(1, 2);
	std::cout << "index:" << index << std::endl;
	std::cout << "str:" << str << std::endl;
	std::cout << "res:" << ret << std::endl;
}