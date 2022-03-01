#以前cmake的写法
#add_library(slib STATIC
#    ${CMAKE_CURRENT_SOURCE_DIR}/slib.cpp
#)


add_library(slib STATIC)

target_sources(slib
PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/slib.cpp
    #静态库是为他人提供的三方库 所以要添加一个头文件
)
target_include_directories(slib
#谁依赖这个目录，那么这个目录就会被包含到相应目录下
INTERFACE

    ${CMAKE_CURRENT_SOURCE_DIR}

    
)


