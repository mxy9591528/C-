#include<iostream>
#include<string>
using namespace std;
int main()
{
	pair<string, int>p("Tom", 20);
	cout << "����:" << p.first << " ����" << p.second << endl;
	pair<string, int>q("Jerry", 20);
	cout << "����:" << q.first << " ����" << q.second << endl;
	return 0;
}