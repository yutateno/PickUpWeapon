#pragma once
#include "Character.h"

class Character_Flame: public Character
{
private:
	int gr_forward[8];			// �O����
	int gr_backward[4];			// ������
	int gr_side[8];			// ������

public:
	Character_Flame();		// �R���X�g���N�^
	Character_Flame(int x, int y, int hp, int nP, int direction);		// ���W�Ƒ̗͂ƃv���C���[�i���o�[�ƌ����������Ɏ��R���X�g���N�^
	~Character_Flame();		//�f�X�g���N�^

	void Process();		// �v���Z�X

	void Draw();		// �`��
};