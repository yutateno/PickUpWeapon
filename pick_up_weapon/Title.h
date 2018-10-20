#pragma once
#include "Scene.h"

class Title : public Scene
{
private:
	int gr_back;	// 背景
	int gr_two;		// 二人用
	int gr_three;	// 三人用
	int gr_four;	// 四人用
	int gr_end;		// 終了
	int gr_extra;

	int gr_icon_two[2];			// 2Pアイコン
	int gr_icon_three[2];		// 3Pアイコン
	int gr_icon_four[2];		// 4Pアイコン
	int gr_icon_end[8];			// endアイコン
	int gr_icon_endclick[5];	// endアイコン

	bool extraflag;

	bool clickflag;

public:
	Title();	// コンストラクタ
	~Title();	// デストラクタ
	
	void Update();	// 更新

	void Process();	// プロセス

	void Draw();	// 描画
};