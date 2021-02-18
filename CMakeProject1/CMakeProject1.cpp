// CMakeProject1.cpp: 定义应用程序的入口点。
//

#include "CMakeProject1.h"
#include <windows.h>
using namespace std;

int main()
{
	cout << "Hello CMake." << endl;

	HINSTANCE handle = LoadLibrary("MyDll.dll");
	typedef void (*pointer)(void);
	pointer f;
	f = (pointer)GetProcAddress(handle, "hello");
	f();
	FreeLibrary(handle);
	return 0;
}
