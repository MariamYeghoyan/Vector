#include <iostream>
#include "vector.h"

int main() {
    Vector<int> v;
    v.push_back(10);
    v.push_back(50);
    std::cout << v[0] << ' ' << v[1] << std::endl; 
    v.push_front(100);
    std::cout << v[0] << ' ' << v[1] << ' ' << v[2] << std::endl; 
    Vector<int> v1 = v;
    std::cout << v1[0] << std::endl;
}