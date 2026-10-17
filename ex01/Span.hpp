#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>

class Span
{
    private:
        unsigned int size;
        std::vector<int>    numbers;
    public:
        class FullException : public std::exception
        {
            public:
                virtual const char *what() throw();
        };
        Span();
        Span(unsigned int size);
        Span(const  Span &other);
        Span &operator=(const Span &other); 
        ~Span();

        void    addNumber(int number);
};

#endif