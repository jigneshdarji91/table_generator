#ifndef __PARSER__
#define __PARSER__

#include "utilities.h"
#include <vector>

using namespace std;

typedef vector< string > RowVector;
typedef vector< RowVector > TableVector;


///Parser: This class parses a given file using a user-defined separator as a demiliter and generates a 2D string vector
class Parser
{
    public:
        ///Generates a 2D string vector from the input file using a user-defined separator
        static ReturnValueE parse_file(const string filename,
                const char separator,
                TableVector& parsed_file);

        ///Generates a string vector from a line in input file using a user-define seperator
        static ReturnValueE parse_line(const string input_line,
                const char separator,
                RowVector& parsed_line);
};

#endif /*__PARSER__*/
