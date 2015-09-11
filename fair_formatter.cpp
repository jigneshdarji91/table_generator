#include <iostream>
#include <sstream>
#include <fstream>
#include <iomanip>
#include "fair_formatter.h"
#include "table.h"

using namespace std;

ReturnValueE
FairFormatter::format_table(Table& table, char& vert_sep, char& horz_sep, char& joint_sep)
{
    print_border(table, horz_sep, joint_sep);
    for(unsigned int i = 0; i < table.size(); i++)
    {
        print_elements(table, i, vert_sep);
        print_border(table, horz_sep, joint_sep);
    }
}

