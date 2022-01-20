

#include <iostream>
#include <vector>
#include <algorithm>

int main(){
    std::vector<int> vec{1,2,3,4};

    //after c++17, can be simplified by using `auto`
    const std::vector<int>::iterator itr = std::find(vec.begin(), vec.end(),2);
    // auto itr = std::find(vec.begin(), vec.end(),2);
    if(itr != vec.end()){
        *itr = 3;
    }

    // c++17
    if(const std::vector<int>::iterator itr = std::find(vec.begin(), vec.end(),3);
        itr != vec.end()){
            *itr = 4;    
    }

    for(auto itr = vec.begin(); itr != vec.end(); ++itr){
        std::cout<<*itr << std::endl;
    }

}