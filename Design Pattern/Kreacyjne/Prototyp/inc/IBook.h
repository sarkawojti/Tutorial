
#pragma once

class IBook
{
public:
    virtual std::string title() const = 0;

/****    Prototyp         kreacyjny wzorzec projektowy    ****/
/**
    mechanizm tworzenia nowych obiekt�w poprzez klonowanie obiektu do
    kt�rego posiadamy jedynie wska�nik na klas� bazow�
**/
    virtual IBook* clone() = 0;

    virtual ~IBook() = default;
};
