#include "Game.h"

void Game::input()
{
}

void Game::render()
{
}

void Game::sound()
{
}

bool Game::Init()
{
	// ���̃N���X��nullptr�ɂ���Ă��珈�����Ȃ�
	if (this == nullptr)
	{
		return false;
	}

	// ���O�̏����o���𖳌���
	SetOutApplicationLogValidFlag(FALSE);	// ���O�̏����o���𖳌���

	// �E�B���h�E���[�h�̐ݒ�
	ChangeWindowMode(TRUE);					// �E�C���h�E���[�h��L����

	// �E�B���h�E�T�C�Y�ƃJ���[�r�b�g�̐ݒ�
	SetGraphMode(WINDOW_W, WINDOW_H, 32);

	// �E�B���h�E�̃^�C�g��
	SetMainWindowText("DxLib Template");

	// �w�i�F�̐ݒ�
	SetBackgroundColor(128, 128, 128);

	// �E�B���h�E�`�惂�[�h�ݒ�
	SetDrawScreen(DX_SCREEN_BACK);			// ����ʂɕ`�悷��

	// �c�w���C�u��������������
	if (DxLib_Init() == -1)
	{
		return false;						// �G���[���N�����璼���ɏI��
	}

	return true;
}

void Game::Loop()
{
	while (ProcessMessage() == 0)
	{
		// ���t���b�V�����[�g��ݒ肷�邽�߂̏���
		clock_t check_fps = clock() + CLOCKS_PER_SEC / 60;

		// �}�E�X�J�[�\���\���ݒ�
		SetMouseDispFlag(TRUE);

		// printfDx�̏�����
		clsDx();

		// ��ʏ�̕`����������i��ʂ������j
		ClearDrawScreen();


		//  ���͏���
		this->input();
		Check_input_key.Update();

		//  ��ʕ`�揈��
		this->render();


		//  �����Đ�����
		this->sound();


		// ���t���b�V�����[�g�����ɂȂ�܂ő҂���
		while (clock() < check_fps) {}

		// ����ʂ̕`���\�ɔ��f
		ScreenFlip();


		// ESC�L�[�Ń��[�v���甲����
		if (CheckHitKey(KEY_INPUT_ESCAPE)) {
			break;
		}

	}
}

void Game::End()
{
	// �c�w���C�u�����g�p�̏I������
	DxLib_End();							// �c�w���C�u�����g�p�̏I������
}
