#define MYDLL_EXPORTS
#include "MyDll.h"
#include <iostream>
using namespace std;
MYDLL_API void hello(void)
{
	cout << "this is my dll" << endl;
}