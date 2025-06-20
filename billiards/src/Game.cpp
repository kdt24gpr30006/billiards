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
	// このクラスがnullptrにされてたら処理しない
	if (this == nullptr)
	{
		return false;
	}

	// ログの書き出しを無効化
	SetOutApplicationLogValidFlag(FALSE);	// ログの書き出しを無効化

	// ウィンドウモードの設定
	ChangeWindowMode(TRUE);					// ウインドウモードを有効化

	// ウィンドウサイズとカラービットの設定
	SetGraphMode(WINDOW_W, WINDOW_H, 32);

	// ウィンドウのタイトル
	SetMainWindowText("DxLib Template");

	// 背景色の設定
	SetBackgroundColor(128, 128, 128);

	// ウィンドウ描画モード設定
	SetDrawScreen(DX_SCREEN_BACK);			// 裏画面に描画する

	// ＤＸライブラリ初期化処理
	if (DxLib_Init() == -1)
	{
		return false;						// エラーが起きたら直ちに終了
	}

	return true;
}

void Game::Loop()
{
	while (ProcessMessage() == 0)
	{
		// リフレッシュレートを設定するための処理
		clock_t check_fps = clock() + CLOCKS_PER_SEC / 60;

		// マウスカーソル表示設定
		SetMouseDispFlag(TRUE);

		// printfDxの初期化
		clsDx();

		// 画面上の描画を初期化（画面を消去）
		ClearDrawScreen();


		//  入力処理
		this->input();
		Check_input_key.Update();

		//  画面描画処理
		this->render();


		//  音声再生処理
		this->sound();


		// リフレッシュレートが一定になるまで待つ処理
		while (clock() < check_fps) {}

		// 裏画面の描画を表に反映
		ScreenFlip();


		// ESCキーでループから抜ける
		if (CheckHitKey(KEY_INPUT_ESCAPE)) {
			break;
		}

	}
}

void Game::End()
{
	// ＤＸライブラリ使用の終了処理
	DxLib_End();							// ＤＸライブラリ使用の終了処理
}
