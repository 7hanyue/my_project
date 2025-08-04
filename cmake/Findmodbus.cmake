#���ҿ⣨modbus �⣩��ģ��˵��ע��

# - try to find modbus library

# modbus_FOUND - ���ϵͳ�Ƿ��ҵ� modbus �⣨�ҵ�Ϊ TRUE������ FALSE��
# modbus_INCLUDE_DIRS -�洢 modbus ���ͷ�ļ�Ŀ¼������ʱ��������ô����ҵ� #include ��ͷ�ļ���
#modbus_LIBRARY_DIRS -�洢 modbus ��Ŀ��ļ�Ŀ¼������ʱ���ã��ñ������ҵ� .so/.lib �ȣ�
#modbus_LIBRARIES -�洢ʵ��Ҫ���ӵ� modbus ���ļ������� libmodbus.so �� modbus.lib ��


message(STATUS "------------Findmodbus.cmake-------") 

unset(modbus_FOUND)

set(modbus_DIR ${LS_ROOT}/3rdparty/libmodbus)
set(modbus_LIBRARY_DIRS ${modbus_DIR}/release/lib ${modbus_DIR}/release/bin)

find_path(modbus_INCLUDE_DIRS  # ���������ҵ�ͷ�ļ�·���󣬴浽���������  
    NAMES modbus.h       # Ҫ�ҵ�ͷ�ļ�����֧��ͨ�����������ȷ�� modbus.h��  
    PATHS ${modbus_DIR}/include  # ����·����ȥ ${modbus_DIR}/include Ŀ¼����  
    NO_SYSTEM_ENVIRONMENT_PATH  # ����ϵͳ��������·����ֻ������ָ���� PATHS
    )

find_library(modbus_LIBRARIES  #�ҵ����ļ���·�� / ���ƴ浽�������
            modbus #Ҫ�ҵĿ���
            PATHS ${modbus_LIBRARY_DIRS} # ����·����
            NO_SYSTEM_ENVIRONMENT_PATH # ����ϵͳ��������·����ֻ������ָ���� PATHS
            )

message(STATUS "Find modbus:modbus_INCLUDE_DIRS ${modbus_INCLUDE_DIRS}") 
message(STATUS "Find modbus:modbus_LIBRARIES ${modbus_LIBRARIES}") 

if (modbus_INCLUDE_DIRS AND modbus_LIBRARIES)
    set(modbus_FOUND TRUE)
    message(STATUS "Find modbus: ${modbus_LIBRARIES}") 
endif(modbus_INCLUDE_DIRS AND modbus_LIBRARIES)  #������������Ƕ�ǰ�� if ������ ���ظ�����������ǿ����ɶ���



if(NOT TARGET modbus) 
    add_library(modbus SHARED IMPORTED)  #����һ�������͹����Ŀ�꣨SHARED IMPORTED�������ֽ� modbus
    set_target_properties(modbus PROPERTIES INTERFACE_INCLUDE_DIRECTORIES ${modbus_INCLUDE_DIRS})  #������Ŀ�����ӵ���ǰĿ��ʱ����Ҫ������ͷ�ļ�·����
    #INTERFACE_INCLUDE_DIRECTORIES������ CMake ��һ�� ���ӿ����ԡ������ڴ洢ͷ�ļ�����·��

    if(EXISTS "${modbus_LIBRARIES}")
        set_target_properties(modbus PROPERTIES IMPORTED_LOCATION ${modbus_LIBRARIES})   #���ÿ��ļ���ʵ��·��������ʱ�����ã����� .so/.dll ��
        set_target_properties(modbus PROPERTIES IMPORTED_IMPLIB ${modbus_LIBRARIES}) #���õ����·��(��Ҫ Windows ���ã������� .lib �ļ�����������ʱ�� ����
    endif()

endif()

