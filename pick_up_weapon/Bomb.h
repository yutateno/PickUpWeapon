#pragma once
#include "DxLib.h"

class Bomb
{
private:
	int gr[5];	// �摜

	int se_bomb;	// ��

	int x;	// x���W
	int y;	// y���W
	int direction;		// 0�E1��2��3��

	int animcount;	// �A�j���[�V�����J�E���g
	int animspeed;	// �A�j���[�V�����t���[��

	int bombframe;

public:
	Bomb();		// �R���X�g���N�^
	Bomb(int x, int y, int direction);		// �R���X�g���N�^
	~Bomb();	// �f�X�g���N�^

	void Draw();	// �`��

	int GetX();		// X���W
	int GetY();		// Y���W
	int GetFrame();
};