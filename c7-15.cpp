/**
*	删除默认生成的new重载函数，禁止使用new 的方式在堆上分配内存。
*	
*	使用new创建对象，会造成编译失败。
*/

#include <cstddef>

char* p;

class NoHeapAlloc{
public:
	void* operator new(std::size_t)=delete;
};

int main(int argc, char const *argv[])
{
	NoHeapAlloc nha;
	NoHeapAlloc* p_nha=new NoHeapAlloc();
	return 0;
}

//g++ -std=c++11 c7-15.cpp