
message(STATUS "\n----------------------#ui:#")
message(STATUS "CMAKE_CURRENT_SOURCE_DIR=${CMAKE_CURRENT_SOURCE_DIR}")


#utility
include_directories(${UTILITY_INCLUDE}/json )

#将所有需要编译的cpp源码文件路径资源保存在ALL_SRCS中
file(GLOB_RECURSE ALL_SRCS "9SquareGrids/*.cpp" )
#将所有需要编译的h头文件路径资源保存在ALL_INCLUDES中
file(GLOB_RECURSE ALL_INCLUDES "9SquareGrids/*.h")

message(STATUS "ALL_SRCS=${ALL_SRCS}")
message(STATUS "\nALL_INCLUDES=${ALL_INCLUDES}")

#MOC 会处理包含 Q_OBJECT 宏的头文件，生成必要的代码以支持 Qt 的信号和槽机制。
set(CMAKE_AUTOMOC ON) #若没有这句话，软件界面不支持信号和槽机制
#UIC 会将 .ui 文件（Qt Designer 设计的界面文件）转换为 C++ 代码
set(CMAKE_AUTOUIC ON)

add_library(UILib SHARED ${ALL_SRCS} ${ALL_INCLUDES} 9SquareGrids/PositionDatumsDialog.ui)

target_link_libraries(UILib ${QT_LIBRARIES} Utility)

target_include_directories(UILib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR} ${CMAKE_CURRENT_SOURCE_DIR}/9SquareGrids)

message(STATUS "CMAKE_ARCHIVE_OUTPUT_DIRECTORY=${CMAKE_ARCHIVE_OUTPUT_DIRECTORY} ")
message(STATUS "----------------#ui#end")

#set(EGMServer_LIBRARIES EGMServerLibs)
##----------set方法说明：缓存变量用法 
#set(path ${PROJECT_SOURCE_DIR} CACHE PATH "path")
#message(WARNING ${path})
#set(path ${PROJECT_BINARY_DIR} CACHE PATH "path" [FORCE])
#message(WARNING ${path})
#message(WARNING ${path})

 