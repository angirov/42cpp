template<typename T>
void iter(T* array, int arrlen, void (* fun)(T const &))
{
    for (int i = 0; i < arrlen; ++i)
    {
        fun(array[i]);
    }
};

template<typename T>
void iter(T* array, int arrlen, void (* fun)(T &))
{
    for (int i = 0; i < arrlen; ++i)
    {
        fun(array[i]);
    }
};