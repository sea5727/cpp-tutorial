#include <iostream>
#include <thread>
#include <unistd.h>
#include <functional>
#include <sys/socket.h>


#define LESS_THAN_RANGE(value, min, faillog) if(LessThanRange(value, min)) return -1;
#define OUT_OF_RANGE(value, min, max, faillog) if(OutOfRange(value, min, max)) return -1;
#define IS_NULL(ptr, faillog) if(IsNull(ptr)) return -1;

#define DEFER(name, call) Defer name{[=]{call}};

class Defer{
public:
    std::function<void()> & callback;
    Defer(std::function<void()> && callback)
        : callback{callback} { }
    ~Defer() {
        callback();
    }
};


template<typename... Args>
bool all(Args... args) { return (... && args); }

template<typename... Args>
bool any(Args... args) { return (... || args); }

template<typename... Args>
bool none(Args... args) { return not(... || args); }
class TestClass{
public:
    TestClass(){
        std::cout << "TestClass Created" << std::endl;
    }
    ~TestClass() noexcept(false) {
        std::cout << "TestClass Deleted" << std::endl;
    }
};


int create_socket(){
    auto fd = socket(AF_INET, SOCK_STREAM, 0);
    if(fd == -1){
        std::cerr << "socket create fail.." << std::endl;
        exit(0);
    }

    bool testf = true;

    Defer defer0{[&]{
        std::cout << "testf : " << testf << std::endl;
        if(testf)
            close(fd);
    }};
    // DEFER( ALWAYS_CLOSE_SOCKET, close(fd); );

    return 0;
}


template<typename Args>
bool GreaterThanRange(Args value, Args max){
    return value > max;
}
template<typename Args>
bool LessThanRange(Args value, Args min){
    return value < min;
}

template<typename Args, typename Ty>
bool OutOfRange(Args value, Ty min, Ty max){
    return value < min || value > max;
}

template<typename Args>
bool WithinRange(Args value, Args min, Args max){
    return value >= min && value <= max;
}

template<typename Ty>
bool IsNull(Ty p){
    return p == nullptr;
}




int ErrorHandling(TestClass * testclass, int fd, int index, int size){


    IS_NULL(testclass, "error testclass : invalid pointer")
    LESS_THAN_RANGE(fd, 0, "error fd : invalid range")
    OUT_OF_RANGE(index, 0, 1000, "error index: invalid range")
    OUT_OF_RANGE(size, 0, 1000, "error size : invalid range")


}

int main(int argc, char * argv[]){
    create_socket();
    ErrorHandling(nullptr, -1, 1000, -1);

    while(1){
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
}