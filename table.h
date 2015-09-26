#ifndef __TABLE__
#define __TABLE__

#include <iostream>
#include <vector>
#include "utilities.h"
#include "iformatter.h"

using namespace std;

typedef vector< string > RowVector;
typedef vector< RowVector > TableVector;

/// Maintains the data structures required to generated a formatted table. It's main function is to store the width of the columns.
class Table
{
    private:
        ///2D String Vector to store the table
        TableVector table;
        ///Number of columns
        unsigned int column;
        ///Seperators for the table
        char vert_sep, horz_sep, joint_sep;
        ///Column widths for all the columns
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

        ///Returns the size of the Table
        int size() { table.size();};

        ///Calculates the max number of columns in the table
        ReturnValueE columns();
        
        ///Generates column widths and stores in a vector
        ReturnValueE column_widths();
        
        ///Returns the number of columns in the table
        ReturnValueE get_columns(unsigned int& col){ col = column; };

        ///Returns the number of rows in the table
        ReturnValueE get_rows(unsigned int& row){ row = table.size();};

        ///Returns width of a specific column
        ReturnValueE get_column_width(const unsigned int & col,
                unsigned int& col_width) { col_width = column_width[col] + 2;};

        ///Sets the formatter to be used
        ReturnValueE set_formatter(IFormatter*& f) {formatter = f;};

        ///Returns the element at the specified position
        ReturnValueE get_element(unsigned int& row,
                unsigned int& col,
                string& element);

        ///Prints the table using the Formatter specified
        ReturnValueE print_table();
};
#endif /*__TABLE__*/
