#include <iostream>
#include <thread>
#include <vector>
#include <atomic>

class TestClass{
public:
    std::atomic<int> index;
    int *arrays;
    TestClass(int * arr)
        : index(0),
        arrays(arr) {

    }
    void
    test(){
        int flag = 10000;
        int value = 0;
        bool result = false;
        for(int i = 0 ; i < 10000; i++){
            arrays[index++] = 10000;
            result = index.compare_exchange_strong(flag, value);
        }
    }
    void
    print(){
        printf("atomic:%d\n", index.load());
    }
};
int main(int argc, char * argv[]){

    std::vector<std::thread> workers;

    int arrays[10000 * 10] = {0, };
    TestClass test(arrays);

    int flag = 10000;
    int value = 0;
    bool result = false;
    for(int i = 0 ; i < 10 ; i++){
        workers.emplace_back([&test]{
            test.test();
        });
    }

    for(auto & worker : workers){
        worker.join();
    }

    test.print();

    return 0;
}