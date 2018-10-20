#pragma once
#include "DxLib.h"

class Drop
{
private:
	int Gr;			// 画像

	int x;
	int y;		// 座標
	int ID;			// どの武器か

public:
	Drop();		// コンストラクタ
	Drop(int x, int y, int ID);		// 座標とIDを引数に取るコンストラクタ
	~Drop();		// デストラクタ

	void Draw();	// 描画

	// ゲッター
	int GetX();
	int GetY();
	int GetID();
};