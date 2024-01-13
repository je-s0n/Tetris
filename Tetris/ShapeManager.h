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
	list<class CShape*> m_ShapeList; // �ٴڿ� ���� ���� ǥ��
	class CShape* m_pCurShape; // ���� �����ִ� ���� ǥ��
	class CShape* m_pNextShape; // ���� ���� ���� ǥ��

	// ������ ������ ƽ�� ����
	int	m_iSpeed;

public:
	void Update(); // ���� ������Ʈ
	void Render();
	class CShape* CreateRandomShape();
	class CShape* CreateShape(SHAPE_TYPE eType); // ������ ������ִ� �Լ�
};

