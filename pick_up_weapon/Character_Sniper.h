#pragma once
#include "Character.h"

class Character_Sniper : public Character
{
private:
	int gr_forward[4];			// �O����
	int gr_backward[4];			// ������
	int gr_right[4];			// �E����
	int gr_left[4];				// ������
	int gr_shoot_forward[2];	// �O������
	int gr_shoot_right[2];		// �E������
	int gr_shoot_left[2];		// ��������

	int reload_se;
	
	int waitcount;

public:
	Character_Sniper();		// �R���X�g���N�^
	Character_Sniper(int x, int y, int hp, int nP, int direction);		// ���W�Ƒ̗͂ƃv���C���[�i���o�[�ƌ����������Ɏ��R���X�g���N�^
	~Character_Sniper();		//�f�X�g���N�^

	void Process();		// �v���Z�X

	void Draw();		// �`��
};