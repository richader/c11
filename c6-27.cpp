#include <pthread.h>
#include <iostream>

using namespace std;

//线程本地化标记，全局变量变成每个线程内的局部全局变量
int thread_local errCode = 0;

void* MarSetErr(void* input){
	if(*(int*)input == 1){
		errCode = 1;
	}else if(*(int*)input == 2){
		errCode =-1;
	}else{
		errCode = 0;
	}
}

int main(int argc, char const *argv[])
{
	int input_a =1;
	int input_b=2;
	pthread_t thread1,thread2;
	pthread_create(&thread1,NULL,&MarSetErr,&input_a);
	pthread_create(&thread2,NULL,&MarSetErr,&input_b);
	pthread_join(thread2,NULL);
	pthread_join(thread1,NULL);
	cout <<errCode<<endl;
	return 0;
}