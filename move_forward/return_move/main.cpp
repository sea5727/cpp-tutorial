#include <iostream>
#include <thread>

#include <algorithm>

class Bar{
public:
    std::string name;
    Bar(const std::string &name) : name{name}
    {
        std::cout << "This is Bar Default Constructor" << std::endl;
    }
    Bar(const Bar &copy)
        : name(copy.name)
    {
        std::cout << "This is Bar copy Constructor" << std::endl;
    }
    Bar(Bar &&move)
        : name(std::move(move.name))
    {
        std::cout << "This is Bar move Constructor" << std::endl;
    }
    ~Bar()
    {
        std::cout << "This is Bar destructor" << std::endl;
    }
};
class MyClass
{
public:
    std::string name;
    Bar bar;
    MyClass(const std::string &name) : name{name}, bar{name}
    {
        std::cout << "This is MyClass Default Constructor" << std::endl;
    }
    MyClass(const MyClass &copy)
        : name(copy.name), bar{copy.name}
    {
        std::cout << "This is MyClass copy Constructor" << std::endl;
    }
    MyClass(MyClass &&move)
        : name(std::move(move.name)), bar{name}
    {
        std::cout << "This is MyClass move Constructor" << std::endl;
    }
    ~MyClass()
    {
        std::cout << "This is MyClass destructor" << std::endl;
    }
    void
    print()
    {
        std::cout << "Hello " << name << std::endl;
    }

    MyClass & getMyClass1()  { return *this; }
    MyClass const & getMyClass2()  { return *this; }
    const MyClass & getMyClass3()  { return *this; }
    MyClass getMyClass4() & { return *this; }
    MyClass getMyClass5() const & { return *this; }
    MyClass getMyClass6() && { return *this; }
    MyClass getMyClass7() const && { return *this; }

};


int main() {
    MyClass a("a");
    std::cout << "========== 1 ===========" << std::endl;
    MyClass a1 = a.getMyClass1();
    std::cout << "========== 2 ===========" << std::endl;
    MyClass a2 = a.getMyClass2();
    std::cout << "========== 3 ===========" << std::endl;
    MyClass a3 = a.getMyClass3();
    std::cout << "========== 4 ===========" << std::endl;
    MyClass a4 = a.getMyClass4();
    std::cout << "========== 5 ===========" << std::endl;
    MyClass a5 = a.getMyClass5();
    std::cout << "========== 6 ===========" << std::endl;
    // auto a6 = a.getMyClass6();
    // auto a7 = a.getMyClass7();

    while(1){
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
}

