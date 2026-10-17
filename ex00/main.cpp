#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include "easyfind.hpp"

int main()
{
    std::vector<int> v;
    for (int i = 0; i < 5; i++)
        v.push_back(i * 10);

    std::list<int> l(v.begin(), v.end());
    std::deque<int> d(v.begin(), v.end());

    try {
        std::cout << *easyfind(v, 20) << std::endl;   // found
        std::cout << *easyfind(l, 40) << std::endl;   // found
        std::cout << *easyfind(d, 99) << std::endl;   // throws
    }
    catch (std::exception &e) {
        std::cout << "Error: " << e.what() << std::endl;
    }
    return 0;
}