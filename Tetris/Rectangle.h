#pragma once
#include "Shape.h"
class CRectangle :
    public CShape
{
public:
    CRectangle();
    ~CRectangle();

public:
    virtual bool Init();
};

