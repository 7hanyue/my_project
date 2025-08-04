#查找库（modbus 库）的模块说明注释

# - try to find modbus library

# modbus_FOUND - 标记系统是否找到 modbus 库（找到为 TRUE，否则 FALSE）
# modbus_INCLUDE_DIRS -存储 modbus 库的头文件目录（编译时需包含，让代码找到 #include 的头文件）
#modbus_LIBRARY_DIRS -存储 modbus 库的库文件目录（链接时需用，让编译器找到 .so/.lib 等）
#modbus_LIBRARIES -存储实际要链接的 modbus 库文件名（如 libmodbus.so 或 modbus.lib ）


message(STATUS "------------Findmodbus.cmake-------") 

unset(modbus_FOUND)

set(modbus_DIR ${LS_ROOT}/3rdparty/libmodbus)
set(modbus_LIBRARY_DIR ${modbus_DIR}/release/lib)

find_path(modbus_INCLUDE_DIRS  # 变量名：找到头文件路径后，存到这个变量里  
    NAMES modbus.h       # 要找的头文件名（支持通配符，这里明确找 modbus.h）  
    PATHS ${modbus_DIR}/include  # 查找路径：去 ${modbus_DIR}/include 目录里找  
    NO_SYSTEM_ENVIRONMENT_PATH  # 不走系统环境变量路径，只搜上面指定的 PATHS
    )

find_library(modbus_LIBRARIES 
            modbus #要找的库名
            PATHS ${modbus_LIBRARY_DIRS} # 查找路径：
            NO_SYSTEM_ENVIRONMENT_PATH # 不走系统环境变量路径，只搜上面指定的 PATHS
            )

if (modbus_INCLUDE_DIRS AND modbus_LIBRARIES)
    set(modbus_FOUND TRUE)
    message(STATUS "Find modbus: ${modbus_LIBRARIES}") 
endif(modbus_INCLUDE_DIRS AND modbus_LIBRARIES)  #括号里的内容是对前面 if 条件的 “重复”，用于增强代码可读性



if(NOT TARGET modbus) 
    add_library(modbus SHARED IMPORTED)  #创建一个导入型共享库目标（SHARED IMPORTED），名字叫 modbus
    set_target_properties(modbus PROPERTIES INTERFACE_INCLUDE_DIRECTORIES ${modbus_INCLUDE_DIRS})  #当其他目标链接到当前目标时，需要包含的头文件路径”
    #INTERFACE_INCLUDE_DIRECTORIES：这是 CMake 的一个 “接口属性”，用于存储头文件搜索路径

    if(EXISTS "${modbus_LIBRARIES}")
        set_target_properties(modbus PROPERTIES IMPORTED_LOCATION ${modbus_LIBRARIES})   #设置库文件的实际路径（运行时加载用，比如 .so/.dll ）
        set_target_properties(modbus PROPERTIES IMPORTED_IMPLIB ${modbus_LIBRARIES}) #设置导入库路径(主要 Windows 下用）（比如 .lib 文件，编译链接时用 ）。
    endif()

endif()

