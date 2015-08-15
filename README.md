# callByName
A simple piece of code that allows to easily call functions by name.

Use
---

Just create your functions using the macro FUNCTION_CALL_BY_NAME(), like this,

```cpp
FUNCTION_CALL_BY_NAME(myFunction) {
    std::cout << "Hello, world!\n";
}
```
And call it using callFunctionByName(const std::string & name), like this,

```cpp
callFunctionByName("myFunction");
```

An example is included in the file test.cpp. It can be built with the makefile or issuing the command 
    g++ -std=c++11 -o test test.cpp callByName.cpp
To use it, type
    ./test FUNCTION_NAME
where function name is one of the functions defined in the file.

How does it work
----------------

A map (the STL container) called functionContainer stores objects derived from the class CallableByName and indexes those objects by their name. We can register the objects by using the function registerFunction that receives a string and a CallableByName object.

CallableByName is an abstract class that has a pure virtual method run. The particular implementations of run should hold a function that we would like to call through a string. We can call these methods, provided they were registered with registerFunction, using callFunctionByName which is basically,

```cpp
functionContainer.at(name)->run();
```

So, how do we automatically register the functions? The macro FUNCTION_CALL_BY_NAME creates a derived object of the class CallableByName defines run as the user implemented method and defines a constructor that register the function and its name using the operator #.


Warning
-------

When linking all the files, it is important to firstly list callByName.o in the linking command among all the other object files that register functions. The C++ standard does not say anything about the order that 
global objects are created in other in units, but doing so (at least in gcc) constructs functionContainer before trying to store a function on it. Otherwise, a segmentation fault will occur.
