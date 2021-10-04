
#include "Header.h"
#include "conio.h"
 
int main()
{
    Vector <int> x(5);
    x.showarray();
    x.allocarray(10);
    x.showarray();
    x.addtoend(102);
    x.showarray();
    _getch();
    return 0;
}
