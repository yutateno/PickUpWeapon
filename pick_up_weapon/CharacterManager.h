#pragma once
#include "Character.h"
#include "Character_Normal.h"
#include "Character_Gatling.h"
#include "Character_Doll.h"
#include "Character_Sniper.h"
#include "Character_GunSeat.h"
#include "Character_Knife.h"
#include "Character_Sword.h"
#include "Character_Venom.h"
#include "Character_Bomb.h"
#include "Character_Flame.h"
#include "Character_Traversal.h"
#include "Character_Shield.h"
#include "Obstacle.h"
#include "Map.h"
#include "Drop.h"
#include "Bullet.h"
#include "Doll.h"
#include "Gun_Seat.h"
#include "Venom.h"
#include "Bomb.h"
#include "Flame.h"
#include "Traversal.h"
#include <random>

class CharacterManager
{
private:
	// 画像
	int gr_hp_cover;
	int gr_startcount[6];

	int gr_start_black;	// 最初

	int gr_draw;

	// 音楽
	int game_bgm;
	int win_bgm;
	int gatling_se;
	int sniper_se;
	int damage_se;
	int gunseat_se;
	int gunseatend_se;
	int doll_se;
	int knife_se;
	int shield_se;
	bool end_bgm_flag;

	int playmode;
	int dropnum;		// ドロップ数
	int count;		// 落ちる武器の生成カウント
	int effectcount;	// 落ちてる武器のエフェクト
	int gatlingcount;		// ガトリングの初期待機時間
	int bulletinterval;	// 玉の間隔
	int gatlingspeed;	// ガトリングの弾速
	int sniperspeed;	// スナイパーの弾速
	int gunseatspeed;	// 銃座の弾速

	int starttime;
	int startblendframe;
	bool endflag;	// 終了フラッグ
	bool endtotitle;
	int endframe;

	int timer;
	int timeframe;

	Map* map;				// マップ

	// キャラクター
	struct CharacterS {
		Character* character;		// キャラクター
		int gr_hpbar;				// 体力バー
		int gr_lose[28];			// 敗北画像
		int gr_win;					// 勝利画像
		int ID;						// 武器のID
		int hp;						// HP
		int prehp;					// 直前の体力
		int hp_shield;				// シールド時の体力
		int x;						// x座標
		int y;						// y座標
		int direction;				// 方向[0右、1下、2左、3上]
		int dropID;					// ドロップのID
		int chara;					// キャラクターの種類[0Normal 1Sword 2Gatling 3Gun]
		int knifeframe;				// ナイフ間隔
		bool venomflag;				// 毒ガスに当たったかどうか
		int venomframe;				// 毒ガスの継続ダメージ
		bool bombhit;				// 強すぎるので一回だけにする爆弾
		bool flamemovehit;			// 移動中の火に当たった
		bool traversalcatch;		// トラバサミにつかまった
		int loseframe;				// 負け画像のフレーム
		int losecount;				// 負け画像のカウント
		int gunspeed;					// 弾の速度
	};
	CharacterS character[4];

	int playernum;

	struct DropS {
		Drop* drop;
		bool dropflag;	// 人に取られて地面にないかどうか
	};
	DropS drop[13];

	random_device rnd;     // 非決定的な乱数生成器を生成

	vector<Bullet*>bullet;		// 銃の玉

	vector<Obstacle*>obstacle;	// 壊れる壁系

	vector<Doll*>doll;	// 人形

	vector<Gun_Seat*>gunseat;	// 銃座

	vector<Venom*>venom;		// 毒瓶

	vector<Bomb*>bomb;		// 爆弾

	vector<Flame*>flame;	// 炎

	vector<Traversal*>traversal;	// トラバサミ

	// 大本
	void Process();		// プロセス

	void Draw();		// 描画

	void TwoUpdate();
	void ThreeUpdate();
	void FourUpdate();
	
	// キャラクターの基本的な部分
	void CharacterProcess();


	// 武器のDropに関して
	void DropWeaponInit();		// 武器を落とす処理
	void DropWeapon();			// 武器を落とす処理

	// キャラのジョブ変更に関して
	void Change(CharacterS character[], int nP);			// キャラ変更

	// 弾の生成に関して
	void BulletForm();		// 玉生成
	void BulletColl();		// 玉のあたり判定

	// マップ内の壁に関して
	void ObstacleInit();	// 壊れる系壁の生成

	// ナイフに関して
	void KnifeProcess();

	// 剣に関して
	void SwordProcess();

	// 炎に関して
	void FlameProcess();

	// 爆弾に関して
	void BombProcess();

	// 毒瓶に関して
	void VenomProcess();

	// 銃座に関して
	void GunSeatProcess();

	// 人形に関して
	void DollProcess();

	// トラバサミに関して
	void TraversalProcess();

	// 盾に関して
	void ShieldProcess();

public:
	CharacterManager(int playmode, int nowmode);		// コンストラクタ
	~CharacterManager();	// デストラクタ

	void Update();	// 更新
	
	bool GetEnd();	// 終了

	bool GetToTitle();
};