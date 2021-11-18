/// @file test.cpp
/// Implementation for the Testing framework.
///
/// @version 0.1
/// @author Gunjan Javaria <gunjan.javaria@zeusnumerix.com>

#include "calculate.h"

#include "gtest/gtest.h"

////////////////////////////////////////////////////////////////////////////////
Calculate calc;

TEST( ADDITION_TEST, POSITIVE ){
    EXPECT_EQ( calc.add( 1.0, 1.0 ), 2.0 ); 
}

TEST( ADDITION_TEST, NEGATIVE ){
    EXPECT_EQ( calc.add( -1.0, -1.0 ), -2.0 ); 
}

TEST( SUBTRACTION_TEST, POSITIVE ){
    EXPECT_EQ( calc.subtract( 2.0, 1.0 ), 1.0 ); 
}

int main( int argc, char** argv ) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}