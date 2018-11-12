#include <cstdio>
#include <cstddef>

using namespace std;

int main(int argc, char const *argv[])
{
	nullptr_t my_null;
	printf("%x\n", &my_null);

	printf("%d\n", my_null == nullptr);

	const nullptr_t && default_nullptr = nullptr;
	printf("%x\n", &default_nullptr);
	return 0;
}