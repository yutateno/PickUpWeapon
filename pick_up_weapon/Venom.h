#pragma once
#include "DxLib.h"

class Venom
{
private:
	int gr[3];	// 画像

	int se_venom;	// 音

	int x;	// x座標
	int y;	// y座標
	int direction;		// 0右1下2左3上

	int animcount;	// アニメーションカウント
	int animspeed;	// アニメーションフレーム

	int venomframe;

public:
	Venom();		// コンストラクタ
	Venom(int x, int y, int direction);		// コンストラクタ
	~Venom();	// デストラクタ
	
	void Draw();	// 描画

	int GetX();		// X座標
	int GetY();		// Y座標
	int GetFrame();
};