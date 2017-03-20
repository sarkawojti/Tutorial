
#include "IBook.h"

class Book : public IBook
{
private:
    std::string _title;
public:
    Book(const std::string title):_title(title){}
    Book(const Book&) = default;

    Book* clone() override { return new Book(*this); }
    std::string title() const override { return _title; }

};
