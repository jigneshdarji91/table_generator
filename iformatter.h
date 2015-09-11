#ifndef __IFORMATTER__
#define __IFORMATTER__

#include "utilities.h"
#include <vector>

using namespace std;

class Table;
class IFormatter
{
    public:
        virtual ReturnValueE format_table(Table& table, char& vert_sep, char& horz_sep, char& joint_sep) = 0;
        virtual ReturnValueE print_border(Table& table, char horz_sep, char joint_sep);
        virtual ReturnValueE print_elements(Table& table, unsigned int row, char vert_sep);
};

#endif /*__IFORMATTER__*/
