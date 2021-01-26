#include <iostream>
#include <thread>
#include <vector>
#include <atomic>

int main(int argc, char * argv[]){

    std::vector<std::thread> workers;

    std::atomic<int> index(0);

    
    for(int i = 0 ; i < 10 ; i++){
        workers.emplace_back([&index]{
            for(int i = 0 ; i < 10000; i++){
                index++;
            }
        });
    }

    for(auto & worker : workers){
        worker.join();
    }

    printf("index:%d\n", index.load());
    
    std::vector<std::thread> workers2;

    int normal = 0;

    for(int i = 0 ; i < 10 ; i++){
        workers2.emplace_back([&normal]{
            for(int i = 0 ; i < 10000; i++){
                normal++;
            }
        });
    }

    for(auto & worker : workers2){
        worker.join();
    }

    printf("index:%d\n", normal);
    return 0;
}