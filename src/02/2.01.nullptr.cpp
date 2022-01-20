

#include<iostream>
#include<experimental/type_traits>

void foo(char *);
void foo(int);


int main(){
    if(std::experimental::is_same_v<decltype(NULL), decltype(0)>) std::cout << "NULL == 0" << std::endl;
    if(std::experimental::is_same_v<decltype(NULL), decltype((void*)0)>) std::cout << "NULL == (void*)0" << std::endl;
    if(std::experimental::is_same_v<decltype(NULL), std::nullptr_t>) std::cout << "NULL == nullptr" << std::endl;

    foo(0);         // will call foo(int);
    // foo(NULL);   // doesn't compile
    foo(nullptr);   // will call foo(char *);
    return 0;
}

void foo(char *){
    std::cout<<"foo(char*) is called"<<std::endl;
}

void foo(int i){
    std::cout<<"foo(int) is called"<<std::endl;
}