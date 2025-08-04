cmake_minimum_required(VERSION 3.8)

project (weld)
#PROJECT_SOURCE_DIR 和project() 配合使用
message(STATUS "----------------#weld# ")
message(STATUS "PROJECT_SOURCE_DIR=${PROJECT_SOURCE_DIR}")
#告诉 CMake 在编译时自动包含当前源文件所在的目录，这样在代码中包含头文件时就不需要写完整的路径。
set(CMAKE_INCLUDE_CURRENT_DIR ON)
#set(CMAKE_AUTOUIC ON)

# MSVC
add_compile_options(/utf-8)  
# GCC/Clang  
add_compile_options(-finput-charset=UTF-8)  

# 1. 设置 C++ 标准为 C++17（或更高，如 C++20）
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON) # 强制启用，避免回退到旧标准

# 2. MSVC 专属选项：修复 __cplusplus 和标准兼容性
if(MSVC)
    add_compile_options(/Zc:__cplusplus /permissive-)
endif()

##通过下面这种方式进行find_package
set(CMAKE_PREFIX_PATH  "C:/Qt5/Qt/5.15.2/msvc2019_64")
#需要注意的是，设置了CMAKE_PREFIX_PATH时，CMake会优先在CMAKE_PREFIX_PATH指定的路径下查找。如果没有找到，CMake会进一步在默认查找路径
#file(TO_CMAKE_PATH ${CMAKE_PREFIX_PATH} QTDIR)
#message(STATUS "QTDIR=${QTDIR}")
find_package(Qt5Core REQUIRED)
find_package(Qt5Network REQUIRED)
find_package(Qt5SerialPort REQUIRED)
find_package(Qt5Gui REQUIRED)
find_package(Qt5Sql REQUIRED)
find_package(Qt5Widgets REQUIRED)
find_package(Qt5Xml REQUIRED)
find_package(Qt5Concurrent REQUIRED)

message(STATUS "Qt5Concurrent_INCLUDE_DIRS=${Qt5Concurrent_INCLUDE_DIRS}")
message(STATUS "Qt5Core_LIBRARIES=${Qt5Core_LIBRARIES}")
message(STATUS "Qt5Network_INCLUDE_DIRS=${Qt5Network_INCLUDE_DIRS}")
#Qt5SerialPort_LIBRARIES、Qt5Sql_LIBRARIES等这些变量变量是 CMake 在找到 Qt5 模块后默认提供的.当 find_package 正确找到 Qt5 的 SerialPort 模块后，这些变量就会被赋值
set(QT_LIBRARIES ${Qt5SerialPort_LIBRARIES} ${Qt5Sql_LIBRARIES} ${Qt5Network_LIBRARIES} ${Qt5Core_LIBRARIES} ${Qt5Gui_LIBRARIES} ${Qt5Widgets_LIBRARIES} ${Qt5Xml_LIBRARIES} ${Qt5Concurrent_LIBRARIES})

set(QT_INCLUDES ${Qt5SerialPort_INCLUDE_DIRS} ${Qt5Sql_INCLUDE_DIRS} ${Qt5Network_INCLUDE_DIRS} ${Qt5Core_INCLUDE_DIRS} ${Qt5Gui_INCLUDE_DIRS} ${Qt5Widgets_INCLUDE_DIRS} ${Qt5Xml_INCLUDE_DIRS} ${Qt5Concurrent_INCLUDE_DIRS})
#作用域
include_directories(${QT_INCLUDES})
#include_directories 命令添加的目录作用域取决于它在 CMakeLists.txt 文件中的位置。要是在 add_subdirectory 命令之前调用，这些目录会对所有子项目生效；要是在 add_subdirectory 命令之后调用，仅对当前子项目生效。

##通过下面这种方式进行find_package
set(CMAKE_PREFIX_PATH  "C:/download_3rdparty/sqlite")
find_package(SQLite3 REQUIRED)
if(SQLite3_FOUND)
    message(STATUS "Found SQLite3: ${SQLite3_VERSION}")
    message(STATUS "SQLite3 Include Dir: ${SQLite3_INCLUDE_DIRS}")
    message(STATUS "SQLite3 Libraries: ${SQLite3_LIBRARIES}")  
else()
    message(FATAL_ERROR "SQLite3 not found")
endif()

#作用域
include_directories(${SQLite3_LIBRARIES})


message(STATUS "CMAKE_CURRENT_SOURCE_DIR=${CMAKE_CURRENT_SOURCE_DIR}")  
# LIBRARY_OUTPUT_DIRECTORY 在 Windows 下对 .dll 无效（但对 Linux/macOS 有效）
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY_DEBUG ${CMAKE_CURRENT_SOURCE_DIR}/build/bin)
## 全局设置输出路径（按配置分目录）
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/build/lib)  # 控制 .lib
#在 Windows 中，.dll 文件必须通过此变量设置路径！
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/build/bin)


#EGMServer_INCLUDE这个变量在里面的CMakeLists中会用到
set(EGMServer_INCLUDE ${CMAKE_CURRENT_SOURCE_DIR}/EGMServer/include)
set(EGMServer_LIBRARIES EGMServerSharedLibs)


set(UTILITY_INCLUDE ${CMAKE_CURRENT_SOURCE_DIR}/utility)

set(LASER_INCLUDE ${CMAKE_CURRENT_SOURCE_DIR}/Laser)

set(UI_INCLUDE ${CMAKE_CURRENT_SOURCE_DIR}/ui)
message(STATUS "UI_INCLUDE=${CMAKE_CURRENT_SOURCE_DIR}/ui")
set(LS_ROOT ${CMAKE_CURRENT_SOURCE_DIR})
set(Ezcad3_include ${LS_ROOT}/3rdparty/Ezcad3/inculde)
message(STATUS "CMAKE_RUNTIME_OUTPUT_DIRECTORY=${CMAKE_RUNTIME_OUTPUT_DIRECTORY} ")

set(L_Find_DIR ${LS_ROOT}/cmake)
#CMAKE_MODULE_PATH：CMake 内置变量，存储查找自定义模块（如 Findxxx.cmake）的路径列表
#把 ${L_Find_DIR}（需提前定义的路径变量）追加到 CMAKE_MODULE_PATH 最前面，让 CMake 优先在 ${L_Find_DIR} 里找自定义模块（比如 Findmodbus.cmake ）。
set(CMAKE_MODULE_PATH ${L_Find_DIR} ${CMAKE_MODULE_PATH})

#modbus库使用
find_package(modbus REQUIRED) 
include_directories(${modbus_INCLUDE_DIRS})


#set(json_INCLUDE ${CMAKE_CURRENT_SOURCE_DIR}/utility/json)
message(STATUS "----------------#weld#end ")
# 包含子项目。

add_subdirectory (utility)
add_subdirectory (utility2)
add_subdirectory (Laser)
add_subdirectory (EGMServer)
add_subdirectory (EGMServer/test)
add_subdirectory (ui)
add_subdirectory (userManager)

add_subdirectory (3DCalib)



