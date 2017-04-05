
#include <iostream>
#include<fstream>

#include "inc/FileReader.h"
#include "inc/ConsoleReader.h"
#include "inc/WhiteSpaceCleanReader.h"
#include "inc/UpperReader.h"

int main()
{
    std::shared_ptr<IReader> reader_file = std::make_shared<FileReader>("data");
    std::cout << reader_file->read() << std::endl;

    std::shared_ptr<IReader> reader_console = std::make_shared<ConsoleReader>("Podaj: ");;
    std::cout << reader_console->read() << std::endl;

    WhiteSpaceCleanReader white_space_clean_file_reader(reader_file);
    std::cout << white_space_clean_file_reader.read() << std::endl;

    WhiteSpaceCleanReader white_space_clean_console_reader(reader_console);
    std::cout << white_space_clean_console_reader.read() << std::endl;

    UpperReader upper_file_reader(reader_file);
    std::cout << upper_file_reader.read() << std::endl;

    UpperReader upper_console_reader(reader_console);
    std::cout << upper_console_reader.read() << std::endl;

    return 0;
}

/** Dekoraotr  - obiektowy wzorzec strukturalny **/

/**

Dekorator musi miec taki sam interfejs jak obiekt, który bêdziemy dekorowac
(obiekty dekoruj¹ce sa tego samego typu co obiekty dekorowane).
Do dekoratora przekazujemy dekorowany obiekt. Wolajac funkcje dekoratora wolamy
funkcje z obiektu dekorujacego a nastepnie dodajemy fumkcjonalnosc.
W przeciwienstwie do dziedziczenia, obiekty dostaja nowe funkcjonalnoœci dynamicznie
( w trakcie dzialania programu), a nie na etapie kompilacji.
Klient wcale nie musi wiedziec o dzia³aniu wzorca.

**/
