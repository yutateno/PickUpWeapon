#pragma once
#include "Scene.h"

class Title : public Scene
{
private:
	int gr_back;	// �w�i
	int gr_two;		// ��l�p
	int gr_three;	// �O�l�p
	int gr_four;	// �l�l�p
	int gr_end;		// �I��
	int gr_extra;

	int gr_icon_two[2];			// 2P�A�C�R��
	int gr_icon_three[2];		// 3P�A�C�R��
	int gr_icon_four[2];		// 4P�A�C�R��
	int gr_icon_end[8];			// end�A�C�R��
	int gr_icon_endclick[5];	// end�A�C�R��

	bool extraflag;

	bool clickflag;

public:
	Title();	// �R���X�g���N�^
	~Title();	// �f�X�g���N�^
	
	void Update();	// �X�V

	void Process();	// �v���Z�X

	void Draw();	// �`��
};