#pragma once
#include "Shape.h"
class CShapeT : public CShape
{
public:
	CShapeT();
	~CShapeT();

public:
	virtual bool Init();
	virtual void Rotation();
};


