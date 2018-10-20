#pragma once
#include "DxLib.h"

class Bullet
{
private:
	int gr;	// �摜

	int direction;	// ����
	int speed;	// ���x

	int x;	// X���W
	int y;	// Y���W
	int power;

public:
	Bullet();	// �R���X�g���N�^
	Bullet(int x, int y, int direction, int speed, int power);	// �R���X�g���N�^
	~Bullet();	// �f�X�g���N�^

	void Move();	// �ړ�
	void Draw();	// �`��

	int GetX();		// X���W
	int GetY();		// Y���W
	int GetPower();
	int GetDire();
};