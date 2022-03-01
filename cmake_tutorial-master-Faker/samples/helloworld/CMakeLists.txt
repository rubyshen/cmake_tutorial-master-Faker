add_executable(helloworld)
#以前是在add_executable添加源文件 现在是用下行添加源文件
target_sources(helloworld
PRIVATE
#INTERFACE PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/helloworld.cpp #当前helloworld这个目录

)

#依赖哪个库 就调用哪个库的方法

target_link_libraries(helloworld
#因为这个静态库是私有的，不给别人共享，所以要private
PRIVATE
    dynlib
    slib
    #使用别的sdk时 可以用其debug和release版本 可以点vscode下边切换debug和release模式
    #$<$<CONFIG:Debug>:util_D>
    #$<$<CONFIG:Release>:util>

)

#以下解决方案不是最好的解决方案
#target_include_directories()
#应在相应的库目录下添加
#target_include_directories(slib
#INTERFACE
#    ${CMAKE_CURRENT_SOURCE_DIR}
#)



#private 本身我这个库 要用
#interface 给别的库用
#public = private + interface


#从别的地方找的资料
#以target_link_libraries(A B)命令为例，从理解的角度解释：

#PRIVATE 依赖项B仅链接到目标A，若有C链接了目标A，C不链接依赖项B
#INTERFACE 依赖项B并不链接到目标A，若有C链接了目标A，C会链接依赖项B
#PUBLIC 依赖项B链接到目标A，若有C链接了目标A，C也会链接依赖项B
#从使用的角度解释，若有C链接了目标A：

#如果依赖项B仅用于目标A的实现，且不在头文件中提供给C使用，使用 PRIVATE
#如果依赖项B不用于目标A的实现，仅在头文件中作为接口提供给C使用，使用 INTERFACE
#如果依赖项B不仅用于目标A的实现，而且在头文件提供给C使用，使用 PUBLIC
##


find_package(Vulkan REQUIRED)

if(Vulkan_FOUND)
    message("vulkan found! ${Vulkan_INCLUDE_DIRS} ${Vulkan_LIBRARIES}")
endif()