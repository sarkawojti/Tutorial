
struct StructBase
{
    /** domyslnie skladowe struktury [pola, metody] sa publiczne **/
    int a;
    void show(){}
};

/** domyslnie dziedziczenie jest typu publicznego **/
struct StructDerived : StructBase {};

class ClassBase
{
    /** domyslnie skladowe klasy [pola, metody] sa prywatne **/
    int a;
    void show(){}
};

/** domyslnie dziedziczenie jest typu prywatnego **/
class ClassDerived : ClassBase {};

int main()
{
    StructBase _struct_base;
    _struct_base.a;
    _struct_base.show();

    StructDerived _struct_derived;
    _struct_derived.a;
    _struct_derived.show();

    ClassBase _class_base;
    ClassDerived _class_derived;

    return 0;
}
