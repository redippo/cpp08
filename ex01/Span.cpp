#include "Span.hpp"
#include <algorithm>
#include <iterator>

Span::Span() : size(0)
{
};

Span::Span(unsigned int size) : size(size)
{

}

Span::Span(const  Span &other) : size(other.size), numbers(other.numbers)
{
}

Span &Span::operator=(const Span &other)
{
    if (this != &other)
    {
        size = other.size;
        numbers = other.numbers;
    }
    return (*this);
}

Span::~Span(){};

void    Span::addNumber(int number)
{
    if (numbers.size() >= size)
        throw FullException();//throw
    numbers.push_back(number);
};

const char *Span::FullException::what() const throw()
{
    return "span is full";
}

unsigned int Span::longestSpan() const
{
    if (numbers.size() < 2)
        throw noSpanException();
    int min = *std::min_element(numbers.begin(), numbers.end());
    int max = *std::max_element(numbers.begin(), numbers.end());
    return static_cast<unsigned int>(max) - static_cast<unsigned int>(min);
}

unsigned int Span::shortestSpan()const 
{
    if (numbers.size() < 2)
        throw noSpanException();
    std::vector <int> sorted(numbers);
    std::sort(sorted.begin(), sorted.end());
    size_t i = 2;
    unsigned int shortest = static_cast<unsigned int>(sorted[1]) - static_cast<unsigned int>(sorted[0]);
    while (i < numbers.size())
    {
        unsigned int diff = static_cast<unsigned int>(sorted[i]) - static_cast<unsigned int> (sorted[i - 1]);
        if (diff < shortest)
            shortest = diff;
        i++;
    }
    return (shortest);
}

const char *Span::noSpanException::what() const throw()
{
    return "not enough numbers to find a span";
}
