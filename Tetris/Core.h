#pragma once
#include "value.h"
#include "Macro.h"
class CCore
{
private:
	CCore();
	~CCore();
private:
	static CCore* m_pInst;
public:
	// �̱��� �������� �����ϱ� ���� �̱��� ��ü ����
	static CCore* GetInst()
	{
		if (!m_pInst)
			m_pInst = new CCore;
		return m_pInst;
	}

	static void DestroyInst()
	{
		// �޸� ���� ��ũ�� ����ؼ� ����
		SAFE_DELETE(m_pInst);
	}
public:
	bool Init(); // �ʱ�ȭ �Լ�
	void Run(); // ���� ���� run �Լ�
};

