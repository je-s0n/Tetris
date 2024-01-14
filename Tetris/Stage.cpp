#include "Stage.h"
#include "Core.h"
#include "Shape.h"

CStage::CStage() : m_iSpeed(2)
{
}


CStage::~CStage()
{
}

void CStage::AddBlock(class CShape* pShape, const POSITION& tPos)
{
	for (int i = 0; i < 4; ++i)
	{
		for (int j = 0; j < 4; ++j)
		{
			// 블록일 경우
			if (pShape->GetBlock(j, i) == '0')
			{
				m_Stage[tPos.y - (3-i)][tPos.x + j] = '0';

				bool bLine = true;
				// 현재 라인을 체크하여 가득 차있으면 한줄 제거한 후 그 외 차있는 모든 줄을 한 칸씩 내려준다.
				for (int k = 0; k < STAGE_WIDTH; ++k)
				{
					if (m_Stage[tPos.y - (3 - i)][k] != '0') {
						bLine = false;
						break;
					}
				}

				if (bLine)
				{
					for (int k = tPos.y-(3-i); k > 0; --k)
					{
						for (int l = 0; l < STAGE_WIDTH; ++l) {
							m_Stage[k][l] = m_Stage[k - 1][l];
						}
					}
				}
			}
		}
	}
};

bool CStage::CheckBlock(int x, int y)
{
	if (y >= STAGE_HEIGHT) // 바닥에 닿았을 때 true 리턴
		return true;
	else if (x < 0 || x >= STAGE_WIDTH)
		return true;
	return m_Stage[y][x] == '0';
}

bool CStage::Init()
{
	for (int i = 0; i < STAGE_HEIGHT; ++i)
	{
		for (int j = 0; j < STAGE_WIDTH; ++j)
		{
			m_Stage[i][j] = '1';
		}
	}
	return true;
}

void CStage::Render()
{
	// 비어있는 공간 외부를 공간으로 감싸줌
	for (int i = 0; i < STAGE_HEIGHT + 1; ++i) // 가로/세로 모두 두 칸이 늘어나야 함
	{
		for (int j = 0; j < STAGE_WIDTH + 2; ++j)
		{
			if (i == 0 && (j==0 || i== STAGE_WIDTH + 1))
				cout << "■";
			else if (j == 0)
				cout << "■";
			else if (i == STAGE_HEIGHT)
				cout << "■";
			else if (j == STAGE_WIDTH + 1)
				cout << "■"; // 2Byte
			else {
				if(m_Stage[i][j-1] == '1')
					cout << "  "; // 2Byte짜리라서 공백 두 칸으로 해야 함
				else cout << "■";
			}
		}
		cout << endl;
	}

	// 다음 도형을 보여주기 위한 공간 설정
	for (int i = 0; i < 7; ++i) {
		CCore::GetInst()->SetConsolePos(17, i);
		cout << "■";
	}

	for (int i = 0; i < 6; ++i) {
		CCore::GetInst()->SetConsolePos(11 + i, 6);
		cout << "■";
	}
}
