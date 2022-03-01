#这个添加不添加不重要
project(samples)
#一个project可以有多个target 每个target可以对应一个应用程序 也可以是一个静态库或动态库
#没有源文件 添加自己目录
#添加静态库
#因为helloworld依赖slib 所以slib放到前面
add_subdirectory(dynlib)
add_subdirectory(slib)

add_subdirectory(helloworld)

