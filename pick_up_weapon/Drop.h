#pragma once
#include "DxLib.h"

class Drop
{
private:
	int Gr;			// �摜

	int x;
	int y;		// ���W
	int ID;			// �ǂ̕��킩

public:
	Drop();		// �R���X�g���N�^
	Drop(int x, int y, int ID);		// ���W��ID�������Ɏ��R���X�g���N�^
	~Drop();		// �f�X�g���N�^

	void Draw();	// �`��

	// �Q�b�^�[
	int GetX();
	int GetY();
	int GetID();
};