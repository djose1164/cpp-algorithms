#include "vector.h"

#include <iostream>

int main()
{
    Vector<int> vector;
    for (int i{0}; i < 20; ++i)
        vector.push_back(i);
    
    vector.pop_back();
    vector.pop_back();

    for (const auto num : vector)
        std::cout << num << " ";
    std::cout << std::endl;

    return 0;
}