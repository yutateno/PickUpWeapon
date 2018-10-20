#pragma once
#include "Scene.h"
#include "Character.h"
#include "Character_Sniper.h"
#include "Character_Knife.h"
#include "Bullet.h"
#include <vector>

using namespace std;

class Extra : public Scene
{
private:
	Character* characterAttack;
	Character* characterDefence;

	vector<Bullet*>bullet;		// 銃の玉

	int gr_back;

	int sniper_se;
	int damage_se;

	int bulletinterval;	// 玉の間隔
	int sniperspeed;	// スナイパーの弾速

	bool great;
	
	void Draw();
	void Process();

	// 弾の生成に関して
	void BulletForm();		// 玉生成
	void BulletColl();		// 玉のあたり判定

	bool endreturnflag;

public:
	Extra();			// コンストラクタ
	~Extra();		// デストラクタ

	void Update();	// シーンで呼ばれる
};