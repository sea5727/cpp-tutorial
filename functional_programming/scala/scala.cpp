
#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
#include "scala.hpp"

int main(int argc, char * argv[]){
    auto&& g = fun::groupBy(std::vector<int>{1, 2, 3, 4, 5},
    [](auto e) { return (e % 2 == 0) ? "Even" : "Odd"; });
    
    // vector/pair에 대한 ostream << 출력을 오버라이딩 했다고 가정
    for (auto&& e : g){
        std::cout << "first : " << e.first << ", second : " << e.second.size() << std::endl;
    }


    auto f = fun::map(fun::groupBy(std::string("Hello"), [](auto e) { return e; }),
                [](auto p) { return std::make_pair(p.first, p.second.size()); });
    for (auto e : f){
        std::cout << "first : " << e.first << ", second : " << e.second << std::endl;
    }
    // std::cout << e << std::endl;
    

    std::vector<int> nums{ 1,2,3,4 }; 
    std::vector<int> map_example; 
    std::vector<int> filter_example; 
    std::transform(nums.begin(), nums.end(), std::back_inserter(map_example), [](const auto& x) {return x * x; }); 
    std::copy_if(nums.begin(), nums.end(), std::back_inserter(filter_example), [](const auto& x) {return x % 2 == 0; }); 
    auto reduce_example = std::accumulate(nums.begin(), nums.end(), 1, [](const auto& x,const auto& y) {return x * y; });

    

    std::cout << "map_example : " << std::endl;
    for(auto & m : map_example){
        std::cout << m << ", ";
    
    } std::cout << std::endl;

    std::cout << "filter_example : " << std::endl;
    for(auto & m : filter_example){
        std::cout << m << ", ";
    
    } std::cout << std::endl;

    std::cout << "reduce_example : " << std::endl;
    std::cout << reduce_example << std::endl;
    


using namespace std;

    vector<int> v1 = { 1, 2, 4, 5, 3, 6, 8, 5, 7, 9 }; 
    vector<int> v2 = { 1, 2, 4, 5, 3, 6, 8, 5, 7, 9 }; 
    auto lambda = [](int x) { return x % 2 == 1; }; 
    auto p = partition(v1.begin(), v1.end(), lambda); 
    auto s = stable_partition(v2.begin(), v2.end(), lambda); 
    for (auto i = v1.begin(); i < v1.end(); i++) 
    { if (p == i) { cout << endl; } cout << *i << "\t"; } cout << endl; 
    for (auto i = v2.begin(); i < v2.end(); i++) 
    { if (s == i) { cout << endl; } cout << *i << "\t";  } 
    cout << endl; 
    cout << "is partitioned?: " << is_partitioned(v1.begin(), v1.end(), lambda) << endl; 
    cout << "is partitioned?: " << is_partitioned(v2.begin(), v2.end(), lambda) << endl;

    
    return 0;
}
