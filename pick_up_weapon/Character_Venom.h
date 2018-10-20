#pragma once
#include "Character.h"

class Character_Venom : public Character
{
private:
	int gr_forward[8];			// 前向き
	int gr_backward[4];			// 後ろ向き
	int gr_right[8];			// 右向き
	int gr_left[8];				// 左向き
	int gr_venom_estimation;	// 予測位置

	int venomX, venomY;

public:
	Character_Venom();		// コンストラクタ
	Character_Venom(int x, int y, int hp, int nP, int direction);		// 座標と体力とプレイヤーナンバーと向きを引数に取るコンストラクタ
	~Character_Venom();		//デストラクタ

	void Process();		// プロセス

	void Draw();		// 描画
};