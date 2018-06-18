/*!
 *
 */

#ifndef COMPUTE_READ_H
#define COMPUTE_READ_H

#include <string>
#include <fstream>
#include <iostream>

inline std::string read_from_binary_file( const std::string& filepath )
{
    std::ifstream file( filepath , std::ios::binary );
    std::string str;

    if( !file.tellg() < 0 )
    {
        std::cerr << "Error loading file at location: " << filepath << "." << std::endl;
    }
    else if( !file.good() )
    {
        std::cerr << "Error reading file: " << filepath << "." << std::endl;
    }

    char c;
    while( file.get( c ) )
    {
        str.push_back( c );
    }

    return str;
}

#endif //COMPUTE_READ_H
