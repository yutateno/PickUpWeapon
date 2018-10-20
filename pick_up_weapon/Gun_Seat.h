#pragma once
#include "DxLib.h"

class Gun_Seat
{
private:
	int gr_up[2];			// 上の画像
	int gr_down[2];			// 下の画像
	int gr_side[2];			// 左右の画像

	int x;	// X座標
	int y;	// Y座標
	int direction;			// 0右1下2左3上
	int waitcount;	// 撃ち初めまでの待機
	int gunframe;	// フレーム

	int animcount;	// アニメーションのカウント
	int animspeed;	// アニメーションのスピード

public:
	Gun_Seat();	// コンストラクタ
	Gun_Seat(int x, int y, int direction);		// コンストラクタ
	~Gun_Seat();	// デストラクタ

	int gunnum;	// 弾数
	int hp;

	void Do();		// 実行
	void Draw();	// 描画

	int GetDire();	// 向き
	int GetX();		// X座標
	int GetY();		// Y座標
	int GetShot();	// ガンフレーム
};