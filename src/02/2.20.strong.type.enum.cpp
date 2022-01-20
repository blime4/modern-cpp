

#include <iostream>
#include <type_traits>

template <typename T>
std::ostream& operator<<(typename std::enable_if_t<std::is_enum_v<T>, std::ostream> &stream, const T &e){
    return stream << static_cast<typename std::underlying_type_t<T>>(e);
}

enum Left{
    left_value1 = 1,
    left_value2
};

enum Right{
    right_value1 = 1,
    right_value2
};

enum class new_enum : unsigned int {
    value1,
    value2,
    value3 = 100,
    value4 = 100
 };

int main(){
    // if(Left::left_value1 == Right::right_value2){
    if(left_value1 == right_value2){
        std::cout<< "Left::value1 == Right::value2"<<std::endl;
    }

    // 这样定义的枚举实现了类型安全，首先他不能够被隐式的转换为整数，同时也不能够将其与整数数字进行比较，

    // compile error
    // if(new_enum::value1 == 1) {
    //     std::cout << "true!" << std::endl;
    // }

    //更不可能对不同的枚举类型的枚举值进行比较。但相同枚举值之间如果指定的值相同，那么可以进行比较：
    if(new_enum::value3 ==new_enum::value4){
        std::cout<<"new_enum::value3 == new_enum::value4" <<std::endl;
    }

    std::cout<< new_enum::value3 <<std::endl;

    std::cout<<"--------------------------------"<<std::endl;
    std::cout<< Left::left_value2 <<std::endl;

    return 0;
}
