#include "Core.h"
#include "StageManager.h"
// ��Ʈ���� ����(10) * ����(15) ����� ���ؼ� �������� ���� �ʿ�


// �� ��絵 ������ �پ���

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
	// �������� ������ �ʱ�ȭ
	if (!CStageManager::GetInst()->Init())
		return false;
	return true;
}

void CCore::Run()
{
	CStageManager::GetInst()->Run();
}