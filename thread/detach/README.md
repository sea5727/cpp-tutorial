# Detach

detach : 스레드를 떼어낸다.   

detach를 호출하면 더이상 thr 객체에서 스레드를 컨트롤 할 수 없다.   

```cpp
auto thr = std::thread([]{
    printf("Working\n");
    std::this_thread::sleep_for(std::chrono::seconds(5));
});

thr.detach();

if(thr.joinable()){
    printf("joinable\n"); // no print
}

try{
    thr.join();
}
catch(std::exception & err){
    std::cout << err.what() << std::endl; // << Invalid argument
}

if(thr.joinable()){
    printf("joinable\n"); // no print
}

```
출력
``` 
Working
Invalid argument
```