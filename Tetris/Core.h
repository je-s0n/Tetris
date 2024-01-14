#pragma once
#include "value.h"
#include "Macro.h"
#include <windows.h>

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
private:
	// �ܼ�â���� �ڵ� ���� �����
	HANDLE m_hConsole;
	bool m_bLoop;
public:
	bool Init(); // �ʱ�ȭ �Լ�
	void Run(); // ���� ���� run �Լ�
	void SetConsolePos(int x, int y); // ������ ���콺 ��ġ ��� ���� �Լ�
	void End() {
		m_bLoop = false;
	}
};

