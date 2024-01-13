#include "Shape.h"
#include "Core.h"

CShape::CShape() {

	for (int i = 0; i < 4; ++i) {
		for (int j = 0; j < 4; ++j) {
			m_cShape[i][j] = '1'; // 1 : �����
		}
	}
}

CShape::~CShape() {
}

bool CShape::Init()
{
	// ���� �Ʒ��� ����Ÿ� �Ʒ��� ���� ������ ��ƾ� ��
	m_tPivot.x = 0;
	m_tPivot.y = 3;
	return true;
}


// ������ �ֵܼ� �ڵ��� ������ ���� -> �׷��� �� �ֿܼ� �ڵ��� ������ �ͼ� �� �ܼ�â�� ��Ʈ�� �ϱ�
// �ü������ �ڵ��� �̿��Ͽ� ��û�ؾ� �� -> ���� ��� �� �� 4-5������ ��� ������ [0][4]
void CShape::Render()
{

	for (int i = 0; i < 4; ++i)
	{
		int iYIndex = m_tPos.y - (3 - i);
		if (iYIndex < 0)
			continue;
		// �ܼ�â�� ����� ��ǥ�� ������ �� ���
		CCore::GetInst()->SetConsolePos(m_tPos.x, iYIndex);
		for (int j = 0; j < 4; ++j)
		{
			// �� ���������� ������ �� ��� "  "�� ��� ���� �ʵ��� ó��
			if (m_tPos.x + j >= STAGE_WIDTH)
				continue;

			if (m_cShape[i][j] == '0')
				cout << "��";
			else
				cout << "  ";
		}

		cout << endl;
	}
}

// �� �Լ��� true : �ٴڿ� ����, false : �ٴڿ� ���� ����
boolean CShape::MoveDown() {
	if (m_tPos.y == STAGE_HEIGHT - 1) // �� �Ʒ����� ������ �� ����
		return true;
	++m_tPos.y;
	return false;
}

void CShape::MoveLeft() {
	if (m_tPos.x == 0)
		return;
	--m_tPos.x;
}

void CShape::MoveRight() {
	if (m_tPos.x + m_iWidthCount == STAGE_WIDTH) // ������ �� ���� �Ʒ��� �������� ��ұ� ������ �������� ó�� �ʿ��Ͽ� �����ϰ� �ִ� ���� �� ���� �� ��
		return;
	++m_tPos.x;
}

void CShape::RenderNext()
{

	for (int i = 0; i < 4; ++i)
	{
		int iYIndex = m_tPos.y - (3 - i);
		if (iYIndex < 0)
			continue;
		// �ܼ�â�� ����� ��ǥ�� ������ �� ���
		CCore::GetInst()->SetConsolePos(m_tPos.x, iYIndex);
		for (int j = 0; j < 4; ++j)
		{

			if (m_cShape[i][j] == '0')
				cout << "��";
			else
				cout << "  ";
		}

		cout << endl;
	}
}