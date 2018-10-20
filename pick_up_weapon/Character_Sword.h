#pragma once
#include "Character.h"

class Character_Sword : public Character
{
private:
	int gr_forward[8];			// �O����
	int gr_backward[4];			// ������
	int gr_right[8];			// �E����
	int gr_left[8];				// ������
	int gr_attack_forward[2];	// �O�U��
	int gr_attack_backward[2];	// ���U��
	int gr_attack_right[2];		// �E�U��
	int gr_attack_left[2];		// ���U��
	int gr_afterimage[2];		// �c��
	bool attackflag;
	int attackframe;

public:
	Character_Sword();		// �R���X�g���N�^
	Character_Sword(int x, int y, int hp, int nP, int direction);		// ���W�Ƒ̗͂ƃv���C���[�i���o�[�ƌ����������Ɏ��R���X�g���N�^
	~Character_Sword();	// �f�X�g���N�^

	void Process();		// �v���Z�X

	void Draw();		// �`��
};