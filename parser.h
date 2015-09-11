#ifndef __PARSER__
#define __PARSER__

#include "utilities.h"
#include <vector>

using namespace std;

typedef vector< string > RowVector;
typedef vector< RowVector > TableVector;

class Parser
{
    public:
        static ReturnValueE parse_file(const string filename,
                const char separator,
                TableVector& parsed_file);
        static ReturnValueE parse_line(const string input_line,
                const char separator,
                RowVector& parsed_line);
};

#endif /*__PARSER__*/
