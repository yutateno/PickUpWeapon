#pragma once
#include "Character.h"

class Character_GunSeat : public Character
{
private:
	int gr_forward[8];		// 前向き
	int gr_backward[4];		// 後ろ向き
	int gr_side[8];			// 横向き

public:
	Character_GunSeat();		// コンストラクタ
	Character_GunSeat(int x, int y, int hp, int nP, int direction);		// 座標と体力とプレイヤーナンバーと向きを引数に取るコンストラクタ
	~Character_GunSeat();		//デストラクタ

	void Process();		// プロセス

	void Draw();		// 描画
};