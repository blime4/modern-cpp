
#include <iostream>
#include <stddef.h>

struct Storage {
    char      a;
    int       b;
    double    c;
    long long d;
};

struct alignas(max_align_t) AlignasStorage {
    char      a;
    int       b;
    double    c;
    long long d;
};

int main() {
    std::cout << alignof(Storage) << std::endl;
    std::cout << alignof(AlignasStorage) << std::endl;
    return 0;
}