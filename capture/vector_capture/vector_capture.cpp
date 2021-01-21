#include <iostream>
#include <vector>
#include <thread>
#include <string>
#include <functional>


class MyClass{
public:
    int a;
    std::string b;
    MyClass(int a, std::string b)
        : a(a)
        , b(b) {
        std::cout << "MyClass Default Constructor a : " << a << std::endl;
    }
    MyClass(const MyClass & copy) 
        : a(copy.a)
        , b(copy.b) {
        a += 1;
        std::cout << "MyClass copy Constructor a : " << a << std::endl;
    }
    MyClass(MyClass && move) 
        : a(move.a)
        , b(std::move(move.b)){
        a += 1;
        std::cout << "MyClass move Constructor a : " << a << std::endl;
    }
    ~MyClass() {
        std::cout << "MyClass Destructor a : " << a << std::endl;
    }
    void print(){
        std::cout << "a : " << a << ", b : " << b << std::endl;
    }
    void print2(){
        std::cout << "this is print2" << std::endl;
    }

};

void woker_start(std::vector<std::thread> & workers){

    std::vector<MyClass> container;
    container.emplace_back(100, "this is string");
    std::cout << "container.at(0).b:" << container.at(0).b << std::endl;

    workers.emplace_back([con = std::move(container)]{
        std::this_thread::sleep_for(std::chrono::seconds(1));    
        std::cout << "container.at(0).b:" << con.at(0).b << std::endl;
        
        while(1){
            std::this_thread::sleep_for(std::chrono::seconds(1));    
        }
    });
}

void param(MyClass test2){
    std::cout << test2.a << ", " << test2.b << std::endl;
}


class MoveTestClass{
public:
    std::function<void()> &&c;
    MoveTestClass(std::function<void()> && c)
        : c(std::move(c)) {
        std::cout << "MoveTestClass default constructor" << std::endl;
    }

};
int main(){

    MyClass test(0, "this is string");
    test.print();
    std::cout << "================================" << std::endl;
    // auto t = [=]{
    //     std::cout << test.a << std::endl;
    // };
    // std::cout << "================================" << std::endl;
    std::function<void()> a = [=]{
        std::cout << test.a << std::endl;
    };
    std::cout << "================================" << std::endl;
    test.print();

    while(1){
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
    return 0;
}