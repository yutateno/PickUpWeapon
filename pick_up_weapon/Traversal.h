#pragma once
#include "DxLib.h"

class Traversal
{
private:
	int gr_wait;	// �߂܂���O�摜
	int gr_catch;	// �߂܂�����

	int se_traversal;	// ��

	int x;	// x���W
	int y;	// y���W

	int traversalframe;

public:
	Traversal();		// �R���X�g���N�^
	Traversal(int x, int y, int direction);		// �R���X�g���N�^
	~Traversal();	// �f�X�g���N�^

	bool catchflag;
	int nP;

	void Draw();	// �`��

	int GetX();		// X���W
	int GetY();		// Y���W
	int GetFrame();
};