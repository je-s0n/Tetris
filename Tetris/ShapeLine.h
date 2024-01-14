#pragma once
#include "Shape.h"
class CShapeLine : public CShape
{
public:
	CShapeLine();
	~CShapeLine();

public:
	virtual bool Init();
	virtual void Rotation();
};


