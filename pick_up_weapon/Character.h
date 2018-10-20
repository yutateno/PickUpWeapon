#pragma once
#include "DxLib.h"
#include "Input.h"

class Character
{
protected:
	int x;					// x���W
	int y;					// y���W
	int prex;				// ���O��x���W
	int prey;				// ���O��y���W
	int hp;				// �̗�
	int speed;				// �X�s�[�h
	int nP;					// �v���C���[�i���o�[
	int direction;			// ����[0�E�A1���A2���A3��]
	int startwaitcount;

	int animcount;		// �A�j���[�V�����J�E���g
	int animspeed;		// �A�j���[�V�����X�s�[�h

	// �R���g���[���[
	DINPUT_JOYSTATE input;		// �R���g���[���[
	int RTbutton;								// RT�{�^��
	int gatlingframe;							// �K�g�����O�̒e�t���[��
	int sniperframe;						// �X�i�C�p�[�̒e�t���[��
	int RBframe;
	int LBframe;
	int Aframe;

	// ��{�ړ�����
	void MoveControl();

	// �f�o�b�O
	void MoveControl2();				// 2P

public:
	Character();					// �R���X�g���N�^

	virtual ~Character() {};		// �f�X�g���N�^

	virtual void Process() = 0;		// �v���Z�X

	virtual void Draw() = 0;		// �`��


	void MoveReset();				// ���O�ɖ߂�

	int tamanum;		// �łĂ鋅�̐�

	// �Q�b�^�[
	int GetX();						// X���W
	int GetY();						// Y���W
	int GetDire();					// ����
	int GetRTbutton();				// RT�{�^��
	int GetAbutton();				// A�{�^��
	int GetRBbutton();				// RB�{�^��
	int GetLBbutton();
};