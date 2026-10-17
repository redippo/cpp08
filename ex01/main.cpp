#include "Span.hpp"
#include <iostream>
#include <exception>
#include <list>

int main()
{
    Span S(10); 
    int i = 0;
    try
    {
        while (i < 11)
        {
            S.addNumber(i);
            i++;
        }
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
    Span sp(5);
    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);
    std::cout << sp.shortestSpan() << std::endl;
    std::cout << sp.longestSpan() << std::endl;


    std::vector<int> v;
    for (i = 0; i < 20000; ++i)
        v.push_back(rand());

    Span big(20000);
    big.addNumbers(v.begin(), v.end());
    std::cout << big.shortestSpan() << " " << big.longestSpan() << std::endl;

    // 3. range from a list
    std::list<int> l(v.begin(), v.begin() + 100);
    Span fromList(100);
    fromList.addNumbers(l.begin(), l.end());

    // 4. range too big -> FullException
    try
    {
        Span small(10);
        small.addNumbers(v.begin(), v.end()); 
    }
    catch(std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
}