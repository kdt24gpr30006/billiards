// =======================================
//  ライブラリ読込
// =======================================
#include "Game.h"

// ------------------------------
// WinMain
// ------------------------------
/// <summary>
/// WinMain関数
/// </summary>
/// <param name="hInstance"><インスタンスハンドル/param>
/// <param name="hPrevInstance"><意味はない/param>
/// <param name="lpCmdLine"></param>
/// <param name="nShowCmd"></param>
/// <returns></returns>
int WINAPI WinMain(_In_ HINSTANCE hInstance, _In_opt_  HINSTANCE hPrevInstance, _In_ LPSTR lpCmdLine, _In_ int nShowCmd)
{

	// =======================================
	//  初期化処理
	// =======================================
	Game* gamePtr = new Game;
	gamePtr->Init();

	// Init()がfalseで帰ってきたらその時点で終了
	if (gamePtr->Init() == false)
	{
		return -1;
	}

	// ------------------------------
	//  ゲームループ
	// ------------------------------
	gamePtr->Loop();

	// =======================================
	//  終了処理
	// =======================================
	gamePtr->End();

	// ゲームオブジェクト削除
	if (gamePtr != nullptr)
	{
		delete gamePtr;
		gamePtr = nullptr;
	}

	// ソフトの終了
	return 0;
}