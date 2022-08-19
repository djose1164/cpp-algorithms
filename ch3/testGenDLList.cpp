#include "genDLList.h"
#include <iostream>

int main(int argc, char const *argv[])
{
    GenDLList<int> list;
    for (size_t i{0}; i < 10; ++i)
        list.add_to_head(i);

    for (size_t i{10}; i < 20; ++i)
        list.add_to_tail(i);

    if (list.is_in_list(10))
        std::cout << "I have it!\n";
    else
        std::cout << "Not in.\n";

    while (!list.is_empty())
        std::cout << list.delete_from_tail() << " ";
    std::cout << std::endl;

    return 0;
}
