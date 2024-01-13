#include "Shape.h"
#include "Core.h"

CShape::CShape() {

	for (int i = 0; i < 4; ++i) {
		for (int j = 0; j < 4; ++j) {
			m_cShape[i][j] = '1'; // 1 : 빈공간
		}
	}
}

CShape::~CShape() {
}

bool CShape::Init()
{
	// 왼쪽 아래로 맞출거면 아래와 같이 기준점 잡아야 함
	m_tPivot.x = 0;
	m_tPivot.y = 3;
	return true;
}


// 윈도우 콘솔도 핸들을 가지고 있음 -> 그래서 이 콘솔에 핸들을 가지고 와서 이 콘솔창을 컨트롤 하기
// 운영체제한테 핸들을 이용하여 요청해야 함 -> 가로 가운데 맨 끝 4-5번으로 잡고 내리자 [0][4]
void CShape::Render()
{

	for (int i = 0; i < 4; ++i)
	{
		// 콘솔창에 출력할 좌표를 설정한 후 출력
		CCore::GetInst()->SetConsolePos(m_tPos.x, m_tPos.y-(3-i));
		for (int j = 0; j < 4; ++j)
		{
			if (m_cShape[i][j] == '0')
				cout << "■";
			else
				cout << "  ";
		}

		cout << endl;
	}
}

void CShape::MoveDown() {
	if (m_tPos.y == STAGE_HEIGHT - 1) // 맨 아래에서 움직일 수 없다
		return;
	++m_tPos.y;
}

void CShape::MoveLeft() {
	if (m_tPos.x == 0)
		return;
	--m_tPos.x;
}

void CShape::MoveRight() {
	if (m_tPos.x + m_iWidthCount == STAGE_WIDTH) // 도형의 맨 왼쪽 아래를 기준으로 잡았기 때문에 디테일한 처리 필요하여 차지하고 있는 가로 값 저장 후 비교
		return;
	++m_tPos.x;
}