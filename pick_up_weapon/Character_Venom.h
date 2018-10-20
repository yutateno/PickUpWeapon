#pragma once
#include "Character.h"

class Character_Venom : public Character
{
private:
	int gr_forward[8];			// �O����
	int gr_backward[4];			// ������
	int gr_right[8];			// �E����
	int gr_left[8];				// ������
	int gr_venom_estimation;	// �\���ʒu

	int venomX, venomY;

public:
	Character_Venom();		// �R���X�g���N�^
	Character_Venom(int x, int y, int hp, int nP, int direction);		// ���W�Ƒ̗͂ƃv���C���[�i���o�[�ƌ����������Ɏ��R���X�g���N�^
	~Character_Venom();		//�f�X�g���N�^

	void Process();		// �v���Z�X

	void Draw();		// �`��
};