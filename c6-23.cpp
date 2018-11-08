#include <thread>
#include <atomic>
#include <iostream>

using namespace std;

atomic<int> a{0};
atomic<int> b{0};
int ValSet(int){
	int t=1;
	a.store(t,memory_order_relaxed);
	b.store(2,memory_order_relaxed);
}
int Observer(int){
	cout<<"("<<a<<","<<b<<")"<<endl;
}

int main(int argc, char const *argv[])
{
	thread t1(ValSet,0);
	thread t2(Observer,0);
	t1.join();
	t2.join();

	cout<<"Got("<<a<<","<<b<<")"<<endl;
	return 0;
}