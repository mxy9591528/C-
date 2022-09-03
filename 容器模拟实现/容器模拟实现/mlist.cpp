#include"mlist.hpp"
#include<list>
#include<string>
using namespace mxylist;
void printList(const mlist<int>&L)
{
	for (mlist<int>::const_iterator i = L.begin(); i != L.end(); i++)
		cout << *i << " ";
	cout << endl;
}
void test01()
{
	mlist<int>L1;
	L1.push_back(10);
	L1.push_back(20);
	L1.push_back(30);
	L1.push_back(40);
	printList(L1);
	mlist<int>L2(L1.begin(), L1.end());
	printList(L2);
	mlist<int>L3(L2);
	printList(L3);
	mlist<int>L4(7, 3);
	printList(L4);
}
void test02()
{
	mlist<int>L1;
	L1.push_back(10);
	L1.push_back(20);
	L1.push_back(30);
	L1.push_back(40);
	printList(L1);
	mlist<int>L2;
	L2 = L1;
	printList(L2);
	mlist<int>L3;
	L3.assign(L2.begin(), L2.end());
	printList(L3);
	mlist<int>L4;
	L4.assign(7, 3);
	printList(L4);
	L1.swap(L4);
	printList(L1);
	printList(L4);
}
void test03()
{
	mlist<int>L1;
	L1.push_back(10);
	L1.push_back(20);
	L1.push_back(30);
	L1.push_back(40);
	printList(L1);
	if (L1.empty())
		cout << "L1Ϊ��" << endl;
	else
		cout << "L1��Ϊ�գ�Ԫ�ظ���Ϊ:" << L1.size() << endl;
	L1.resize(10);
	printList(L1);
	L1.resize(15, 3);
	printList(L1);
	L1.resize(1);
	printList(L1);
}
void test04()
{
	mlist<int>L;
	L.push_back(10);
	L.push_back(20);
	L.push_back(30);
	L.push_front(-10);
	L.push_front(-20);
	L.push_front(-30);
	printList(L);
	L.pop_back();
	printList(L);
	L.pop_front();
	printList(L);
	L.insert(L.begin(), 999);
	printList(L);
	L.erase(++L.begin());
	printList(L);
	L.push_back(520025);
	L.push_front(520025);
	printList(L);
	L.remove(520025);
	printList(L);
	L.clear();
	printList(L);
}
void test05()
{
	mlist<int>L1;
	L1.push_back(10);
	L1.push_back(20);
	L1.push_back(30);
	L1.push_back(40);
	cout << "��һ��Ԫ��:" << L1.front() << endl << "���һ��Ԫ��:" << L1.back() << endl;
}
void test06()
{
	mlist<int>L1;
	L1.push_back(30);
	L1.push_back(20);
	L1.push_back(100);
	L1.push_back(40);
	L1.push_back(10);
	printList(L1);
	L1.reverse();
	printList(L1);
	//���õ�ѡ������ʵ�ֵ�list���򣬻���֧���Զ�������ʽ��ʵ�ʿ⺯�������Զ���ȽϺ�������
	L1.sort();
	printList(L1);
	L1.reverse();
	printList(L1);
}
class Person
{
public:
	string m_name;
	int m_age;
	int m_height;
	Person(string name, int age, int height)
	{
		this->m_age = age;
		this->m_height = height;
		this->m_name = name;
	}
};
void printPerson(list<Person>&p)
{
	for (auto i : p)
		cout << "����:" << i.m_name << "  ����:" << i.m_age << "  ���:" << i.m_height << endl;
}
bool cmp(Person&p1,Person&p2)
{
	//������ ����
	if (p1.m_age == p2.m_age)//������ͬ����߽���
		return p1.m_height >p2.m_height;
	return p1.m_age <p2.m_age;
}
void test07()
{
	list<Person>L;
	Person p[6] =
	{
	{"����",35,165},
	{"�ܲ�",45,180},
	{"��Ȩ",40,170},
	{"�����",27,175},
	{"˾��ܲ",50,173},
	{"���",27,177}
	};
	for (int i = 0; i < 6; i++)
		L.push_back(p[i]);
	printPerson(L);
	cout << "----------------------------------------------------" << endl;
	cout << "�����" << endl;
	L.sort(cmp);
	printPerson(L);

}
int main()
{
	/*test01();
	test02();
	test03();
	test04();
	test05();
	test06();*/
	test07();
	return 0;
}
