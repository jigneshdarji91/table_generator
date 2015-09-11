#ifndef __TABLE__
#define __TABLE__

#include <iostream>
#include <vector>
#include "utilities.h"
#include "iformatter.h"

using namespace std;

typedef vector< string > RowVector;
typedef vector< RowVector > TableVector;

class Table
{
    private:
        TableVector table;
        unsigned int column;
        char vert_sep, horz_sep, joint_sep;
        vector<unsigned int> column_width;
        IFormatter *formatter;

    public:
        Table(TableVector& in_table, 
                IFormatter*& f,
                char v_sep = '|',
                char h_sep = '-',
                char j_sep = '+') : formatter(f),
            vert_sep(v_sep),
            horz_sep(h_sep),
            joint_sep(j_sep)
        {  
            table = in_table;
            columns();
            column_widths();
        };

        Table operator=(const Table&);
        ReturnValueE max_columns(unsigned int& /*max_col*/);
        ReturnValueE max_column_width(const unsigned int /*col*/,
                unsigned int& /*max_col_width*/);
        int size() { table.size();};
        ReturnValueE columns();
        ReturnValueE column_widths();
        ReturnValueE get_columns(unsigned int& col){ col = column; };
        ReturnValueE get_rows(unsigned int& row){ row = table.size();};
        ReturnValueE get_column_width(const unsigned int & col,
                unsigned int& col_width) { col_width = column_width[col] + 2;};
        ReturnValueE set_formatter(IFormatter*& f) {formatter = f;};
        ReturnValueE get_element(unsigned int& row,
                unsigned int& col,
                string& element);
        ReturnValueE print_table();
};
#endif /*__TABLE__*/
