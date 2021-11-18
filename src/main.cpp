/// @file main.cpp
/// Home of the one and only, main() routine for app.
///
/// @version 0.1
/// @author Gunjan Javaria <gunjan.javaria@zeusnumerix.com>
///
#include "calculate.h"

int main( int argc, char** argv ) {
    if( argc != 2 ){
        std::cout << "Illegal Usage" << std::endl;
        std::cout << "Run by ./app ../../input/control_file.json" << std::endl;
        return EXIT_FAILURE;
    }

    Calculate calc;
    if( !calc.readJsonFile( argv[1] )) {
        std::cout << "JSON File reading failed" << std::endl;
        return EXIT_FAILURE; 
    }
    if( !calc.run() ){
        std::cout << "Run failed" << std::endl;
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}