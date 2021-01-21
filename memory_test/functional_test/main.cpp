#include <iostream>
#include <thread>
#include <functional>

class MyClass{
    std::string name = "myclassname";
public:
MyClass(){
    std::cout << "MyClass Default Constructor" << std::endl;
}
MyClass(const MyClass & copy){
    std::cout << "MyClass Copy Constructor" << std::endl;
}
MyClass(MyClass && move){
    std::cout << "MyClass Move Constructor" << std::endl;
}
~MyClass(){
    std::cout << "MyClass Destructor" << std::endl;
}
void testfunction(){
    std::cout << "start testfunction" << name << std::endl;
}

void addEvent(std::array<std::function<void()>, 1000> & arr){
    std::function<void()> f = std::bind(&MyClass::testfunction, this);
    arr[0] = f;
}
};

void add(std::array<std::function<void()>, 1000> & arr){
    auto a = MyClass{};
    a.testfunction();
    std::cout << "class:" << (void*)&a << std::endl;
    a.addEvent(arr);
}

void add2(std::array<std::function<void()>, 1000> & arr){
    auto a = std::make_shared<MyClass>();
    arr[0] = [a](){
        a->testfunction();
    };
}

int main(int argc, char * argv[]){
    std::cout << "memory test" << std::endl;

    std::array<std::function<void()>, 1000> arr;

    
    add2(arr);
    int a = 100;
    int b = 100;
    int c = 100;
    
    int d = 100;
    int e = 100;
    int f = 100;
    int g = 100;


    std::cout << "a:" << (void*)&a << std::endl;
    std::cout << "b:" << (void*)&b << std::endl;
    std::cout << "c:" << (void*)&c << std::endl;
    std::cout << "d:" << (void*)&d << std::endl;
    std::cout << "e:" << (void*)&e << std::endl;
    std::cout << "f:" << (void*)&f << std::endl;
    std::cout << "g:" << (void*)&g << std::endl;

    std::cout << a << b << c << d << e << f << g ;

    if(arr[0]){
        arr[0]();    
    }
    if(arr[1]){
        std::cout << "arr[1] callable" << std::endl; 
    }


    arr[0] = nullptr;

    if(arr[0]){
        std::cout << "arr[0] callable" << std::endl; 
    }


    while(1){
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }

    return 0;
} 