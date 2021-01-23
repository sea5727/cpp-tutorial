#include <iostream>
#include <thread>
#include <vector>

int main(int argc, char * argv[]){
    auto thr = std::thread([]{
        printf("Working\n");
        std::this_thread::sleep_for(std::chrono::seconds(5));
    });

    std::cout << "thread id : " << thr.get_id() << std::endl;
    std::cout << thr.hardware_concurrency() << std::endl;
    thr.native_handle();
    // thr.swap();

    // std::this_thread::yield();
    std::this_thread::sleep_for(std::chrono::seconds(1));
    return 0;
}