#pragma once
#include "value.h"
class CStageManager
{
public:
	CStageManager();
	~CStageManager();
private:
	static CStageManager* m_pInst;

public:
	static CStageManager* GetInst()
	{
		if (!m_pInst)
			m_pInst = new CStageManager;
		return m_pInst ;
	}

	static void DestroyInst()
	{
		SAFE_DELETE(m_pInst);
	}

// 현재 스테이지 정보 필요
private:
	class CStage* m_pCurStage;
public:
	bool Init();
	void Run();
};

