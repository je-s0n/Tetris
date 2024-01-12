#pragma once

#include "value.h"

class CShape
{
public:
	CShape();
	virtual  ~CShape();

protected:
	// 가로길이 4, 세로길이 4 (최대)
	char m_cShape[4][4]; // 도형 형태
	POSITION m_tPos;
	// 스테이지에서의 위치도 있고, 4*4에서의 기준점도 필요함 -> 이 기준점을 기준으로 스테이지에 출력해야 함
	// 각 도형마다 기준점 필요하며, 밑바닥을 기준으로 하는 것이 좋음 -> 스테이지 밑바닥에 닿았을 때 멈춰야 하기 때문
	// 도형의 회전 시에도 기준이 필요함
	POSITION m_tPivot;
	// 피봇을 잡아놓고 현재 모양이 무엇이냐에 따라 모양 바뀔 때마다 가로 몇칸인지 저장해야 함 
	int m_iWidthCount;
	
public:
	void SetPosition(int x, int y)
	{
		m_tPos.x = x;
		m_tPos.y = y;
	}

	void SetPosition(const POSITION& tPos)
	{
		m_tPos = tPos;
	}

	POSITION GetPosition() const // 원하는 이 도형의 현재 위치 return -> 이 도형의 위치를 기준으로 해서 채워줘야 함
	{
		return m_tPos;
	}

	POSITION GetPivot() const
	{
		return m_tPivot;
	}
public:
	virtual bool Init();

public:
	void Render();
	void MoveDown();
	void MoveLeft();
	void MoveRight();
};

