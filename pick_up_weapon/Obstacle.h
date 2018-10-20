#pragma once
#include "DxLib.h"

class Obstacle
{
private:
	int capsule[6];					// �}�b�v��ɂ���J�v�Z���u���b�N
	int capsule_break[13];	// �}�b�v��ɂ������Œ��̃J�v�Z���u���b�N
	int capsule_broken;	// �}�b�v��ɂ����ꂽ�J�v�Z���u���b�N
	int rock;						// �}�b�v��ɂ����u���b�N
	int rock_break[11];		// �}�b�v��ɂ������Œ��̊�u���b�N
	int rock_broken;		// �}�b�v��ɂ����ꂽ��u���b�N

	int animcount;					// ����u���b�N�̃t���[��
	int animbreakcount;					// ����u���b�N�̃t���[��
	int breakcount;					// ����u���b�N�̃t���[��
	int animspeed;		// �A�j���[�V�����X�s�[�h

	int ID;		// �z�u������̂�ID

	int x;
	int y;	// ���W

	bool brokenflag;		// ��ꂽ���ǂ���
	bool breakflag;			// ���Ă���Œ����ǂ���


public:
	Obstacle();		// �R���X�g���N�^
	Obstacle(int ID, int x, int y);	// �R���X�g���N�^
	~Obstacle();		// �f�X�g���N�^

	void Draw_Normal();	// �ʏ펞�̕`��
	void Draw_Break();	// ���Ă���Œ��̕`��
	void Draw_Broken();	// ��ꂽ���̕`��

	bool hitflag;		// �_���[�W���󂯎n�߂����ǂ���

	// �Q�b�^�[
	bool GetBrokenFlag();		// ��ꂽ�t���b�O
	bool GetBreakFlag();		// ���Ă���t���b�O
	int GetX();		// X���W
	int GetY();		// Y���W
	int GetID();	// ID
	int GetHowBreak();		// �ǂ̂��炢���Ă��邩
};