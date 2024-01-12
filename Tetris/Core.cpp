#include "Core.h"
#include "StageManager.h"
// 테트리스 가로(10) * 세로(15) 몇개인지 정해서 스테이지 설계 필요


// 블럭 모양도 굉장히 다양함

CCore* CCore::m_pInst = NULL;

CCore::CCore()
{
}

CCore::~CCore()
{
	CStageManager::DestroyInst();
}

bool CCore::Init()
{
	// 스테이지 관리자 초기화
	if (!CStageManager::GetInst()->Init())
		return false;
	return true;
}

void CCore::Run()
{
	CStageManager::GetInst()->Run();
}