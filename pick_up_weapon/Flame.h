#pragma once
#include "DxLib.h"

class Flame
{
private:
	int gr_move[4];		// �ړ��摜
	int gr_flame[4];	// ���Ή摜

	int se_flame;

	int direction;	// ����
	int speed;	// ���x

	int moveframe;	// �ړ�
	int animcount;	// �A�j���[�V�����J�E���g
	int animspeed;	// �A�j���[�V�����t���[��

	int x;	// X���W
	int y;	// Y���W

public:
	Flame();	// �R���X�g���N�^
	Flame(int x, int y, int direction);	// �R���X�g���N�^
	~Flame();	// �f�X�g���N�^

	bool wallhit;

	void Move();	// �ړ�
	void Draw();	// �`��

	int GetX();		// X���W
	int GetY();		// Y���W
	int GetFrame();
	int GetDire();
};