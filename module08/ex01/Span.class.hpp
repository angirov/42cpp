#ifndef SPAN_CLASS_HPP
# define SPAN_CLASS_HPP

# include <cmath>
# include <set>
# include <algorithm>

class Span {
private:
    Span();

    size_t max;
    std::multiset<int> numbers;
public:
    Span(size_t max);
    Span(Span const &other);
    virtual ~Span();

    class FullSpanException: public std::exception {
        virtual const char* what() const throw();
    };
    class NotEnoughNumbersException: public std::exception {
        virtual const char* what() const throw();
    };

    Span &operator=(Span const &other);

    void addNumber(int number);
    template<typename InputIterator>
    void addNumber(InputIterator begin, InputIterator end);

    size_t shortestSpan(void) const;
    size_t longestSpan(void) const;
};

template<typename InputIterator>
void Span::addNumber(InputIterator begin, InputIterator end) {
    if (std::distance(begin, end) + this->numbers.size() > this->max)
        throw FullSpanException();
    this->numbers.insert(begin, end);
}

#endif
