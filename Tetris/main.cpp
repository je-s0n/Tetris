#include "Core.h"
int main()
{
	if (!CCore::GetInst()->Init()) // �ʱ�ȭ ����
	{
		CCore::DestroyInst();
		return 0;
	}

	CCore::GetInst()->Run();
	CCore::DestroyInst();
	return 0;
}
