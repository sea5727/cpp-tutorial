
#include <iostream>
#include "range.hpp"

int main(int argc, char * argv[]){
    for (int i : range(1, 4))
        std::cout << i << '\n';
    for (double i : range(7.5, 10.5))
        std::cout << i << '\n';
    return 0;
}
