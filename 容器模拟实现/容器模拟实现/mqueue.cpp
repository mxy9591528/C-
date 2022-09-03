#include"mqueue.hpp"
#include<string>
using namespace mxyqueue;
class Person
{
	string m_name;
	int m_age;
public:
	Person(string name, int age)
	{
		this->m_name = name;
		this->m_age = age;
	}
	string getName()
	{
		return this->m_name;
	}
	int getAge()
	{
		return this->m_age;
	}
};
int main()
{
	Person p[4] = { {"����",999},{"����",888},{"�ֶ�",777},{"����",666} };
	mqueue<Person>q;
	for (int i = 0; i < 4; i++)
		q.push(p[i]);
	while (!q.empty())
	{
		cout << "��ͷԪ�ء�������:" << q.front().getName() << "  ����:" << q.front().getAge() << endl;
		cout << "��βԪ�ء�������:" << q.back().getName() << "  ����:" << q.back().getAge() << endl;
		q.pop();
	}
	cout << "���д�СΪ:" << q.size() << endl;
}