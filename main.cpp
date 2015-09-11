#include "parser.h"
#include "table.h"
#include "fair_formatter.h"
#include "unfair_formatter.h"
#include "utilities.h"

int main(int argc, char** argv)
{
    TableVector temp;
    Parser::parse_file(argv[1], '\t', temp);
    IFormatter* formatter = new FairFormatter();
    
    char vert_sep, horz_sep, joint_sep;

    if(argc == 5)
    {
        vert_sep = (char)*argv[2];
        horz_sep = (char)*argv[3];
        joint_sep = (char)*argv[4];
    }
    else
    {
        vert_sep = '|';
        horz_sep = '-';
        joint_sep = '+';
    }
    Table table(temp, formatter, vert_sep, horz_sep, joint_sep);
    table.print_table();

    cout << endl << endl;

    formatter = new UnfairFormatter();
    table.set_formatter(formatter);
    table.print_table();
}
