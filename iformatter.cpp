#include <iostream>
#include <sstream>
#include <fstream>
#include <iomanip>
#include "table.h"
#include "iformatter.h"

using namespace std;

ReturnValueE
IFormatter::print_border(Table& table, char horz_sep, char joint_sep)
{
    unsigned int col, col_width;
    table.get_columns(col);
    for(unsigned int j = 0; j < col; j++)
    {
        if(j == 0)
            cout << joint_sep ;
        table.get_column_width(j, col_width);
        for(int k = 0; k < col_width; k++)
            cout << horz_sep;
        cout << joint_sep ;
    }
    cout << endl;
}

ReturnValueE
IFormatter::print_elements(Table& table, unsigned int row, char vert_sep)
{
    unsigned int col, col_width;
    string element;
    table.get_columns(col);
    for(unsigned int j = 0; j < col; j++)
    {
        if(j == 0)
            cout << vert_sep ;
        table.get_column_width(j, col_width);
        table.get_element(row, j, element);
        cout << setw(col_width) << left << element << vert_sep ;
    }
    cout << endl;
}

