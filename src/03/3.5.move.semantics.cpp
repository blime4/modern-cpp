

#include <iostream>


class A{
public:
    int *ptr;
    A():ptr(new int(1)){
        std::cout<< "constructor  " << ptr << std::endl;
    }
    A(A& a) :ptr(new int(*a.ptr)){
        std::cout << "copy" << ptr << std::endl;
    }// meaningless object copy

    A(A&& a) :ptr(a.ptr){
        a.ptr = nullptr;
        std::cout<< "move" << ptr << std::endl;
    }
    ~A() {
        std::cout<<"destructor"<< std::endl;
        delete ptr;
    }
};

// 避免编译器优化
A return_rvalue(bool test) {
    A a,b;
    if(test) return a;          // equal to static_cast<A&&>(a);
    else return b;              // equal to static_cast<A&&>(b);
}

int main() {
    A obj = return_rvalue(false);
    std::cout << "obj:" << std::endl;
    std::cout << obj.ptr << std::endl;
    std::cout << *obj.ptr << std::endl;
    return 0;
}
