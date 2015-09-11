#ifndef __FAIR_FORMATTER__
#define __FAIR_FORMATTER__

#include "iformatter.h"

using namespace std;

class Table;
class FairFormatter : public IFormatter
{
    public:
        virtual ReturnValueE format_table(Table& table, char& vert_sep, char& horz_sep, char& joint_sep);
};

#endif /*__FAIR_FORMATTER__ */
