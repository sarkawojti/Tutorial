
#include <iostream>

template<class T>
class Object
{
public:
    virtual T result() const = 0;
    virtual void operator()(const T& elem) = 0;
    virtual ~Object() = default;
};

template<class T>
class Sum : public Object<T>
{
private:
    T _result = 0;
public:
    void operator()(const T& elem) override
    {
        _result += elem;
    }
    T result() const override { return _result; }
};

template<class T>
class Multi : public Object<T>
{
private:
    T _result = 1;
public:
    void operator()(const T& elem) override
    {
        _result *= elem;
    }
    T result() const override { return _result; }
};

template<class T>
T func(const T* const _array, unsigned _size, Object<T>&& func_obj)
{
    std::cout << "Array: ";
    //T result = 0;
    for(auto i = _array; i != _array + _size; ++i)
    //for(unsigned i = 0; i < _size; ++i)
    {
        std::cout << *i << " ";
        //std::cout << _array[i] << std::endl;
        //result+=*i;
        func_obj(*i);
    }
    std::cout << std::endl;
    //return T;

    return func_obj.result();
}

int main()
{
    const unsigned size = 6;
    int* array = new int[size];

    for(unsigned i = 0; i < size; ++i)
    {
        array[i] = 2 * size - i;
    }

    std::cout << "Sum : " << func(array, size, Sum<int>()) << std::endl;

    std::cout << "Multi : " << func(array, size, Multi<int>()) << std::endl;

    return 0;
}

/**
1. Napisz funkcje wypisujac¹ elementy tablicy typu int.
2. Przerob funkcje tak by zwracala sume elementow tablicy.
3. Przerob funkcje na szablon funkcji.
4. Dodaj wlasny obiekt sumujacy elementy tablicy.
5. Dodaj wlasny obiekt zwracjacy iloczyn elemtow tablicy.
**/

