

#include <iostream>
#include <string>


void reference(std::string & str) {
    std::cout<<"lvalue: "<<std::endl;
}

void reference(std::string && str) {
    std::cout<<"rvalue: "<<std::endl;
}

int main(){
    std::string lv1 = "string";         // lv1 is a lvalue
    // std::string&& r1 = lv1;          // illegal, rvalue cant ref to lvalue
    std::string && rv1 = std::move(lv1);
    std::cout<<rv1<< std::endl;

    const std::string& lv2 = lv1 + lv1;

    // lv2 += "test";                   // illegal, const ref can't be modified
    std::cout << lv2 << std::endl;
    std::string && rv2 = lv1 + lv2;
    rv2 += "string";                    // legal , non-const ref can be modified

    std::cout << rv2 << std::endl;

    reference(rv2);

    return 0;

}