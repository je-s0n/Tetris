#include "Core.h"
#include "StageManager.h" // 테트리스 가로(10) * 세로(15) 몇개인지 정해서 스테이지 설계 필요
#include "ShapeManager.h"
#include <windows.h>

// 블럭 모양도 굉장히 다양함

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
	// 콘솔창 핸들 생성
	m_hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	// 제대로 되지 않는 핸들일 경우 false 리턴
	if (m_hConsole == INVALID_HANDLE_VALUE)
		return false;

	// 스테이지 관리자 초기화
	if (!CStageManager::GetInst()->Init())
		return false;
	return true;
}

void CCore::Run()
{
	while (true)
	{
		system("cls"); // 아래 1초 멈췄다가 지워지도록 하는 함수
		CShapeManager::GetInst()->Update();
		CStageManager::GetInst()->Run();
		CShapeManager::GetInst()->Render();
		
		Sleep(100);
	}
}

void CCore::SetConsolePos(int x, int y) 
{
	// 한 칸은 2Byte룰 사용하여 * 2를 해줌
	// 테트리스에서는 특수문자를 사용하여 1칸을 표현함
	COORD pos = { (x + 1) * 2, y };
	SetConsoleCursorPosition(m_hConsole, pos);
}