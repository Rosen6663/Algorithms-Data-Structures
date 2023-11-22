#include<iostream>
using namespace std;
#include<vector>
int mian()
{
	vector<int> v;
	#插入数据 
	v.push_back(10);
	v.push_back(20);
	v.push_back(30);
	v.push_back(40);
	v.push_back(50);
	#相当于指针，指向第一个元素的迭代器 
	vector<int>::iterator itBegin =v.begin();
	#指向最后一个元素的下一个  
	vector<int>::iterator itEnd =v.end();
	
	return 0;
}
