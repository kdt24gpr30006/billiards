// =======================================
//  ���C�u�����Ǎ�
// =======================================
#include "Game.h"

// ------------------------------
// WinMain
// ------------------------------
/// <summary>
/// WinMain�֐�
/// </summary>
/// <param name="hInstance"><�C���X�^���X�n���h��/param>
/// <param name="hPrevInstance"><�Ӗ��͂Ȃ�/param>
/// <param name="lpCmdLine"></param>
/// <param name="nShowCmd"></param>
/// <returns></returns>
int WINAPI WinMain(_In_ HINSTANCE hInstance, _In_opt_  HINSTANCE hPrevInstance, _In_ LPSTR lpCmdLine, _In_ int nShowCmd)
{

	// =======================================
	//  ����������
	// =======================================
	Game* gamePtr = new Game;
	gamePtr->Init();

	// Init()��false�ŋA���Ă����炻�̎��_�ŏI��
	if (gamePtr->Init() == false)
	{
		return -1;
	}

	// ------------------------------
	//  �Q�[�����[�v
	// ------------------------------
	gamePtr->Loop();

	// =======================================
	//  �I������
	// =======================================
	gamePtr->End();

	// �Q�[���I�u�W�F�N�g�폜
	if (gamePtr != nullptr)
	{
		delete gamePtr;
		gamePtr = nullptr;
	}

	// �\�t�g�̏I��
	return 0;
}