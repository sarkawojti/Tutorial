
#pragma once

/****    Prototyp         kreacyjny wzorzec projektowy    ****/

/**
    mechanizm tworzenia nowych obiektów poprzez klonowanie obiektu do
    którego posiadamy jedynie wskaźnik na klasę bazową
**/

class ICloneable
{
public:
    virtual ICloneable* clone() = 0;
};
