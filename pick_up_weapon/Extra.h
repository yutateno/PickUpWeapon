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

	vector<Bullet*>bullet;		// �e�̋�

	int gr_back;

	int sniper_se;
	int damage_se;

	int bulletinterval;	// �ʂ̊Ԋu
	int sniperspeed;	// �X�i�C�p�[�̒e��

	bool great;
	
	void Draw();
	void Process();

	// �e�̐����Ɋւ���
	void BulletForm();		// �ʐ���
	void BulletColl();		// �ʂ̂����蔻��

	bool endreturnflag;

public:
	Extra();			// �R���X�g���N�^
	~Extra();		// �f�X�g���N�^

	void Update();	// �V�[���ŌĂ΂��
};