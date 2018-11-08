/**
* 章节6.3.3，代码清单6.25
* 按文章中的逻辑，两个线程中必须遵守顺序：t1先于t2执行，且t1执行到a.store和b.store语句之间有个停顿，等待t2输出，才能得到预期的结果。
* 否则，1、t2先执行会循环疏忽一堆0；t1没有停顿的话，b.store执行后t2不符合循环条件，无法进入循环内部输出。
*
* 以下修改会有两种结果：t1先执行，得到预期结果.t2先执行，无输出。
* 总得来说，无法保证两个线程之间的执行顺序，也不保证执行进度一致。
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
	b.store(2,memory_order_release);
}
int Thread2(int){
	// while(b.load(memory_order_acquire)!=2){
	// 	cout<<a.load(memory_order_relaxed)<<endl;
	// } 
	while(b.load(memory_order_acquire)==2){
		cout<<a.load(memory_order_relaxed)<<endl;
		break;
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