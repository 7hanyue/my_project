message(STATUS "\n----------------------#test:#")
# moc 自动调用   Qt的几个编译工具：moc、uic、rcc
#MOC 会处理包含 Q_OBJECT 宏的头文件，生成必要的代码以支持 Qt 的信号和槽机制。
set(CMAKE_AUTOMOC ON)

#EGMServer_INCLUDE这个变量在外面的CMakeLists被定义了
include_directories (${EGMServer_INCLUDE})

file(GLOB_RECURSE ALL_INCLUDES ./*.h)
file(GLOB_RECURSE ALL_SRCS ./*.cpp)
message(STATUS "ALL_INCLUDES=${ALL_INCLUDES}")
message(STATUS "ALL_SRCS=${ALL_SRCS}")

qt5_wrap_cpp(MocFiles ${ALL_INCLUDES} ${ALL_SRCS})
source_group("moc" FILES ${MocFiles})
message("MocFiles" ${MocFiles})
#message("CMAKE_BINARY_DIR" ${CMAKE_BINARY_DIR})
#link_directories(${CMAKE_BINARY_DIR}/EGMServer)
# 将源代码添加到此项目的可执行文件。
add_executable(Test_EGMServer WIN32 ${ALL_SRCS} ${MocFiles})

target_link_libraries(Test_EGMServer ${QT_LIBRARIES})
target_link_libraries(Test_EGMServer ${EGMServer_LIBRARIES})
