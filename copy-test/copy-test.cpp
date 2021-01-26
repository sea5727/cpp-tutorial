#include <iostream>
#include <thread>
#include <vector>
#include <atomic>
#include <functional>


class InnerClass{
public:
    InnerClass(){
        printf("InnerClass constructor\n");
    }
    InnerClass(const InnerClass & copy){
        printf("MyClass copy constructor\n");
    }
    InnerClass(InnerClass && move){
        printf("MyClass move constructor\n");
    }
    ~InnerClass(){
        printf("InnerClass destructor\n");
    }
};
class MyClass{
public:
    int a = 0;
    std::string b = "";
    std::function<void()> f;
    MyClass(){
        // printf("MyClass constructor\n");
    }
    MyClass(int a, const std::string & b)
        : a(a)
        , b(b) {
        printf("MyClass a with b constructor\n");
    }
    MyClass(const MyClass & copy){
        printf("MyClass copy constructor\n");
    }
    MyClass(MyClass && move){
        printf("MyClass move constructor\n");
    }
    ~MyClass(){
        printf("MyClass destructor\n");
    }
    MyClass& operator=(MyClass& ref)
    {
        a = ref.a;
        b = ref.b;
        return *this;
    }
};


 std::array<MyClass, 65000> arrays;

int main(int argc, char * argv[]){
   

    // std::this_thread::sleep_for(std::chrono::seconds(1));

    for(int i = 0; i < 65000 ; i++){
        arrays[i].a = i;
        arrays[i].b = std::string("this is ") + std::to_string(i);
        arrays[i].f = [=]{
            printf("Callback function i : %d\n", i);
        };
    }
    for(int i = 0 ; i < 65000 ; i++){
        arrays[i].f();
    }

    while(1){
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
    return 0;
}