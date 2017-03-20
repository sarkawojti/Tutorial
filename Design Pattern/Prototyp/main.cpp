#include <iostream>
#include <vector>

#include "inc/Book.h"

int main()
{
    std::vector<IBook*> books_catalog;
    books_catalog.push_back(new Book("Thinking in C++"));

    std::cout << books_catalog[0]->title() << std::endl;

    std::vector<IBook*> books_catalog_shallow_copy = books_catalog;
    /** Tak wykonana kopia katalogu zawiera jedynie wskazniki na te same obiekty. **/

    std::vector<IBook*> books_catalog_deep_copy;
    for(const auto& book : books_catalog)
    {
        books_catalog_deep_copy.push_back( (*book).clone() );
    }
    /** kopia zapasowa, kopia dla innego usera **/

    return 0;
}
