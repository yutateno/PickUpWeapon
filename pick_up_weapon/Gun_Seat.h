#pragma once
#include "DxLib.h"

class Gun_Seat
{
private:
	int gr_up[2];			// ��̉摜
	int gr_down[2];			// ���̉摜
	int gr_side[2];			// ���E�̉摜

	int x;	// X���W
	int y;	// Y���W
	int direction;			// 0�E1��2��3��
	int waitcount;	// �������߂܂ł̑ҋ@
	int gunframe;	// �t���[��

	int animcount;	// �A�j���[�V�����̃J�E���g
	int animspeed;	// �A�j���[�V�����̃X�s�[�h

public:
	Gun_Seat();	// �R���X�g���N�^
	Gun_Seat(int x, int y, int direction);		// �R���X�g���N�^
	~Gun_Seat();	// �f�X�g���N�^

	int gunnum;	// �e��
	int hp;

	void Do();		// ���s
	void Draw();	// �`��

	int GetDire();	// ����
	int GetX();		// X���W
	int GetY();		// Y���W
	int GetShot();	// �K���t���[��
};