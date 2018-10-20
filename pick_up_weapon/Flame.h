#pragma once
#include "DxLib.h"

class Flame
{
private:
	int gr_move[4];		// 移動画像
	int gr_flame[4];	// 着火画像

	int se_flame;

	int direction;	// 向き
	int speed;	// 速度

	int moveframe;	// 移動
	int animcount;	// アニメーションカウント
	int animspeed;	// アニメーションフレーム

	int x;	// X座標
	int y;	// Y座標

public:
	Flame();	// コンストラクタ
	Flame(int x, int y, int direction);	// コンストラクタ
	~Flame();	// デストラクタ

	bool wallhit;

	void Move();	// 移動
	void Draw();	// 描画

	int GetX();		// X座標
	int GetY();		// Y座標
	int GetFrame();
	int GetDire();
};