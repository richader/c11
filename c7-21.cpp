#include <iostream>

using namespace std;

class Tax{
public:
	Tax(float r,int b):rate(r),base(b){}
	float operator()(float money){return (money-base)*rate;}
private:
	float rate;
	int base;
};


int main(int argc, char const *argv[])
{
	Tax high(0.40,30000);
	Tax middle(0.25,20000);

	cout <<"tax over 3w:"<<high(50000)<<endl;
	cout <<"tax over 2w:"<<middle(25000)<<endl;
	return 0;
}