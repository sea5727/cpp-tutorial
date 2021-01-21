#include <iostream>

class MyClass
{
public:
    std::string name;
    MyClass(const std::string &name) : name{name}
    {
        std::cout << "This is Default Constructor" << std::endl;
    }
    MyClass(const MyClass &copy)
    {
        std::cout << "This is copy Constructor" << std::endl;
    }
    MyClass(MyClass &&move)
    {
        std::cout << "This is movec Constructor" << std::endl;
    }
    ~MyClass()
    {
        std::cout << "This is destructor" << std::endl;
    }
    void
    print()
    {
        std::cout << "Hello " << name << std::endl;
    }
};


void overloaded( int const &arg ) { std::cout << "by lvalue\n"; }
void overloaded( int && arg ) { std::cout << "by rvalue\n"; }
 
template< typename t >
/* "t &&" with "t" being template param is special, and  adjusts "t" to be
   (for example) "int &" or non-ref "int" so std::forward knows what to do. */
void forwarding( t && arg ) {
    std::cout << "via arg : " << " std::forward: ";
    overloaded( std::forward< t >( arg ) );
    std::cout << "via std::move: ";
    overloaded( std::move( arg ) ); // conceptually this would invalidate arg
    std::cout << "by simple passing: ";
    overloaded( arg );
}
 
void testfunc(const int & v){
    int t = v + 100;
}
int main() {
    std::cout << "initial caller passes rvalue:\n";
    forwarding( 5 );
    std::cout << "initial caller passes lvalue:\n";
    int x = 5;
    forwarding( x );


    int y = 100;
    testfunc(y);

}

