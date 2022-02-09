// thread5_text.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
//多线程执行顺序乱，与操作系统对线程的调度机制有关

#include "pch.h"
#include <iostream>
#include<string>
#include<thread>
#include<list>
#include<vector>
using namespace std;

void myprint(int num)
{
	cout<<"开始执行，线程编号="<<num<<endl;
	//。。。
	cout << "结束执行，线程编号=" << num << endl;
	return;
}

int main()
{
	vector <thread> mythreads;//创建线程容器，方便管理
	for (int i = 0; i < 10; i++)//创建10个线程
	{
		mythreads.push_back(thread(myprint,i));//创建并开始执行线程
	}
	//join等待
	for (auto iter = mythreads.begin(); iter != mythreads.end(); iter++)//构造容器迭代器完成主线程等待操作、、、、、、、、、、、重点！！！！！以后常用！
	{
		iter->join();
	}
	cout << "主线程执行结束" << endl;
	return 0;
}

