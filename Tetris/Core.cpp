#include "Core.h"
#include "StageManager.h" // ��Ʈ���� ����(10) * ����(15) ����� ���ؼ� �������� ���� �ʿ�
#include "ShapeManager.h"
#include <windows.h>

// �� ��絵 ������ �پ���

CCore* CCore::m_pInst = NULL;

CCore::CCore()
{
	srand((unsigned int)time(0));
}

CCore::~CCore()
{
	CStageManager::DestroyInst();
}

bool CCore::Init()
{
	// �ܼ�â �ڵ� ����
	m_hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	// ����� ���� �ʴ� �ڵ��� ��� false ����
	if (m_hConsole == INVALID_HANDLE_VALUE)
		return false;

	// �������� ������ �ʱ�ȭ
	if (!CStageManager::GetInst()->Init())
		return false;
	return true;
}

void CCore::Run()
{
	while (true)
	{
		system("cls"); // �Ʒ� 1�� ����ٰ� ���������� �ϴ� �Լ�
		CShapeManager::GetInst()->Update();
		CStageManager::GetInst()->Run();
		CShapeManager::GetInst()->Render();
		
		Sleep(100);
	}
}

void CCore::SetConsolePos(int x, int y) 
{
	// �� ĭ�� 2Byte�� ����Ͽ� * 2�� ����
	// ��Ʈ���������� Ư�����ڸ� ����Ͽ� 1ĭ�� ǥ����
	COORD pos = { (x + 1) * 2, y };
	SetConsoleCursorPosition(m_hConsole, pos);
}