#pragma once
#include "DxLib.h"

class Venom
{
private:
	int gr[3];	// �摜

	int se_venom;	// ��

	int x;	// x���W
	int y;	// y���W
	int direction;		// 0�E1��2��3��

	int animcount;	// �A�j���[�V�����J�E���g
	int animspeed;	// �A�j���[�V�����t���[��

	int venomframe;

public:
	Venom();		// �R���X�g���N�^
	Venom(int x, int y, int direction);		// �R���X�g���N�^
	~Venom();	// �f�X�g���N�^
	
	void Draw();	// �`��

	int GetX();		// X���W
	int GetY();		// Y���W
	int GetFrame();
};