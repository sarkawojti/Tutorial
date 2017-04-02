
#include <iostream>
#include <cassert>
#include <stdexcept>
#include <map>
#include <set>

/** KONTENERY ASOCJACYJNE **/

/**

- kontenery o zmiennej dlugosci pozwalajace na operowanie elementami przy uzyciu kluczy
- always sorted, default criteria is operator<
- nie mozna dodawac danych na konkretna pozycje, kolejnosc ustalana jest wg danego klucza
- NO push_back or push_front
- zaimplementowane jako drzewo binarne, operacje add & remove powoduja rearanzacje drzewa

**/

class A
{
public:
    ~A(){ _count_call_destructor++; }
    static int _count_call_destructor;
};

int A::_count_call_destructor = 0;

int main()
{
    /**
        MAP - no duplicated key, each element is a pair of key and value,
            sorted according to the key [default use operator <].
    **/
    std::map<std::string, int> _string_map_int;

    assert(true == _string_map_int.empty());
    assert(0 == _string_map_int.size());

    /** random access / [] operator / C++11 "at" method **/
    _string_map_int["Tom"];     /** not safety, if key is not present then this key
                                    will be add with default value **/
    assert(false == _string_map_int.empty());
    assert(1 == _string_map_int.size());
    assert(_string_map_int["Tom"] == 0);
    _string_map_int.at("Tom");  /** safety, if hey is not present then throw excetion
                                    and will not add new item [C++11] **/
    try{
        _string_map_int.at("John");
    }catch(const std::out_of_range&){}

    /** OPERATION INSERT O(log(n)) **/
    auto _result = _string_map_int.insert(std::make_pair("John",18));
        /** return pair: FIRST is a iterator show a added/found element
            SECOND is a info if element added [true] existed before [false] **/
    assert(true == _result.second);
    assert(2 == _string_map_int.size());
    assert(_string_map_int["John"] == 18);

    _result = _string_map_int.insert(std::make_pair("Tom",18));
    assert(false == _result.second);
    assert(2 == _string_map_int.size());
    assert(_string_map_int["Tom"] == 0);

    _string_map_int.insert(_result.first, std::make_pair("Peter",27));
        /** ITERATOR is only a hint [NO INFO ABOUT THE INSERT POSITION]
            when O(log(n)) could be reduce to O(1) **/

    _result = _string_map_int.emplace("Peter", 28); /** faster, [C++11] **/
    _string_map_int.emplace_hint(_result.first, "Peter", 28); /** faster, [C++11] **/

    /** OPERATION REMOVE O(log(n)) **/
    auto _string_map_int_iterator = _string_map_int.erase("Tom");          /** by key **/
        /** return iterator shows a next element **/
    _string_map_int.erase(_result.first);                                  /** by iterator **/
    _string_map_int.erase(_string_map_int.begin(), _string_map_int.end()); /** by range **/
    _string_map_int.clear();        /** remove all **/

    std::map<std::string, A> _string_map_a;
    _string_map_a["Tom"];
    _string_map_a["John"];
    _string_map_a.erase("Tom");             /** call object destructor **/
    assert(A::_count_call_destructor == 1);
    _string_map_a.clear();                  /** call object destructor **/
    assert(A::_count_call_destructor == 2);

    /** OPERATION SEARCH O(log(n)) **/
    assert(_string_map_int.find("Tom") == _string_map_int.end()); /** by key **/
        /** return iterator shows a found element or end container **/
    _string_map_int["Tom"];
    assert(_string_map_int.find("Tom") != _string_map_int.end());

    assert(1 == _string_map_int.count("Tom"));
        /** return 0 if item is not present and 1 if is present
            [1 is max because all item in map are unique]   **/
    assert(0 == _string_map_int.count("John"));

    /** OPERATION MOVE **/
    std::map<std::string, int> _new_string_map_int;
    assert(1 == _string_map_int.size());
    assert(0 == _new_string_map_int.size());
    _string_map_int.swap(_new_string_map_int);
    assert(0 == _string_map_int.size());
    assert(1 == _new_string_map_int.size());

    /** OPERATION MODIFICATION **/
    /** value of the elements CAN BE MODIFIED / key of the elements CANNOT BE MODIFIED **/
    assert(0 == _new_string_map_int["Tom"]);
    _new_string_map_int["Tom"] = 100;
    assert(100 == _new_string_map_int["Tom"]);
    /** or use iterators, safety **/
    auto _iterator = _new_string_map_int.find("Tom");
    (*_iterator).second = 1001;
    assert(1001 == _new_string_map_int["Tom"]);
    _result = _string_map_int.insert(std::make_pair("Tom",18));
    (*_result.first).second = 18;
    assert(18 == _new_string_map_int["Tom"]);

    /**
        SET - no duplicated value, each element is a value,
            sorted according to the value [default use operator <]
    **/
    std:set<int> _int_set;

    assert(true == _int_set.empty());
    assert(0 == _int_set.size());

    /** no random access / no [] operator / no C++11 "at" method **/

    /** OPERATION INSERT O(log(n)) **/
    /** method insert/emplace/emplace_hint **/

    /** OPERATION REMOVE O(log(n)) **/
    /** method erase/clear **/

    /** OPERATION SEARCH O(log(n)) **/
    /** method find/count **/

    /** OPERATION MODIFICATION **/
    /** value of the elements CANNOT BE MODIFIED **/

    return 0;
}
