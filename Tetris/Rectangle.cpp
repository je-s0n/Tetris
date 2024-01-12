#include "Rectangle.h"

CRectangle::CRectangle()
{
}

CRectangle::~CRectangle()
{
}

bool CRectangle::Init()
{
	if (!CShape::Init()) {
		return false;
	}
	// 왼쪽 아래로 기준을 잡음
	m_cShape[2][0] = '0'; // 0 : 차있는것
	m_cShape[2][1] = '0';
	m_cShape[3][0] = '0';
	m_cShape[3][1] = '0';

	m_iWidthCount = 2;
	return true;
}