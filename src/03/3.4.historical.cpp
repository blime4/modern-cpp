


#include <iostream>

int main(){
    // int &a = std::move(1);           // illegal , non-const lvalue reference cannot ref rvalue
    const int & b = std::move(1);       // legal , const lvalue reference can
    std::cout << b << std::endl;
}