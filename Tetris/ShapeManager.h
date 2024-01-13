#pragma once
#include "value.h"

class CShapeManager
{
public:
	CShapeManager();
	~CShapeManager();
private:
	static CShapeManager* m_pInst;

public:
	static CShapeManager* GetInst()
	{
		if (!m_pInst)
			m_pInst = new CShapeManager;
		return m_pInst;
	}

	static void DestroyInst()
	{
		SAFE_DELETE(m_pInst);
	}

private:
	list<class CShape*> m_ShapeList; // 바닥에 쌓인 도형 표현
	class CShape* m_pCurShape; // 현재 나와있는 도형 표현
	class CShape* m_pNextShape; // 다음 나올 도형 표현

	// 도형을 움직일 틱을 정함
	int	m_iSpeed;

public:
	void Update(); // 도형 업데이트
	void Render();
	class CShape* CreateRandomShape();
	class CShape* CreateShape(SHAPE_TYPE eType); // 도형을 만들어주는 함수
};

