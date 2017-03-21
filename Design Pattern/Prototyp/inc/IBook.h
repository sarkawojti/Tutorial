
#pragma once

class IBook
{
public:
    virtual std::string title() const = 0;

/****    Prototyp         kreacyjny wzorzec projektowy    ****/
/**
    mechanizm tworzenia nowych obiektów poprzez klonowanie obiektu do
    którego posiadamy jedynie wskaŸnik na klasê bazow¹
**/
    virtual IBook* clone() = 0;

    virtual ~IBook() = default;
};
