#include "output.h"
#include <syncstream>
using namespace std;
void action(char name, int index)
{
    osyncstream out(cout);
    out << "from " << name
        << " done actrion " << index << ".\n";
}
