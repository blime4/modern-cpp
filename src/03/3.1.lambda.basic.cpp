

#include <iostream>
#include <memory>   // std::make_unique
#include <utility>  // std::move


// 与参数传值类似，值捕获的前提是变量可以拷贝，不同之处则在于，被捕获的变量在 Lambda 表达式被创建时拷贝， 而非调用时才拷贝：

void lambda_value_capture(){
    int value = 1;
    auto copy_value = [value]{
        return value;
    };
    value = 100;
    auto stored_value = copy_value();
    std::cout<<"stored_value = "<<stored_value<<std::endl;
    // 这时, stored_value == 1, 而 value == 100.
    // 因为 copy_value 在创建时就保存了一份 value 的拷贝
}


void lambda_reference_capture() {
    int value = 1;
    auto copy_value = [&value]{
        return value;
    };
    value = 100;
    auto stored_value = copy_value();
    std::cout<<"stored_value = "<<stored_value<<std::endl;
    // At this moment, stored_value == 100, value == 100.
    // Because copy_value stores reference
}

void lambda_expression_captrue(){
    auto important = std::make_unique<int>(1);
    auto add = [v1 = 1, v2 = std::move(important)](int x, int y) -> int {
        return x+ y+v1+(*v2);
    };
    std::cout << add(3,4) << std::endl;

}

void lambda_generic(){
    auto generic = [](auto x, auto y){
        return x + y;
    };
    std::cout<<generic(1,2)<< std::endl;
    std::cout <<generic(2.1,3.2)<< std::endl;
}


int main(){
    lambda_value_capture();
    lambda_reference_capture();
    lambda_expression_captrue();
    lambda_generic();
    return 0;
}
