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
	// 싱글톤 패턴으로 구현하기 위한 싱글톤 객체 만듦
	static CCore* GetInst()
	{
		if (!m_pInst)
			m_pInst = new CCore;
		return m_pInst;
	}

	static void DestroyInst()
	{
		// 메모리 해제 매크로 사용해서 만듦
		SAFE_DELETE(m_pInst);
	}
public:
	bool Init(); // 초기화 함수
	void Run(); // 게임 동작 run 함수
};

