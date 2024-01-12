#pragma once

#include "value.h"

class CShape
{
public:
	CShape();
	virtual  ~CShape();

protected:
	// ���α��� 4, ���α��� 4 (�ִ�)
	char m_cShape[4][4]; // ���� ����
	POSITION m_tPos;
	// �������������� ��ġ�� �ְ�, 4*4������ �������� �ʿ��� -> �� �������� �������� ���������� ����ؾ� ��
	// �� �������� ������ �ʿ��ϸ�, �عٴ��� �������� �ϴ� ���� ���� -> �������� �عٴڿ� ����� �� ����� �ϱ� ����
	// ������ ȸ�� �ÿ��� ������ �ʿ���
	POSITION m_tPivot;
	// �Ǻ��� ��Ƴ��� ���� ����� �����̳Ŀ� ���� ��� �ٲ� ������ ���� ��ĭ���� �����ؾ� �� 
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

	POSITION GetPosition() const // ���ϴ� �� ������ ���� ��ġ return -> �� ������ ��ġ�� �������� �ؼ� ä����� ��
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

