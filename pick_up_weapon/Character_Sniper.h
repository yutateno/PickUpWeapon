#pragma once
#include "Character.h"

class Character_Sniper : public Character
{
private:
	int gr_forward[4];			// 前向き
	int gr_backward[4];			// 後ろ向き
	int gr_right[4];			// 右向き
	int gr_left[4];				// 左向き
	int gr_shoot_forward[2];	// 前撃ち中
	int gr_shoot_right[2];		// 右撃ち中
	int gr_shoot_left[2];		// 左撃ち中

	int reload_se;
	
	int waitcount;

public:
	Character_Sniper();		// コンストラクタ
	Character_Sniper(int x, int y, int hp, int nP, int direction);		// 座標と体力とプレイヤーナンバーと向きを引数に取るコンストラクタ
	~Character_Sniper();		//デストラクタ

	void Process();		// プロセス

	void Draw();		// 描画
};