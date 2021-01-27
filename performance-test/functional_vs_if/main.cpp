#include <benchmark/benchmark.h>
#include <iostream>
#include <functional>
#include <map>

int
DecodeTime(const char * timeformat){ // *ms / *s / number
    std::string time = timeformat;  


    static std::array<std::string, 2> 
        string_time = {"infinite", "immediate"};
    static std::array<int, 2>  
        string_time_result = {-1, 0};

    for(auto i = 0 ; i < string_time.size() ; ++i){
        if(time.compare(string_time[i]) == 0 ){
            return string_time_result[i];
        }
    }

    static std::function<int(int)> divide = 
        [] (int input){
            return input / 100;
        };
    static std::function<int(int)> mul = 
        [] (int input){
            return input * 10;
        };
    
    static constexpr unsigned int TIME_FORMAT_SIZE = 4;
    static std::array<std::string, TIME_FORMAT_SIZE> 
        secs = {"ms", "s", "MS", "S"};
    static std::array<std::function<int(int)>, TIME_FORMAT_SIZE + 1> 
        funcs = { divide, mul, divide, mul, divide};


    int i = 0;
    for(auto & sec : secs){
        auto found = time.find(sec);
        if(found != std::string::npos){
            break;
        }
            
        i += 1;
    }

    int integer = -1;
    try{
        
        integer = std::stoi(time);
        integer = funcs[i](integer);
    }
    catch(std::exception & err){
        // TODO invalid format 
    }

    return integer;

}

int
DecodeTime2(const char * timeformat){ // *ms / *s / number
    std::string time = timeformat;  
    if(time.compare("infinite") == 0)
        return -1;
    if(time.compare("immediate") == 0)
        return 0;

{
    int integer = -1;
    auto found = time.find("ms");
    if(found != std::string::npos){
        try{
            
            integer = std::stoi(time);
            integer = integer / 100;
            return integer;
        }
        catch(std::exception & err){
            return integer;
        }
    }
}


{
    int integer = -1;
    auto found = time.find("s");
    if(found != std::string::npos){
        try{
            
            integer = std::stoi(time);
            integer = integer * 10;
            return integer;
        }
        catch(std::exception & err){
            return integer;
        }
    }
}


{
    int integer = -1;
    auto found = time.find("MS");
    if(found != std::string::npos){
        try{
            
            integer = std::stoi(time);
            integer = integer / 100;
            return integer;
        }
        catch(std::exception & err){
            return integer;
        }
    }
}


{
    int integer = -1;
    auto found = time.find("S");
    if(found != std::string::npos){
        try{
            
            integer = std::stoi(time);
            integer = integer * 10;
            return integer;
        }
        catch(std::exception & err){
            return integer;
        }
    }
}

int integer = -1;
    try{
        integer = std::stoi(time);
        integer = integer / 100;
        return integer;
    }
    catch(std::exception & err){
        return integer;
    }


}


void SomeFunction(){
    std::cout << "SomeFunction" << std::endl;
}
static void BM_SomeFunction(benchmark::State& state) {
  // Perform setup here
  for (auto _ : state) {
    // This code gets timed
    DecodeTime("infinite");
    DecodeTime("immediate");
    DecodeTime("immediate");
    DecodeTime("infinite");
  }
}

static void BM_SomeFunction2(benchmark::State& state) {
  // Perform setup here
  for (auto _ : state) {
    // This code gets timed
    DecodeTime2("infinite");
    DecodeTime2("immediate");
    DecodeTime2("immediate");
    DecodeTime2("infinite");
  }
}


// Register the function as a benchmark
BENCHMARK(BM_SomeFunction);
// Run the benchmark

BENCHMARK(BM_SomeFunction2);

BENCHMARK_MAIN();
