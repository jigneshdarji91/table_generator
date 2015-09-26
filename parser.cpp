#include <vector>
#include <iostream>
#include <sstream>
#include <fstream>
#include "utilities.h"
#include "parser.h"

using namespace std;

ReturnValueE 
Parser::parse_file(const string filename, 
        const char separator, 
        TableVector& parsed_file)
{
    //LOG_DBG("begin filename: " << filename);
    ifstream infile(filename.c_str());
    string row;
    while (getline(infile, row))
    {
        RowVector parsed_line;
        parse_line(row, separator, parsed_line);
        if(parsed_line.size() != 0)
            parsed_file.push_back(parsed_line);
    }
    
    cout << "Parsed file:\n";
    for(int i = 0; i < parsed_file.size(); i++)
    {
        for(int j = 0; j < parsed_file[i].size(); j++)
            cout << "\n" << parsed_file[i][j];
        cout << endl;
    }

    //LOG_DBG("end");
    return SUCCESS;
}

ReturnValueE 
Parser::parse_line(const string input_line,
        const char separator,
        RowVector& parsed_line)
{
    //LOG_DBG("begin");
    std::istringstream row_string(input_line);
    string element;
    while (getline(row_string, element, separator))
    {
        parsed_line.push_back(element);
    }
    
    //LOG_DBG("end");
    return SUCCESS;
}
