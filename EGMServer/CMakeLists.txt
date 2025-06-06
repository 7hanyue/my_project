project (EGMServer)
message(STATUS "\n----------------------#EGMServer:#")
message(STATUS "CMAKE_CURRENT_SOURCE_DIR=${CMAKE_CURRENT_SOURCE_DIR}")
#增加头文件所在目录：
include_directories(include)
##add_definitions用法的网址链接 https://blog.csdn.net/qq_35699473/article/details/115837708##
add_definitions(-DEGMServer_Plugin)
#
#将所有需要编译的cpp源码文件路径资源保存在ALL_SRCS中
file(GLOB_RECURSE ALL_SRCS "src/*.cpp")
#将所有需要编译的h头文件路径资源保存在ALL_INCLUDES中
file(GLOB_RECURSE ALL_INCLUDES "include/*.h")

message(STATUS "ALL_SRCS=${ALL_SRCS}")
message(STATUS "\nALL_INCLUDES=${ALL_INCLUDES}")

#MOC 会处理包含 Q_OBJECT 宏的头文件，生成必要的代码以支持 Qt 的信号和槽机制。
set(CMAKE_AUTOMOC ON) #若没有这句话，软件界面不支持信号和槽机制
#UIC 会将 .ui 文件（Qt Designer 设计的界面文件）转换为 C++ 代码
set(CMAKE_AUTOUIC ON)

qt5_wrap_ui(ui_FILES src/EGMServer.ui)
qt5_wrap_cpp(Mocfiles ${ALL_INCLUDES} ${ALL_SRCS})
source_group("moc" FILES ${Mocfiles})
message("Mocfiles" ${Mocfiles})
message("ui_FILES" ${ui_FILES})
#include_directories(${CMAKE_CURRENT_BINARY_DIR})

message("CMAKE_CURRENT_SOURCE_DIR" ${CMAKE_CURRENT_SOURCE_DIR})
# 指定要链接的动态库的路径
#link_directories(${PROJECT_SOURCE_DIR}/lib)
add_library(EGMServerSharedLibs SHARED ${ALL_SRCS} ${ALL_INCLUDES} ${Mocfiles} ${ui_FILES})
target_link_libraries(EGMServerSharedLibs ${QT_LIBRARIES})

message(STATUS "----------------#EGMServer#end")

#set(EGMServer_LIBRARIES EGMServerLibs)
##----------set方法说明：缓存变量用法 
#set(path ${PROJECT_SOURCE_DIR} CACHE PATH "path")
#message(WARNING ${path})
#set(path ${PROJECT_BINARY_DIR} CACHE PATH "path" [FORCE])
#message(WARNING ${path})
#message(WARNING ${path})

 