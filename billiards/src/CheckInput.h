#pragma once

#include "dxlib.h"

class CheckInputKey
{
#define KEY_NUM 256

	// �L�[�̓��͏��
	char Key_buffer[KEY_NUM];
	// �L�[�̉�����Ă��鎞��
	int key_push_fream[KEY_NUM];
public:

	// �R���X�g���N�^�[
	CheckInputKey()
	{
		for (int i = 0; i < KEY_NUM; ++i)
		{
			Key_buffer[i] = 0;
			key_push_fream[i] = 0;
		}
	}

	/// <summary>
	/// ���͏�Ԃ��X�V
	/// </summary>
	void Update();

	/// <summary>
	/// �����ꂽ�u�Ԃ��擾
	/// </summary>
	/// <param name="key"><�m�F�������L�[/param>
	/// <returns><true:�����ꂽ false:������Ă��Ȃ�/returns>
	bool PushHitKey(int key);

	/// <summary>
	/// �������u�Ԃ��擾
	/// </summary>
	/// <param name="key"><�m�F�������L�[/param>
	/// <returns><true:�����ꂽ false:������Ă��Ȃ�/returns>
	bool ReleaseHitKey(int key);
};