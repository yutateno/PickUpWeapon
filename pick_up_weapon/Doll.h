#pragma once
#include "DxLib.h"

class Doll
{
private:
	int gr_right[8];	// �E�̉摜
	int gr_left[8];	// ���̉摜
	int gr_up[8];	// ��̉摜
	int gr_down[8];	// ���̉摜

	int x;	// x���W
	int y;	// y���W
	int direction;		// 0�E1��2��3��
	int speed;	// �ړ����x
	int timelimit;

	int targetX;	// �^�[�Q�b�g�ʒu
	int targetY;	// �^�[�Q�b�g�ʒu
	int targetnP;

	int animcount;	// �A�j���[�V�����J�E���g
	int animspeed;	// �A�j���[�V�����t���[��
	bool anim;	// �����Ԃ��炸�ړ��ł��Ă��邩
	bool diremove;	// �Ԃ������������؂�ւ���
	int hitwait;

public:
	Doll();		// �R���X�g���N�^
	Doll(int x, int y, int direction, int targetX, int targetY, int targetnP);		// �R���X�g���N�^
	~Doll();	// �f�X�g���N�^

	int hp;
	bool hit;

	void Move();	// �ړ�

	void Draw();	// �`��

	void SetDire();	// �Ԃ������������؂�ւ���

	void SetXY(int targetX, int targetY);		// �^�[�Q�b�g���˂ɍX�V
	int GetX();		// X���W
	int GetY();		// Y���W
	bool GetAttack();
	int GetLimit();
	int GetTargetP();
};