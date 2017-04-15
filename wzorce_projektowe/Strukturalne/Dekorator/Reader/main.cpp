
#include <iostream>

#include "inc/FileReader.h"
#include "inc/ConsoleReader.h"
#include "inc/WhiteSpaceCleanReader.h"
#include "inc/UpperReader.h"

int main()
{
    std::shared_ptr<IReader> reader_console = std::make_shared<ConsoleReader>("Podaj: ");;
    std::cout << reader_console->read() << std::endl;

    std::shared_ptr<IReader> reader_file = std::make_shared<FileReader>("data.txt");
    std::cout << reader_file->read() << std::endl;

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
