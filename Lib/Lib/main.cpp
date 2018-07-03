#include "base.h"
#include "mystl.h"



int main()
{
        int b = 4;

	MySTL::map<int, int> stMap;

	stMap.insert(std::make_pair(3,3));

	MySTL::string test;

	test += "test";


	return 0;
}
