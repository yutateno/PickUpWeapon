#pragma once
#include "Character.h"

class Character_Bomb : public Character
{
private:
	int gr_forward[8];			// 前向き
	int gr_backward[4];			// 後ろ向き
	int gr_side[8];			// 右向き
	int gr_bomb_estimation;	// 予測位置

	int bombX, bombY;

public:
	Character_Bomb();		// コンストラクタ
	Character_Bomb(int x, int y, int hp, int nP, int direction);		// 座標と体力とプレイヤーナンバーと向きを引数に取るコンストラクタ
	~Character_Bomb();		//デストラクタ

	void Process();		// プロセス

	void Draw();		// 描画
};