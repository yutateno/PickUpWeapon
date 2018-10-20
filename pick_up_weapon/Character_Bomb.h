#pragma once
#include "Character.h"

class Character_Bomb : public Character
{
private:
	int gr_forward[8];			// �O����
	int gr_backward[4];			// ������
	int gr_side[8];			// �E����
	int gr_bomb_estimation;	// �\���ʒu

	int bombX, bombY;

public:
	Character_Bomb();		// �R���X�g���N�^
	Character_Bomb(int x, int y, int hp, int nP, int direction);		// ���W�Ƒ̗͂ƃv���C���[�i���o�[�ƌ����������Ɏ��R���X�g���N�^
	~Character_Bomb();		//�f�X�g���N�^

	void Process();		// �v���Z�X

	void Draw();		// �`��
};