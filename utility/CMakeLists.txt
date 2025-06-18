
message(STATUS "\n----------------------#utility:#")
message(STATUS "CMAKE_CURRENT_SOURCE_DIR=${CMAKE_CURRENT_SOURCE_DIR}")

add_definitions(-DUTILITY_EXPORTS)
#增加头文件所在目录：
#include_directories(${QT_INCLUDES})

#include_directories(path json)
#将所有需要编译的cpp源码文件路径资源保存在ALL_SRCS中
file(GLOB_RECURSE ALL_SRCS "json/*.cpp" "path/*.cpp")
#将所有需要编译的h头文件路径资源保存在ALL_INCLUDES中
file(GLOB_RECURSE ALL_INCLUDES "json/*.h" "path/*.h")

message(STATUS "ALL_SRCS=${ALL_SRCS}")
message(STATUS "\nALL_INCLUDES=${ALL_INCLUDES}")

#MOC 会处理包含 Q_OBJECT 宏的头文件，生成必要的代码以支持 Qt 的信号和槽机制。
#set(CMAKE_AUTOMOC ON) #若没有这句话，软件界面不支持信号和槽机制
#UIC 会将 .ui 文件（Qt Designer 设计的界面文件）转换为 C++ 代码
#set(CMAKE_AUTOUIC ON)

#只有把增加的.h .cpp文件使用（如生成库、链接到exe中) .h .cpp才不是杂项文件
add_library(Utility SHARED ${ALL_SRCS} ${ALL_INCLUDES} )#${Mocfiles} ${ui_FILES}
target_link_libraries(Utility ${QT_LIBRARIES})

#include_directories：
#全局生效，对当前 CMakeLists.txt 及子目录中所有目标（后续定义的库、可执行文件等）添加头文件搜索路径，属于全局作用域。
#例如：在根目录 CMakeLists 中使用后，所有子模块的目标都会继承这些路径。

#target_include_directories：
#仅对指定目标（如通过 add_library/add_executable 创建的目标）生效，属于目标级作用域。
#例如：为库 MyLib 设置的路径，不会影响可执行文件 MyApp（除非 MyApp 依赖 MyLib 且通过 PUBLIC/INTERFACE 传递）

#现代 CMake 推荐使用 target_include_directories，以实现更精确的依赖管理
target_include_directories(Utility PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/path ${CMAKE_CURRENT_SOURCE_DIR}/json)




message(STATUS "----------------#utility#end")

#set(EGMServer_LIBRARIES EGMServerLibs)
##----------set方法说明：缓存变量用法 
#set(path ${PROJECT_SOURCE_DIR} CACHE PATH "path")
#message(WARNING ${path})
#set(path ${PROJECT_BINARY_DIR} CACHE PATH "path" [FORCE])
#message(WARNING ${path})
#message(WARNING ${path})

 