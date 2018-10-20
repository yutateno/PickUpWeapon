#pragma once
#include "DxLib.h"

class Doll
{
private:
	int gr_right[8];	// 右の画像
	int gr_left[8];	// 左の画像
	int gr_up[8];	// 上の画像
	int gr_down[8];	// 下の画像

	int x;	// x座標
	int y;	// y座標
	int direction;		// 0右1下2左3上
	int speed;	// 移動速度
	int timelimit;

	int targetX;	// ターゲット位置
	int targetY;	// ターゲット位置
	int targetnP;

	int animcount;	// アニメーションカウント
	int animspeed;	// アニメーションフレーム
	bool anim;	// 何もぶつからず移動できているか
	bool diremove;	// ぶつかったら向きを切り替える
	int hitwait;

public:
	Doll();		// コンストラクタ
	Doll(int x, int y, int direction, int targetX, int targetY, int targetnP);		// コンストラクタ
	~Doll();	// デストラクタ

	int hp;
	bool hit;

	void Move();	// 移動

	void Draw();	// 描画

	void SetDire();	// ぶつかったら向きを切り替える

	void SetXY(int targetX, int targetY);		// ターゲットをつねに更新
	int GetX();		// X座標
	int GetY();		// Y座標
	bool GetAttack();
	int GetLimit();
	int GetTargetP();
};