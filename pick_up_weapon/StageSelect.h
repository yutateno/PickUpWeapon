#pragma once
#include "Scene.h"

class StageSelect : public Scene
{
private:
	int gr_back;	// 背景
	int gr_one;		// １つ目のステージ
	int gr_two;		// ２つ目のステージ
	int gr_three;	// ３つ目のステージ

public:
	StageSelect();	// コンストラクタ
	~StageSelect();	// デストラクタ

	void Update();	// 更新

	void Process();	// プロセス

	void Draw();	// 描画
};