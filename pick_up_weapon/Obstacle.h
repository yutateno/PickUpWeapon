#pragma once
#include "DxLib.h"

class Obstacle
{
private:
	int capsule[6];					// マップ上にあるカプセルブロック
	int capsule_break[13];	// マップ上にある壊れる最中のカプセルブロック
	int capsule_broken;	// マップ上にある壊れたカプセルブロック
	int rock;						// マップ上にある岩ブロック
	int rock_break[11];		// マップ上にある壊れる最中の岩ブロック
	int rock_broken;		// マップ上にある壊れた岩ブロック

	int animcount;					// 壊れるブロックのフレーム
	int animbreakcount;					// 壊れるブロックのフレーム
	int breakcount;					// 壊れるブロックのフレーム
	int animspeed;		// アニメーションスピード

	int ID;		// 配置するもののID

	int x;
	int y;	// 座標

	bool brokenflag;		// 壊れたかどうか
	bool breakflag;			// 壊れている最中かどうか


public:
	Obstacle();		// コンストラクタ
	Obstacle(int ID, int x, int y);	// コンストラクタ
	~Obstacle();		// デストラクタ

	void Draw_Normal();	// 通常時の描画
	void Draw_Break();	// 壊れている最中の描画
	void Draw_Broken();	// 壊れた時の描画

	bool hitflag;		// ダメージを受け始めたかどうか

	// ゲッター
	bool GetBrokenFlag();		// 壊れたフラッグ
	bool GetBreakFlag();		// 壊れているフラッグ
	int GetX();		// X座標
	int GetY();		// Y座標
	int GetID();	// ID
	int GetHowBreak();		// どのくらい壊れているか
};