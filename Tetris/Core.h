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
private:
	// 콘솔창에서 핸들 변수 잡아줌
	HANDLE m_hConsole;
	bool m_bLoop;
public:
	bool Init(); // 초기화 함수
	void Run(); // 게임 동작 run 함수
	void SetConsolePos(int x, int y); // 윈도우 마우스 위치 잡는 세팅 함수
	void End() {
		m_bLoop = false;
	}
};

