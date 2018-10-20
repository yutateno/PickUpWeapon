#pragma once
#include "DxLib.h"

class Bomb
{
private:
	int gr[5];	// 画像

	int se_bomb;	// 音

	int x;	// x座標
	int y;	// y座標
	int direction;		// 0右1下2左3上

	int animcount;	// アニメーションカウント
	int animspeed;	// アニメーションフレーム

	int bombframe;

public:
	Bomb();		// コンストラクタ
	Bomb(int x, int y, int direction);		// コンストラクタ
	~Bomb();	// デストラクタ

	void Draw();	// 描画

	int GetX();		// X座標
	int GetY();		// Y座標
	int GetFrame();
};