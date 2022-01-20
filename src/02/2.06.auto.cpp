


#include <initializer_list>
#include <vector>
#include <iostream>

class MagicFoo{
public:
    std::vector<int> vec;
    MagicFoo(std::initializer_list<int> list){
        for(auto it = list.begin(); it != list.end(); ++it){
            vec.push_back(*it);
        }
    }
};


// support in c++20
int add(auto x, auto y) {
    return x + y;
}

int main() {

    MagicFoo magicFoo{1,2,3,4,5,6,7};
    std::cout<<"magicFoo: ";
    for(auto it = magicFoo.vec.begin(); it != magicFoo.vec.end(); ++it){
        std::cout<<*it<<", ";
    }
    std::cout<<std::endl;

    auto i = 5;
    auto j = 6;
    std::cout<<add(i, j)<<std::endl;

    auto arr = new auto(10);    // type int*
    // auto auto_arr2[10] = {arr}       // invalid : auto 还不能用于推导数组类型


    return 0;

}