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

    
