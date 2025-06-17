#pragma once

#include <ctime>		// �W��C ���C�u���� �w�b�_�[ <time.h> ���C���N���[�h���A�֘A���閼�O�� std ���O��Ԃɒǉ����܂��B
#include "DxLib.h"		// DxLib
#include "CheckInput.h"

//	�萔�̐錾
const int WINDOW_W = 1280;	// ��ʃT�C�Y�@��
const int WINDOW_H = 720;	// ��ʃT�C�Y�@�c

/// <summary>
/// �Q�[���֌W
/// </summary>
class Game
{
	/// <summary>
	/// ���͏����֐�
	/// </summary>
	void input();

	/// <summary>
	/// ��ʍX�V�֐�
	/// </summary>
	void render();

	/// <summary>
	/// �����Đ������֐�
	/// </summary>
	void sound();
public:

	CheckInputKey Check_input_key;

	Game()
	{

	}

	/// <summary>
	/// �������֐�
	/// </summary>
	/// <returns><����:true, ���s:false/returns>
	bool Init();

	/// <summary>
	/// �X�V�֐�
	/// </summary>
	void Loop();

	/// <summary>
	/// �I���֐�
	/// </summary>
	void End();

	virtual ~Game()
	{

	}
};