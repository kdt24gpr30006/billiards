#include "CheckInput.h"

void CheckInputKey::Update()
{
	// �S�ẴL�[�̓��͏�Ԃ𓾂�
	GetHitKeyStateAll(Key_buffer);
	for (int i = 0; i < KEY_NUM; i++)
	{
		if (Key_buffer[i] != 0)
		{
			// �R�[�h�ɑΉ�����L�[��������Ă����瑝�₷
			key_push_fream[i]++;
		}
		else
		{
			if (key_push_fream[i] > 0)
			{
				// �����ꂽ�u�Ԃ���-1�ɂ���
				key_push_fream[i] = -1;
			}
			else
			{
				// ������Ă��Ȃ����0�ɂ���
				key_push_fream[i] = 0;
			}
		}
	}
}

bool CheckInputKey::PushHitKey(int key)
{
	if (key_push_fream[key] == 1)
	{
		return true;
	}
	return false;
}

bool CheckInputKey::ReleaseHitKey(int key)
{
	if (key_push_fream[key] == -1)
	{
		return true;
	}
	return false;
}
