#include <cstdio>
#include <cstdint>
//因为是外部库，直接尖括号提示错误，所以要添加包含目录
#include <slib.h>
#include <dynlib.h>
int main()
{
    dynlib::dynlib_impl();
    slib::slib_impl();
    return 0;
}