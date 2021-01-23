#include <iostream>
#include <thread>
#include <vector>

int main(int argc, char * argv[]){
    auto thr = std::thread([]{
        printf("Working\n");
        std::this_thread::sleep_for(std::chrono::seconds(5));
    });


    if(thr.joinable()){
        printf("joinable\n"); // print
    }

    thr.join();
    
    if(thr.joinable()){
        printf("joinable\n"); // not print
    }

    return 0;
}