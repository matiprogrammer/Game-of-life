#ifndef ICLICKLISTENER_H
#define ICLICKLISTENER_H

#include "SimpleCell.h"



class IClickListener
{
public:
    virtual void onClick(SimpleCell *cell)=0;
};

#endif // ICLICKLISTENER_H
