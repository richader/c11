/**
*	验证map中元素的有序性
*
*/

#include <map>
#include <string>
#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
	map<string,string> kvs;
	kvs["0.98"]="0.98";
	kvs["2.1"]="2.1";
	kvs["2.0"]="2.0";
	kvs["1.0"]="1.0";
	kvs["1.1"]="1.1";
	kvs["1.2"]="1.2";
	kvs["1.3"]="1.3";
	kvs["1.4"]="1.4";
	kvs["1.11"]="1.11";

	for (std::map<string, string>::iterator it=kvs.begin(); it!=kvs.end(); ++it)
	{
		cout<<it->first<<endl;
	}

	cout << kvs.rbegin()->first<<endl;
	return 0;
}
