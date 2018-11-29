/**
 * 文章中示例错误，这个utf-8字符串的长度是13，而不是15
 *
 */
#include <iostream>

using namespace std;

int main(){
  char u8string[]=u8R"(你好)""=hello";
  cout<<u8string<<endl;
  cout<<sizeof(u8string)<<endl;
  return 0;
}
