#pragma once
#include "Character.h"

class Character_GunSeat : public Character
{
private:
	int gr_forward[8];		// �O����
	int gr_backward[4];		// ������
	int gr_side[8];			// ������

public:
	Character_GunSeat();		// �R���X�g���N�^
	Character_GunSeat(int x, int y, int hp, int nP, int direction);		// ���W�Ƒ̗͂ƃv���C���[�i���o�[�ƌ����������Ɏ��R���X�g���N�^
	~Character_GunSeat();		//�f�X�g���N�^

	void Process();		// �v���Z�X

	void Draw();		// �`��
};