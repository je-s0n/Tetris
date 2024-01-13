#include "ShapeManager.h"
#include "Rectangle.h"
#include "Stage.h"
#include "StageManager.h"
CShapeManager* CShapeManager::m_pInst = NULL;

CShapeManager::CShapeManager() :
	m_pCurShape(NULL), m_pNextShape(NULL)
{
	m_pCurShape = CreateRandomShape(); // 현재 랜덤함수 생성
	m_pNextShape = CreateRandomShape(); // 다음 랜덤함수 생성
	m_iSpeed = 0;
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
	CStage* pStage = CStageManager::GetInst()->GetCurrentStage();

	++m_iSpeed;

	if (pStage->GetSpeed() == m_iSpeed)
	{
		// true일 경우 바닥에 닿았으므로 리스트에 추가하고 다음 도형을 현재 도형으로 만들어주며, 그 후 다음 도형을 생성함
		if (m_pCurShape->MoveDown()) {
			m_ShapeList.push_back(m_pCurShape);

			m_pCurShape = m_pNextShape;
			m_pCurShape->SetPosition(4, 0);

			m_pNextShape = CreateRandomShape();
		}
		m_iSpeed = 0;
	}

	if(GetAsyncKeyState('A') & 0x8000)
	{
		m_pCurShape->MoveLeft();
	}


	if (GetAsyncKeyState('D') & 0x8000)
	{
		m_pCurShape->MoveRight();
	}
}

void CShapeManager::Render()
{
	list<CShape*>::iterator iterEnd = m_ShapeList.end();
	for (list<CShape*>::iterator iter = m_ShapeList.begin(); iter != iterEnd; ++iter)
	{
		(*iter)->Render();
	}
	m_pCurShape->Render();
	m_pNextShape->SetPosition(13, 3);
	m_pNextShape->RenderNext();
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
