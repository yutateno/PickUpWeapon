#pragma once
#include "Character.h"

class Character_Gatling : public Character
{
private:
	int gr_forward[8];			// �O����
	int gr_backward[4];			// ������
	int gr_right[8];			// �E����
	int gr_left[8];				// ������
	int gr_shoot_forward[2];	// �O������
	int gr_frame_forward[2];	// �O���ߒ�
	int gr_shoot_backward[2];	// ��댂����
	int gr_shoot_right[2];		// �E������
	int gr_frame_right[2];		// �E���ߒ�
	int gr_shoot_left[2];		// ��������
	int gr_frame_left[2];		// �����ߒ�

public:
	Character_Gatling();		// �R���X�g���N�^
	Character_Gatling(int x, int y, int hp, int nP, int direction);		// ���W�Ƒ̗͂ƃv���C���[�i���o�[�ƌ����������Ɏ��R���X�g���N�^
	~Character_Gatling();		//�f�X�g���N�^

	void Process();		// �v���Z�X

	void Draw();		// �`��
};