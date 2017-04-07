
#include "inc/TypeInfoVisitor.h"
#include "inc/Object.h"

int main()
{
    using Union = boost::variant<int, double, std::string, Object>;

    TypeInfoVisitor _type_info;

    Union _union;       /** [DEFAULT]   obiekt przechowujacy zmienna typu int rowna 0 **/
    apply_visitor(_type_info, _union);
    _union = 4.5;       /** zmiana na typ double **/
    apply_visitor(_type_info, _union);
    _union = Object();  /** zmiana na typ Object **/
    apply_visitor(_type_info, _union);
    _union = 89;        /** zmiana na typ int **/
    apply_visitor(_type_info, _union);
    _union = "string";  /** zmiana na typ std::string **/
    apply_visitor(_type_info, _union);
}

