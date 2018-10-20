#pragma once
#include "Character.h"

class Character_Gatling : public Character
{
private:
	int gr_forward[8];			// 前向き
	int gr_backward[4];			// 後ろ向き
	int gr_right[8];			// 右向き
	int gr_left[8];				// 左向き
	int gr_shoot_forward[2];	// 前撃ち中
	int gr_frame_forward[2];	// 前溜め中
	int gr_shoot_backward[2];	// 後ろ撃ち中
	int gr_shoot_right[2];		// 右撃ち中
	int gr_frame_right[2];		// 右溜め中
	int gr_shoot_left[2];		// 左撃ち中
	int gr_frame_left[2];		// 左溜め中

public:
	Character_Gatling();		// コンストラクタ
	Character_Gatling(int x, int y, int hp, int nP, int direction);		// 座標と体力とプレイヤーナンバーと向きを引数に取るコンストラクタ
	~Character_Gatling();		//デストラクタ

	void Process();		// プロセス

	void Draw();		// 描画
};