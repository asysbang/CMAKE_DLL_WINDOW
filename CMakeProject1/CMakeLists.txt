# CMakeList.txt: CMakeProject1 的 CMake 项目，在此处包括源代码并定义
# 项目特定的逻辑。
#
cmake_minimum_required (VERSION 3.8)

project(TEST_NOW)
# 将源代码添加到此项目的可执行文件。
add_executable (CMakeProject1 "CMakeProject1.cpp" "CMakeProject1.h")

add_library(MyDll SHARED "MyDll.cpp" "MyDll.h") #动态库生成

#find_package(MyDll CONFIG REQUIRED)
link_directories(${PROJECT_SOURCE_DIR}/libs) #动态库引用
include_directories(${PROJECT_SOURCE_DIR}/includes)

#add_library(myopencv STATIC IMPORTED)
#set_property(TARGET myopencv PROPERTY IMPORTED_LOCATION ${PROJECT_SOURCE_DIR}/libs/opencv_world411.lib)
     find_package(Tesseract CONFIG REQUIRED)
 target_link_libraries(CMakeProject1 -lMyDll libtesseract)

 

 #target_link_libraries(CMakeProject1 MyDll  ${CMAKE_SOURCE_DIR}/libs/libleptonica-1.78.0.lib ${CMAKE_SOURCE_DIR}/libs/opencv_world411.lib 	${CMAKE_SOURCE_DIR}/libs/libtesseract41.lib)
 #target_link_libraries(CMakeProject1 PRIVATE benchmark::benchmark benchmark::benchmark_main MyDll libtesseract)

# TODO: 如有需要，请添加测试并安装目标。

   #find_package(Tesseract CONFIG REQUIRED)
    #target_link_libraries(main PRIVATE libtesseract)

