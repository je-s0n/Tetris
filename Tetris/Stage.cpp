#include "Stage.h"

CStage::CStage()
{
}


CStage::~CStage()
{
}

bool CStage::Init()
{
	memset(m_Stage, 0, STAGE_WIDTH * STAGE_HEIGHT);
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
				cout << "■";
			else cout << "  "; // 두 칸으로 해야 함
		}
		cout << endl;
	}
}