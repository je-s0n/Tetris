#include "ShapeGun.h"

CShapeGun::CShapeGun()
{
}

CShapeGun::~CShapeGun()
{
}

bool CShapeGun::Init()
{
	if (!CShape::Init()) {
		return false;
	}
	m_cShape[2][0] = '0'; // 0 : 차있는것
	m_cShape[2][1] = '0';
	m_cShape[2][2] = '0';
	m_cShape[3][2] = '0';

	m_iWidthCount = 3;
	m_tPos.x = 4;
	m_tPos.y = 0;
	return true;
}