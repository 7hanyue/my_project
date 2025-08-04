project (3DCalib)
message(STATUS "\n----------------------#3DCalib:#")
message(STATUS "CMAKE_CURRENT_SOURCE_DIR=${CMAKE_CURRENT_SOURCE_DIR}")

#增加头文件所在目录：
include_directories(include)

#utility
include_directories(${UTILITY_INCLUDE}/json )

#Laser
include_directories(${LASER_INCLUDE}/manager)

#ui
include_directories(${UI_INCLUDE}/9SquareGrids)
message(STATUS "ui=${UI_INCLUDE}/9SquareGrids")

#Ezcad3
include_directories(${Ezcad3_include})

#将所有需要编译的cpp源码文件路径资源保存在ALL_SRCS中
file(GLOB_RECURSE ALL_SRCS "*.cpp" ../Laser/*.cpp ../ui/*.cpp)#
#将所有需要编译的h头文件路径资源保存在ALL_INCLUDES中
file(GLOB_RECURSE ALL_INCLUDES "*.h" ../Laser/*.h ../ui/*.h)#

message(STATUS "ALL_SRCS=${ALL_SRCS}")
message(STATUS "\nALL_INCLUDES=${ALL_INCLUDES}")

#MOC 会处理包含 Q_OBJECT 宏的头文件，生成必要的代码以支持 Qt 的信号和槽机制。
set(CMAKE_AUTOMOC ON) #若没有这句话，软件界面不支持信号和槽机制
#UIC 会将 .ui 文件（Qt Designer 设计的界面文件）转换为 C++ 代码
set(CMAKE_AUTOUIC ON)

#include_directories(${CMAKE_CURRENT_BINARY_DIR})

message("CMAKE_CURRENT_SOURCE_DIR" ${CMAKE_CURRENT_SOURCE_DIR})

add_executable(CalibrationWizard WIN32 ${ALL_SRCS} ${ALL_INCLUDES} ClockWidget.ui )
#"CalibParam.h" "CalibParam.cpp"
target_link_libraries(CalibrationWizard ${QT_LIBRARIES} Utility LaserLib UILib)

message(STATUS "----------------#3DCalib#end")

#set(EGMServer_LIBRARIES EGMServerLibs)
##----------set方法说明：缓存变量用法 
#set(path ${PROJECT_SOURCE_DIR} CACHE PATH "path")
#message(WARNING ${path})
#set(path ${PROJECT_BINARY_DIR} CACHE PATH "path" [FORCE])
#message(WARNING ${path})
#message(WARNING ${path})

 