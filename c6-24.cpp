/**
* 6.3.3,代码清单6-24.例子有问题。在强顺序的模型的机器上，由于t1、t2启动顺序的问题， 也有可能有不同的输出结果。
* t1先执行，且在a.store和b.store之间停顿，才能得到预期结果.
* 如果t1先执行且没有停顿，t2没法进入循环体，没有输出
* 如果t2先执行，则会先输出1或多个0，t1停顿才有可能输出1，不停顿不会输出1.
*/
#include <thread>
#include <atomic>
#include <iostream>

using namespace std;

atomic<int> a{0};
atomic<int> b{0};
int Thread1(int){
	int t=1;
	a.store(t,memory_order_relaxed);
	b.store(2,memory_order_relaxed);
}
int Thread2(int){
	while(b.load(memory_order_relaxed)!=2){
		cout<<a.load(memory_order_relaxed)<<endl;
	} 
}

int main(int argc, char const *argv[])
{
	thread t1(Thread1,0);
	thread t2(Thread2,0);
	t1.join();
	t2.join();

	cout<<"Got("<<a<<","<<b<<")"<<endl;
	return 0;
}