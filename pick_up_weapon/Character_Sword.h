#pragma once
#include "Character.h"

class Character_Sword : public Character
{
private:
	int gr_forward[8];			// 前向き
	int gr_backward[4];			// 後ろ向き
	int gr_right[8];			// 右向き
	int gr_left[8];				// 左向き
	int gr_attack_forward[2];	// 前振り
	int gr_attack_backward[2];	// 後ろ振り
	int gr_attack_right[2];		// 右振り
	int gr_attack_left[2];		// 左振り
	int gr_afterimage[2];		// 残像
	bool attackflag;
	int attackframe;

public:
	Character_Sword();		// コンストラクタ
	Character_Sword(int x, int y, int hp, int nP, int direction);		// 座標と体力とプレイヤーナンバーと向きを引数に取るコンストラクタ
	~Character_Sword();	// デストラクタ

	void Process();		// プロセス

	void Draw();		// 描画
};