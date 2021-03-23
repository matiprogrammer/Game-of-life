#ifndef VIEW_H
#define VIEW_H

#include <list>
#include <QString>
using namespace std;
class View
{
public:
    virtual~View();
    View();
    virtual void  update()=0;
    virtual void setPossibleCellTypes(list<QString> possibleCellTypes)=0;

};

#endif // VIEW_H
