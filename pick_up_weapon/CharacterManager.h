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
	// �摜
	int gr_hp_cover;
	int gr_startcount[6];

	int gr_start_black;	// �ŏ�

	int gr_draw;

	// ���y
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
	int dropnum;		// �h���b�v��
	int count;		// �����镐��̐����J�E���g
	int effectcount;	// �����Ă镐��̃G�t�F�N�g
	int gatlingcount;		// �K�g�����O�̏����ҋ@����
	int bulletinterval;	// �ʂ̊Ԋu
	int gatlingspeed;	// �K�g�����O�̒e��
	int sniperspeed;	// �X�i�C�p�[�̒e��
	int gunseatspeed;	// �e���̒e��

	int starttime;
	int startblendframe;
	bool endflag;	// �I���t���b�O
	bool endtotitle;
	int endframe;

	int timer;
	int timeframe;

	Map* map;				// �}�b�v

	// �L�����N�^�[
	struct CharacterS {
		Character* character;		// �L�����N�^�[
		int gr_hpbar;				// �̗̓o�[
		int gr_lose[28];			// �s�k�摜
		int gr_win;					// �����摜
		int ID;						// �����ID
		int hp;						// HP
		int prehp;					// ���O�̗̑�
		int hp_shield;				// �V�[���h���̗̑�
		int x;						// x���W
		int y;						// y���W
		int direction;				// ����[0�E�A1���A2���A3��]
		int dropID;					// �h���b�v��ID
		int chara;					// �L�����N�^�[�̎��[0Normal 1Sword 2Gatling 3Gun]
		int knifeframe;				// �i�C�t�Ԋu
		bool venomflag;				// �ŃK�X�ɓ����������ǂ���
		int venomframe;				// �ŃK�X�̌p���_���[�W
		bool bombhit;				// ��������̂ň�񂾂��ɂ��锚�e
		bool flamemovehit;			// �ړ����̉΂ɓ�������
		bool traversalcatch;		// �g���o�T�~�ɂ��܂���
		int loseframe;				// �����摜�̃t���[��
		int losecount;				// �����摜�̃J�E���g
		int gunspeed;					// �e�̑��x
	};
	CharacterS character[4];

	int playernum;

	struct DropS {
		Drop* drop;
		bool dropflag;	// �l�Ɏ���Ēn�ʂɂȂ����ǂ���
	};
	DropS drop[13];

	random_device rnd;     // �񌈒�I�ȗ���������𐶐�

	vector<Bullet*>bullet;		// �e�̋�

	vector<Obstacle*>obstacle;	// ����ǌn

	vector<Doll*>doll;	// �l�`

	vector<Gun_Seat*>gunseat;	// �e��

	vector<Venom*>venom;		// �ŕr

	vector<Bomb*>bomb;		// ���e

	vector<Flame*>flame;	// ��

	vector<Traversal*>traversal;	// �g���o�T�~

	// ��{
	void Process();		// �v���Z�X

	void Draw();		// �`��

	void TwoUpdate();
	void ThreeUpdate();
	void FourUpdate();
	
	// �L�����N�^�[�̊�{�I�ȕ���
	void CharacterProcess();


	// �����Drop�Ɋւ���
	void DropWeaponInit();		// ����𗎂Ƃ�����
	void DropWeapon();			// ����𗎂Ƃ�����

	// �L�����̃W���u�ύX�Ɋւ���
	void Change(CharacterS character[], int nP);			// �L�����ύX

	// �e�̐����Ɋւ���
	void BulletForm();		// �ʐ���
	void BulletColl();		// �ʂ̂����蔻��

	// �}�b�v���̕ǂɊւ���
	void ObstacleInit();	// ����n�ǂ̐���

	// �i�C�t�Ɋւ���
	void KnifeProcess();

	// ���Ɋւ���
	void SwordProcess();

	// ���Ɋւ���
	void FlameProcess();

	// ���e�Ɋւ���
	void BombProcess();

	// �ŕr�Ɋւ���
	void VenomProcess();

	// �e���Ɋւ���
	void GunSeatProcess();

	// �l�`�Ɋւ���
	void DollProcess();

	// �g���o�T�~�Ɋւ���
	void TraversalProcess();

	// ���Ɋւ���
	void ShieldProcess();

public:
	CharacterManager(int playmode, int nowmode);		// �R���X�g���N�^
	~CharacterManager();	// �f�X�g���N�^

	void Update();	// �X�V
	
	bool GetEnd();	// �I��

	bool GetToTitle();
};