#pragma once
#include "Scene.h"

class StageSelect : public Scene
{
private:
	int gr_back;	// �w�i
	int gr_one;		// �P�ڂ̃X�e�[�W
	int gr_two;		// �Q�ڂ̃X�e�[�W
	int gr_three;	// �R�ڂ̃X�e�[�W

public:
	StageSelect();	// �R���X�g���N�^
	~StageSelect();	// �f�X�g���N�^

	void Update();	// �X�V

	void Process();	// �v���Z�X

	void Draw();	// �`��
};