#include <iostream>
#include <thread>
#include <vector>
#include <atomic>

int main(int argc, char * argv[]){

    std::vector<std::thread> workers;

    int arrays[10000 * 10] = {0, };
    std::atomic<int> index(0);

    
    for(int i = 0 ; i < 10 ; i++){
        workers.emplace_back([&index, &arrays]{
            for(int i = 0 ; i < 10000; i++){
                arrays[index++] = 1000;
            }
        });
    }

    for(auto & worker : workers){
        worker.join();
    }

    int i = 0;
    for(i = 0 ; i < 10000 * 10; ++i){
        if(arrays[i] != 1000) {
            printf("not atomic\n");
            break;
        }
    }
    if(i == 10000 * 10) printf("atomic!\n");
    
    std::vector<std::thread> workers2;

    int arrays2[10000 * 10] = {0, };
    int normal = 0;

    for(int i = 0 ; i < 10 ; i++){
        workers2.emplace_back([&normal, &arrays2]{
            for(int i = 0 ; i < 10000; i++){
                arrays2[normal++] = 1000;
            }
        });
    }

    for(auto & worker : workers2){
        worker.join();
    }

    for(i = 0 ; i < 10000 * 10; ++i){
        if(arrays2[i] != 1000) {
            printf("not atomic\n");
            break;
        }
    }
    if(i == 10000 * 10) printf("atomic!\n");
    return 0;
}