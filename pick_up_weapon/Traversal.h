#pragma once
#include "DxLib.h"

class Traversal
{
private:
	int gr_wait;	// 捕まえる前画像
	int gr_catch;	// 捕まえた後

	int se_traversal;	// 音

	int x;	// x座標
	int y;	// y座標

	int traversalframe;

public:
	Traversal();		// コンストラクタ
	Traversal(int x, int y, int direction);		// コンストラクタ
	~Traversal();	// デストラクタ

	bool catchflag;
	int nP;

	void Draw();	// 描画

	int GetX();		// X座標
	int GetY();		// Y座標
	int GetFrame();
};