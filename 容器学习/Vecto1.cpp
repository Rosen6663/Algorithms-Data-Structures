#include<iostream>
using namespace std;
#include<vector>
int mian()
{
	vector<int> v;
	#�������� 
	v.push_back(10);
	v.push_back(20);
	v.push_back(30);
	v.push_back(40);
	v.push_back(50);
	#�൱��ָ�룬ָ���һ��Ԫ�صĵ����� 
	vector<int>::iterator itBegin =v.begin();
	#ָ�����һ��Ԫ�ص���һ��  
	vector<int>::iterator itEnd =v.end();
	
	return 0;
}
