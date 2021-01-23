#include <iostream>
#include <thread>
#include <vector>

int main(int argc, char * argv[]){
    auto thr = std::thread([]{
        printf("Working\n");
        std::this_thread::sleep_for(std::chrono::seconds(5));
    });

    thr.detach();

    if(thr.joinable()){
        printf("joinable\n"); // no print
    }

    try{
        thr.join();
    }
    catch(std::exception & err){
        std::cout << err.what() << std::endl; // << Invalid argument
    }

    if(thr.joinable()){
        printf("joinable\n"); // no print
    }

    return 0;
}