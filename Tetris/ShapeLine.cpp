#include "ShapeLine.h"

CShapeLine::CShapeLine()
{
}

CShapeLine::~CShapeLine()
{
}

bool CShapeLine::Init()
{
	if (!CShape::Init()) {
		return false;
	}
	m_cShape[3][0] = '0'; // 0 : 차있는것
	m_cShape[3][1] = '0';
	m_cShape[3][2] = '0';
	m_cShape[3][3] = '0';

	m_iWidthCount = 4;
	m_tPos.x = 4;
	m_tPos.y = 0;
	return true;
	
}