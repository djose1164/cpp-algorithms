#include "intSLList.h"

#include <iostream>

int main(int argc, char const *argv[])
{
    auto list = IntSLList();
    for (size_t i{0}; i < 15; ++i)
        list.add_to_tail(i);
    
    list.delete_node(5);
    list.delete_node(2);
    
    /*for (size_t i{0}; i < 14; ++i)
        std::cout << list.delete_from_tail() << " ";
    std::cout << std::endl;*/

    if (list.is_empty())
        std::cout << "List is empty; consider adding some data!\n";
    else
        std::cout << "List has data. Work on it!\n";
    
    if (list.is_in_list(3))
        std::cout << "List has it.\n";
    else
        std::cout << "List doesn't have it.\n";
    return 0;
}
