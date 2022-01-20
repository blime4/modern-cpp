


#include <iostream>
#include <vector>
#include <string>


// sizeof...
template<typename... Ts>
void magic(Ts... args){
    std::cout<<sizeof... (args) << std::endl;
}

// 1. recursive parameter unpack
// 递归是非常容易想到的一种手段，也是最经典的处理方法。
// 这种方法不断递归地向函数传递模板参数，进而达到递归遍历所有模板参数的目的：
template<typename T0>
void printf1(T0 value){
    std::cout<<value<<std::endl;
}
template<typename T, typename... Ts>
void printf1(T value, Ts... args){
    std::cout<<value<<std::endl;
    printf1(args...);
}

// 2. variadic template parameter unfold
// 在 C++17 中增加了变参模板展开的支持，于是你可以在一个函数中完成 printf 的编写：
template<typename T0, typename... T>
void printf2(T0 t0, T... t){
    std::cout<<t0<<std::endl;
    if constexpr (sizeof... (t) > 0) printf2(t...);
}


// 3. parameter unpack using initializer_list
template<typename T, typename... Ts>
auto printf3(T value, Ts... args){
    std::cout<<value<<std::endl;
    (void) std::initializer_list<T>{([&args]{
        std::cout<<args<<std::endl;
    }(),value)...};
}


int main(){
    magic();
    magic(1);
    magic(1,"");

    std::cout<<"--------------------------------"<<std::endl;
    
    printf1(1,2,"123",1.1);
    printf2(1,2,"123",1.1);
    printf3(1,2,"123",1.1);

    return 0;
}