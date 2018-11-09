/**
* 6.3.3,代码清单6-24.
* 在mac笔记本上，是强内存模型，不会出现b.store先执行的场景.

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
	while(b.load(memory_order_relaxed)!=2);

	cout<<a.load(memory_order_relaxed)<<endl;  
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