
/*
һ�������е����ӣ�
������վ�ڱ�����������
���ģ�վ�����ڣ�������
��c++�У�
���˵����������������������⣬�����������������������ܲ���������������
1.�߳�Aִ�е�ʱ������߳������������ѽ���lock()�ɹ���Ȼ����ȥlock()����������
�������ʱ��������������л�
2.�߳�Bִ���ˣ�����߳�������������Ϊ�����߳�A��ûִ�У�����B������ɹ���Ȼ���߳�BҪȥLock������
��ʱ�����Ͳ�����.
*/

#include<thread>
#include<iostream>
#include<mutex>
#include<list>

using namespace std;

class A {

public:
	//���յ�����Ϣ���������͵�һ��������
	void inMsgRecvQueue() {
		for (int i = 0; i < 100000; i++)
		{
			cout << "inMsgRecvQueue()ִ�У�����һ��Ԫ��" << endl;
			my_mutex1.lock();//ʵ�ʹ����п�������������ͷ��һ������
							 //.....................
			my_mutex2.lock();
			msgRecvQueue.push_back(i);//����������־������յ��������ֱ��Ū����Ϣ��������ȥ
			my_mutex2.unlock();
			my_mutex1.unlock();
		}
		return;
	}

	bool outMgLULProc(int& command) {


		my_mutex1.lock();
		my_mutex2.lock();

		std::lock(my_mutex1, my_mutex2);
		if (!msgRecvQueue.empty())
		{
			int command = msgRecvQueue.front();//���ص�һ��Ԫ�أ�
			msgRecvQueue.pop_front();//�Ƴ���һ��Ԫ�أ���������
									 //����Ϳ��Ǵ�������
			my_mutex1.unlock();
			my_mutex2.unlock();
			return true;
		}
		my_mutex1.unlock();
		my_mutex2.unlock();
		return false;
	}



	//�����ݴ���Ϣ������ȡ���̣߳�
	void outMsgRecvQueue() {
		int command = 0;
		for (int i = 0; i < 100000; i++)
		{
			bool result = outMgLULProc(command);
			if (result == true)
			{
				cout << "outMsgRecvQueue()ִ�У�ȡ��һ��Ԫ��";
			}
		}
		cout << "end" << endl;
	}
private:
	//������ǹ�������
	std::list<int> msgRecvQueue;//������ר�����ڴ�����Ҹ����Ƿ�����������
	std::mutex my_mutex1;//����һ��������
	std::mutex my_mutex2;//
};

int main()
{
	A a;
	thread threadObj1(&A::inMsgRecvQueue, &a);
	thread threadObj2(&A::outMgLULProc, &a);
	threadObj1.join();
	threadObj2.join();
	return 0;
}