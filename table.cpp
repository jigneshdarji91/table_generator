#include <iostream>
#include <sstream>
#include <fstream>
#include "table.h"

using namespace std;

Table
Table::operator=(const Table& t)
{
    table = t.table;
    vert_sep = t.vert_sep;
    horz_sep = t.horz_sep;
    joint_sep = t.joint_sep;
    formatter = t.formatter;
    columns();
    column_widths();
}

ReturnValueE 
Table::columns()
{
    //LOG_DBG("begin");
    column = 0;
    for(int i = 0; i < table.size(); i++)
        column = (column > table[i].size()) ? column : table[i].size();
    //LOG_DBG("end max column: " << column);
    return SUCCESS;
}

ReturnValueE 
Table::column_widths()
{
    //LOG_DBG("begin");
    unsigned int max_col_width = 0;

    for(int col = 0; col < column; col++)
    {
        for(int i = 0; i < table.size(); i++)
        {
            if(col >= table[i].size())
                continue;
            max_col_width = (max_col_width > table[i][col].length()) ? max_col_width : table[i][col].length();
        }
        column_width.push_back(max_col_width);
        max_col_width = 0;
    }

    //LOG_DBG("end max_col_width: " << max_col_width);
    return SUCCESS;
}
        
ReturnValueE 
Table::get_element(unsigned int& row,
                unsigned int& col,
                string& element)
{
    //LOG_DBG("begin");
    if(row >= table.size())
    { 
        //LOG(" row number is out of bounds");
        element = " ";
        return FAILURE;
    }
    if(col >= table[row].size())
    {
        //LOG(" col number is out of bounds");
        element = " ";
        return FAILURE;
    }
    element = table[row][col];
    //LOG("[" << row << ", " << col << "] = " << element);
    return SUCCESS;
}

ReturnValueE 
Table::print_table()
{
    formatter->format_table(*this, vert_sep, horz_sep, joint_sep);
}

