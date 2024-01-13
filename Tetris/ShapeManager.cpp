#include "ShapeManager.h"
#include "Rectangle.h"
CShapeManager* CShapeManager::m_pInst = NULL;

CShapeManager::CShapeManager() :
	m_pCurShape(NULL), m_pNextShape(NULL)
{
	m_pCurShape = CreateRandomShape(); // 랜덤함수 생성
}

CShapeManager::~CShapeManager()
{
	list<CShape*>::iterator iterEnd = m_ShapeList.end();
	for (list<CShape*>::iterator iter = m_ShapeList.begin(); iter != iterEnd; ++iter)
	{
		SAFE_DELETE(*iter);
	}

	SAFE_DELETE(m_pCurShape);
	SAFE_DELETE(m_pNextShape);
}

CShape* CShapeManager::CreateRandomShape() 
{
	int iType = rand() % ST_END;
	return CreateShape((SHAPE_TYPE)iType);
}

void CShapeManager::Update()
{
	m_pCurShape->MoveDown();
}

void CShapeManager::Render()
{
	list<CShape*>::iterator iterEnd = m_ShapeList.end();
	for (list<CShape*>::iterator iter = m_ShapeList.begin(); iter != iterEnd; ++iter)
	{
		(*iter)->Render();
	}
	m_pCurShape->Render();
}
CShape * CShapeManager::CreateShape(SHAPE_TYPE eType)
{
	CShape* pShape = NULL;
	switch (eType)
	{
	case ST_RECT :
		pShape = new CRectangle;
		break;
	}

	if (!pShape->Init())
	{
		SAFE_DELETE(pShape);
		return NULL;
	}

	return pShape;
}
