#ifndef __UNFAIR_FORMATTER__
#define __UNFAIR_FORMATTER__

#include "utilities.h"
#include "iformatter.h"

using namespace std;

class Table;
class UnfairFormatter : public IFormatter
{
    public:
        virtual ReturnValueE format_table(Table& table, char& vert_sep, char& horz_sep, char& joint_sep);
};

#endif /*__FAIR_FORMATTER__ */
