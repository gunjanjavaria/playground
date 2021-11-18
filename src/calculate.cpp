/// @file calculate.h
/// Implementation for the Calculate class.
///
/// @version 0.1
/// @author Gunjan Javaria <gunjan.javaria@zeusnumerix.com>

#include "calculate.h"

#include <fstream>

////////////////////////////////////////////////////////////////////////////////

bool Calculate::
readJsonFile( std::string aFilename ) {
    std::ifstream file;
	file.open( aFilename );
	if( !file.is_open() ) {
        std::cout << "not open" << std::endl;
		return false;
	}
    main = jsoncons::json::parse( file );
    file.close();

    return true;
}

bool Calculate::
run(){
    double a = main["numbers"]["first"].as_double();
    double b = main["numbers"]["second"].as_double();
    std::string opr = main["operation"].as_string();
    double result;
    if( opr == "add" ){
        result = add( a, b );
    }
    else if( opr == "subtract" ){
        result = subtract( a, b );
    }
    else if( opr == "multiply" ){
        result = multiply( a, b );
    }
    else {
        return false;
    }
    std::cout << "result: " << result << std::endl;
    return true;
}

double Calculate::
add( double x, double y ) {
    return ( x + y );
}

double Calculate::
subtract( double x, double y ) {
    return ( x - y );
}

double Calculate::
multiply( double x, double y ) {
    return ( x * y );
}
