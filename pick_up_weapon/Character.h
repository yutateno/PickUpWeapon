#pragma once
#include "DxLib.h"
#include "Input.h"

class Character
{
protected:
	int x;					// x座標
	int y;					// y座標
	int prex;				// 直前のx座標
	int prey;				// 直前のy座標
	int hp;				// 体力
	int speed;				// スピード
	int nP;					// プレイヤーナンバー
	int direction;			// 方向[0右、1下、2左、3上]
	int startwaitcount;

	int animcount;		// アニメーションカウント
	int animspeed;		// アニメーションスピード

	// コントローラー
	DINPUT_JOYSTATE input;		// コントローラー
	int RTbutton;								// RTボタン
	int gatlingframe;							// ガトリングの弾フレーム
	int sniperframe;						// スナイパーの弾フレーム
	int RBframe;
	int LBframe;
	int Aframe;

	// 基本移動操作
	void MoveControl();

	// デバッグ
	void MoveControl2();				// 2P

public:
	Character();					// コンストラクタ

	virtual ~Character() {};		// デストラクタ

	virtual void Process() = 0;		// プロセス

	virtual void Draw() = 0;		// 描画


	void MoveReset();				// 直前に戻す

	int tamanum;		// 打てる球の数

	// ゲッター
	int GetX();						// X座標
	int GetY();						// Y座標
	int GetDire();					// 向き
	int GetRTbutton();				// RTボタン
	int GetAbutton();				// Aボタン
	int GetRBbutton();				// RBボタン
	int GetLBbutton();
};