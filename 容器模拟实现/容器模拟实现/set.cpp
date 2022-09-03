#include<iostream>
#include<set>
using namespace std;
void printSet(set<int>&s)
{
	for (set<int>::iterator it = s.begin(); it != s.end(); it++)
		cout << *it << " ";
	cout << endl;
}
void test01()
{
	set<int>s1;
	s1.insert(10);
	s1.insert(20);
	s1.insert(30);
	s1.insert(40);
	printSet(s1);
	set<int>s2(s1);
	printSet(s2);
	set<int>s3;
	s3 = s2;
	printSet(s3);
}
void test02()
{
	set<int>s1;
	s1.insert(10);
	s1.insert(20);
	s1.insert(30);
	s1.insert(40);
	printSet(s1);
	if (s1.empty())
		cout << "s1Ϊ��" << endl;
	else
		cout << "s1��Ϊ��,Ԫ�ظ���Ϊ:" <<s1.size()<< endl;
	set<int>s2;
	s2.insert(1);
	s2.insert(3);
	s2.insert(5);
	s2.insert(7);
	cout << "����ǰ" << endl;
	printSet(s1);
	printSet(s2);
	cout << "������" << endl;
	s1.swap(s2);
	printSet(s1);
	printSet(s2);
}
void test03()
{
	set<int>s1;
	s1.insert(10);
	s1.insert(20);
	s1.insert(30);
	s1.insert(40);
	printSet(s1); 
	s1.erase(s1.begin());
	printSet(s1);
	s1.erase(30);
	printSet(s1);
	s1.clear();
	printSet(s1);
}
void test04()
{
	set<int>s1;
	s1.insert(10);
	s1.insert(20);
	s1.insert(30);
	s1.insert(40);
	//��Ч
	s1.insert(30);
	s1.insert(30);
	auto pos=s1.find(30);
	if (pos != s1.end())
		cout << "�ҵ���" << *pos << endl;
	else
		cout << "û�ҵ�" << endl;
	int num = s1.count(30);
	cout << "num=" << num << endl;
}
void test05()
{
	set<int>s;
	pair<set<int>::iterator, bool>ret = s.insert(10);
	if (ret.second)
		cout << "��һ�β���ɹ�" << endl;
	else
		cout << "��һ�β���ʧ��" << endl;
	ret = s.insert(10);
	if (ret.second)
		cout << "�ڶ��β���ɹ�" << endl;
	else
		cout << "�ڶ��β���ʧ��" << endl;
	multiset<int>ms;
	ms.insert(10);
	ms.insert(10);
	ms.insert(10);
	for (auto it : ms)
		cout << it << " ";
	cout << endl;
}
class cmp
{
public:
	bool operator()(int v1, int v2)
	{
		return v1 > v2;
	}
};
void test06()
{
	set<int>s1;
	s1.insert(10);
	s1.insert(30);
	s1.insert(50);
	s1.insert(40);
	s1.insert(20);
	printSet(s1);
	set<int,cmp>s2;
	s2.insert(10);
	s2.insert(30);
	s2.insert(50);
	s2.insert(40);
	s2.insert(20);
	for (set<int, cmp>::iterator it = s2.begin(); it != s2.end(); it++)
		cout << *it << " ";
	cout << endl;
}
#include<string>
class Person
{
public:
	Person(string name, int age)
	{
		this->m_age = age;
		this->m_name = name;
	}
	string m_name;
	int m_age;
};
class Compare
{
public:
	bool operator()(const Person&p1, const Person&p2)
	{
		return p1.m_age > p2.m_age;
	}
};
void test07()
{
	set<Person,Compare>s;
	Person p[5] = 
	{
	{"����",28},
	{"�ŷ�",25},
	{"����",24},
	{"��",23},
	{"����",30}
	};
	for (int i = 0; i <5; i++)
		s.insert(p[i]);
	for (set<Person,Compare>::iterator it=s.begin();it!=s.end();it++)
		cout << "����:" << it->m_name << "����:" << it->m_age << endl;

}
int main()
{
	//test01();
	//test02();
	//test03();
	//test04();
	//test05();
	//test06();
	test07();
}
