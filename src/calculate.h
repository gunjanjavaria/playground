/// @file calculate.h
/// Declaration for the Calculate class.
///
/// @version 0.1
/// @author Gunjan Javaria <gunjan.javaria@zeusnumerix.com>

#ifndef __HH_CALCULATE_HH__
#define __HH_CALCULATE_HH__

#include <jsoncons/json.hpp>

#include <iostream>

////////////////////////////////////////////////////////////////////////////////

class Calculate {
    
public:
    /// Reads/parses a json file using jsoncons library
    /// 
    /// @param aFilename A string consisting of path of the file which is to be 
    /// read. This could be a relative path from cwd like ../../input/file.json
    /// or an absolute path like C:/user/playground/input/file.json
    ///
    /// @return The function returns true if the file is read successfully
    bool readJsonFile( std::string aFilename );

    /// Runs the program
    ///
    /// @return The function returns true if run is successfully
    bool run();

    /// Adds the numbers
    ///
    /// @return The function returns sum of two numbers
    double add( double x, double y );

    /// Subtracts the numbers
    ///
    /// @return The function returns difference of two numbers
    double subtract( double x, double y );

    /// Muliplies the numbers
    ///
    /// @return The function returns product of two numbers
    double multiply( double x, double y );

private:
    jsoncons::json main;
};

#endif  //__HH_CALCULATE_HH__
