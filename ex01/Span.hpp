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
                virtual const char *what() const throw();
        };
        Span();
        Span(unsigned int size);
        Span(const  Span &other);
        Span &operator=(const Span &other); 
        ~Span();

        void    addNumber(int number);
        unsigned int shortestSpan() const;
        unsigned int longestSpan() const;
        template <typename Iterator>
        void addNumbers(Iterator begin, Iterator end)
        {
            size_t count = static_cast<size_t>(std::distance(begin, end));
            if (numbers.size() + count > size)
            throw FullException();
            numbers.insert(numbers.end(), begin, end);
        }
        class noSpanException : std::exception
        {
            public:
                virtual const char *what() const throw();
        };
};

#endif