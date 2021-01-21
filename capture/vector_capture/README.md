

``` cpp
std::function<void()> a([test1]{
    std::cout << test1.a << std::endl;
});

```

```
==================================
MyClass copy Constructor a : 1
MyClass move Constructor a : 2
MyClass Destructor
2
2
==================================
```


```cpp
auto cb = std::function<void()> ([=]{
    std::cout << test1.a << std::endl;
});
cb();
std::cout << test1.a << std::endl;
```
```
==================================
MyClass copy Constructor a : 1
MyClass move Constructor a : 2
MyClass Destructor a : 1
2
0
==================================
```




```cpp
auto a = [test1]{
    std::cout << test1.a << std::endl;
};
a();
a();
```

```
==================================
MyClass copy Constructor a : 1
1
1
==================================
```
