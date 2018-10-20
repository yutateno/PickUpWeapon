#pragma once
#include "DxLib.h"

class Bullet
{
private:
	int gr;	// 画像

	int direction;	// 向き
	int speed;	// 速度

	int x;	// X座標
	int y;	// Y座標
	int power;

public:
	Bullet();	// コンストラクタ
	Bullet(int x, int y, int direction, int speed, int power);	// コンストラクタ
	~Bullet();	// デストラクタ

	void Move();	// 移動
	void Draw();	// 描画

	int GetX();		// X座標
	int GetY();		// Y座標
	int GetPower();
	int GetDire();
};