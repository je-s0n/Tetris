#include "ShapeS.h"

CShapeS::CShapeS()
{
}

CShapeS::~CShapeS()
{
}

bool CShapeS::Init()
{
	if (!CShape::Init()) {
		return false;
	}
	// ���� �Ʒ��� ������ ����
	m_cShape[2][1] = '0'; // 0 : ���ִ°�
	m_cShape[2][2] = '0';
	m_cShape[3][0] = '0';
	m_cShape[3][1] = '0';

	m_iWidthCount = 3;
	m_tPos.x = 4;
	m_tPos.y = 0;
	return true;
}