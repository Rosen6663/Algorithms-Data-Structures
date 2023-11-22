# STL
## 概念
+ STL(Standard Template Library,**标准模板库**)
+ 分类
	+ 容器
	+ 算法
	+ 迭代器
+ 容器和算法之间通过迭代器进行无缝衔接
+ STL几乎所有的代码都采用了模板和函数
## 组件
六大组件
1. 容器：各种数据结构：如vector,list,deque,set,map
	1. 序列式容器：强调值的排序
	2. 关联式容器：：没有严格的顺序关系
2. 算法:各种算法，如：sort,find,copy,for_each
3. 迭代器:容器和算法之间的胶合剂
4. 
	 ![](image/Pasted%20image%2020231122092425.png)
4. 仿函数：行为类似函数，可以作为算法的某种策略
5. 适配器：一种用于修饰容器额或者仿函数或迭代器接口的东西
6. 空间配置器：负责空间的配置与管理

# Vector
## 简述
+ 容器：vectoe
+ 算法:for_each
+ 迭代器:vector(int)::iterator
## 使用
