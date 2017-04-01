#include <algorithm>
#include <iostream>

/** The rules of three\five\zero **/

class BoolArray
{
public:
    /** constructor **/
    BoolArray(int size):_size(size)
    {
        std::cout << "constructor" << std::endl;
        _array = new bool[_size];

        for(int i = 0; i < _size; ++i)
        {
            _array[i] = true;
        }
    }

    /** copy constructor **/
    BoolArray(const BoolArray& bool_array) :
        _size(bool_array._size),
        _array{new bool[_size]}

    {
        std::cout << "copy constructor" << std::endl;
        std::copy(bool_array._array, bool_array._array + bool_array._size, _array);
    }

    /** move constructor **/
    BoolArray(BoolArray&& bool_array) :
        _size(bool_array._size),
        _array(bool_array._array)
    {
        std::cout << "move constructor" << std::endl;
        bool_array._size = 0;
        bool_array._array = nullptr;
    }

    /** copy assignment operator **/
    BoolArray& operator=(const BoolArray& bool_array)
    {
        std::cout << "copy assignment operator" << std::endl;
        if(&bool_array != this)
        {
            delete []_array;

            _size = bool_array._size;
            _array = new bool[_size];

            std::copy(bool_array._array, bool_array._array + bool_array._size, _array);
        }
        return *this;
    }

    /** move assignment operator **/
    BoolArray& operator=(BoolArray&& bool_array)
    {
        std::cout << "move assignment operator" << std::endl;
        if(&bool_array != this)
        {
            delete []_array;

            _size = bool_array._size;
            _array = bool_array._array;

            bool_array._size = 0;
            bool_array._array = nullptr;
        }
        return *this;
    }

    /** destructor **/
    ~BoolArray()
    {
        std::cout << "destructor" << std::endl;
        delete []_array;
    }

    void print()
    {
        std::cout << "Size: " << _size << " Array :[ " << _array << " ]   ";
        if(not _array)
        {
            std::cout << "nullptr" << std::endl;
            return;
        }

        for(int i = 0; i < _size; ++i)
        {
            std::cout << _array[i] << " ";
        }
        std::cout << std::endl;
    }

private:
    int _size;
    bool* _array;
};


int main()
{
    {
        BoolArray bool_array(5);
        std::cout << "Orginal -> "; bool_array.print();
    }

    std::cout << std::endl;

    {
        BoolArray bool_array(5);
        std::cout << "Orginal [before] -> "; bool_array.print();
        BoolArray bool_array_copy(bool_array);
        std::cout << "Orginal [after]  -> "; bool_array.print();
        std::cout << "Copy             -> "; bool_array_copy.print();
    }

    std::cout << std::endl;

    {
        BoolArray bool_array(5);
        std::cout << "Orginal [before] -> "; bool_array.print();
        BoolArray bool_array_move(std::move(bool_array));
        std::cout << "Orginal [after]  -> "; bool_array.print();
        std::cout << "Move             -> "; bool_array_move.print();
    }

    std::cout << std::endl;

    {
        BoolArray bool_array(5);
        std::cout << "Orginal [before] -> "; bool_array.print();
        BoolArray bool_array_copy = bool_array;
        std::cout << "Orginal [after]  -> "; bool_array.print();
        std::cout << "Copy             -> "; bool_array_copy.print();
    }

    std::cout << std::endl;

    {
        BoolArray bool_array(5);
        std::cout << "Orginal [before] -> "; bool_array.print();
        BoolArray bool_array_move = std::move(bool_array);
        std::cout << "Orginal [after]  -> "; bool_array.print();
        std::cout << "Move             -> "; bool_array_move.print();
    }
}

/**
    Jesli klasa jawnie implementuje jedna z ponizszych funkcji,
    powinna zaimplementowac je wszystkie.

    - copy constructor
    - copy assignment operator
    - destructor

    od C++11
    - move constructor
    - move assignment operator

    Funkcje te wymagane sa gdy recznie dokonujemy dynamicznej alokacji zasobow.
    Wymagane sa by zabezpieczyc zarzadzanie zasobami.
**/
