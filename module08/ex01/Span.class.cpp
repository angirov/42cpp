# include "Span.class.hpp"

Span::Span(unsigned int max): max(max) {}

Span::Span(Span const &other): max(other.max) {
    this->numbers.clear();
    this->numbers = other.numbers;
}

Span::~Span() {
    this->numbers.clear();
}


const char* Span::FullSpanException::what() const throw() {
    return "SpanException: Span is full.";
}

const char* Span::NotEnoughNumbersException::what() const throw() {
    return "SpanException: not enough numbers in this Span.";
}


Span & Span::operator=(Span const &other) {
    if (this == &other)
        return *this;
    this->max = other.max;
    this->numbers.clear();
    this->numbers = other.numbers;
    return *this;
}

void Span::addNumber(int number) {
    if (this->numbers.size() == this->max)
        throw FullSpanException();
    this->numbers.insert(number);
}

unsigned int Span::shortestSpan(void) const {
    if (this->numbers.size() <= 1)
        throw NotEnoughNumbersException();

    std::multiset<int>::iterator first = this->numbers.begin();
    std::multiset<int>::iterator second = ++this->numbers.begin();
    unsigned int minDiff = std::abs(*second++ - *first++);
    while (second != this->numbers.end()) {
        unsigned int diff = std::abs(*second - *first);
        if (diff < minDiff)
            minDiff = diff;
        first++;
        second++;
    }
    return minDiff;
}

unsigned int Span::longestSpan(void) const {
    if (this->numbers.size() <= 1)
        throw NotEnoughNumbersException();

    long max_el = *std::max_element(this->numbers.begin(), this->numbers.end());
    long min_el = *std::min_element(this->numbers.begin(), this->numbers.end());
    return (std::abs(max_el - min_el));
}
