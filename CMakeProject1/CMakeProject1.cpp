// CMakeProject1.cpp: 定义应用程序的入口点。
//

#include "CMakeProject1.h"
#include <windows.h>
#include "tesseract/baseapi.h"
#include "leptonica/allheaders.h"
#include "opencv2/opencv.hpp"
using namespace std;
using namespace cv;
tesseract::TessBaseAPI tessEng;
int main()
{
	cout << "Hello CMake." << endl;

	Mat mm = imread("full.png");
	cout << mm.rows << endl;

	HINSTANCE handle = LoadLibrary("MyDll.dll");
	typedef void (*pointer)(void);
	pointer f;
	f = (pointer)GetProcAddress(handle, "hello");
	f();
	FreeLibrary(handle);
	tessEng.Init("tessdata","eng");
	tessEng.SetPageSegMode(tesseract::PageSegMode::PSM_SINGLE_LINE);
	tessEng.SetVariable("save_best_choices", "T");
	auto pixs = pixRead("tesseract_eng.png");
	tessEng.SetImage(pixs);
	cout << tessEng.GetUTF8Text();
	tessEng.Clear();
	pixDestroy(&pixs);
	cin.get();
	return 0;
}
