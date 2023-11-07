#ifndef ARRAY_CLASS_HPP
# define ARRAY_CLASS_HPP

# include <exception>
# include <string>

template <typename T>
class Array {
public:
    Array();
    Array(unsigned int n);
    Array(Array const &other);
    ~Array();

    Array &operator=(Array const &other);
    T &operator[](unsigned int const index) const;

    unsigned int size() const;

    class OutOfBoundsEcxeption : public std::exception {
    public:
        virtual const char *what() const throw()
        {
            return "### Index out of bound";
        }
    };

private:
    T *array;
    unsigned int length;
};

template <typename T>
Array<T>::Array() : array(NULL), length(0)
{
    std::cout << "Array constructor is called" << std::endl;
}

template <typename T>
Array<T>::Array(unsigned int n) : array(new T[n]), length(n)
{
    std::cout << "n-Array constructor is called" << std::endl;
}

template <typename T>
Array<T>::Array(Array const &other) : array(NULL), length(0)
{
    std::cout << "Copy Array constructor is called" << std::endl;
    *this = other;
}

template <typename T>
Array<T>::~Array()
{
    std::cout << "Array destructor is called" << std::endl;
    delete [] array;
}

template<typename T>
unsigned int Array<T>::size() const
{
    return length;
}

template<typename T>
Array<T> &Array<T>::operator=(Array const &other)
{
    std::cout << "Assignment operator is called" << std::endl;
    if (this == &other)
        return *this;
    delete [] array;
    length = other.length;
    array = new T[length];
    for (unsigned int i = 0; i < length; ++i)
    {
        array[i] = other.array[i];
    }
    return *this;
}

template<typename T>
T & Array<T>::operator[](unsigned int const i) const
{
    if (i >= length)
    {
        throw OutOfBoundsEcxeption();
    }
    return array[i];
}

#endif