#include "Span.hpp"

Span::Span() : size(0)
{
};

Span::Span(unsigned int size) : size(size)
{

}

Span::Span(const  Span &other)
{
    size = other.size;
    numbers = other.numbers;
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
        return throw FullException();//throw
    numbers.push_back(number);
};

const char *what() throw()
{
    return "span is full";
};