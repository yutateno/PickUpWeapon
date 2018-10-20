#pragma once
#include "Character.h"

class Character_Traversal : public Character
{
private:
	int gr_forward[8];		// 前向き
	int gr_backward[4];		// 後ろ向き
	int gr_right[8];		// 右向き
	int gr_left[8];			// 左向き

public:
	Character_Traversal();		// コンストラクタ
	Character_Traversal(int x, int y, int hp, int nP, int direction);		// 座標と体力とプレイヤーナンバーと向きを引数に取るコンストラクタ
	~Character_Traversal();		//デストラクタ

	void Process();		// プロセス

	void Draw();		// 描画
};