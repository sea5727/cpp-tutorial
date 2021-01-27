#include <iostream>
#include <array>
#include <functional>
#include <stdlib.h>
#include <stdarg.h>

void test2(const char * fmt, va_list ap){
    std::function<void()> f = [=]{
        
        char buf[1024];
        vsprintf(buf, fmt, ap);
        printf("f start..buf:%s\n", buf);
    };
    f();
}


void test(const char * fmt, ...){
    va_list ap;
    va_start(ap, fmt);
    test2(fmt, ap);
    va_end(ap);
}

int main(int, char**) {
    test("%s %s %s", "HGET" , "KETS" , "TEST");

    std::cout << "Hello, world!\n";
    int n = 100;

    int a = 100;
    if(a = -1){
        printf("hello world\n");
    } else {
        printf("no hello world\n");
    }
}
