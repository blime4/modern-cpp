

#include <iostream>
#include <initializer_list>
#include <vector>

class Foo
{
public:
    int value_a;
    int value_b;
    Foo(int a, int b) : value_a(a), value_b(b) {}
};

class MagicFoo
{
public:
    std::vector<int> vec;
    MagicFoo(std::initializer_list<int> list)
    {
        for (std::initializer_list<int>::iterator it = list.begin(); it != list.end(); ++it)
        {
            vec.push_back(*it);
        }
    }
    void foo(std::initializer_list<int> list)
    {
        for (std::initializer_list<int>::iterator it = list.begin(); it != list.end(); ++it)
        {
            vec.push_back(*it);
        }
    }
};


int main(){
    // after c++11
    MagicFoo magicFoo = {1,2,3,4,5,6,7};
    magicFoo.foo({8,9,10,11,12,13,14});

    for(std::vector<int>::iterator it = magicFoo.vec.begin(); it != magicFoo.vec.end(); ++it){
        std::cout<<*it<<std::endl;
    }
    Foo foo2{3,4};
    std::cout << "foo2: " << foo2.value_a << ", " << foo2.value_b << std::endl;
}