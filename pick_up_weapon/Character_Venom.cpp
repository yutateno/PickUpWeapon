#include "Character_Venom.h"

Character_Venom::Character_Venom()
{

}

Character_Venom::Character_Venom(int x, int y, int hp, int nP, int direction)
{
	switch (nP)
	{
	case 1:
		LoadDivGraph("media\\player\\1P\\venom\\�O\\�ړ�.png", 8, 8, 1, 64, 64, gr_forward);
		LoadDivGraph("media\\player\\1P\\venom\\�E\\�ړ�.png", 8, 8, 1, 64, 64, gr_right);
		LoadDivGraph("media\\player\\1P\\venom\\��\\�ړ�.png", 8, 8, 1, 64, 64, gr_left);
		LoadDivGraph("media\\player\\1P\\venom\\���\\�ړ�.png", 4, 4, 1, 64, 64, gr_backward);
		gr_venom_estimation = LoadGraph("media\\player\\1P\\venom\\�ŃK�X�\��.png");
		break;
	case 2:
		LoadDivGraph("media\\player\\2P\\venom\\�O\\�ړ�.png", 8, 8, 1, 64, 64, gr_forward);
		LoadDivGraph("media\\player\\2P\\venom\\�E\\�ړ�.png", 8, 8, 1, 64, 64, gr_right);
		LoadDivGraph("media\\player\\2P\\venom\\��\\�ړ�.png", 8, 8, 1, 64, 64, gr_left);
		LoadDivGraph("media\\player\\2P\\venom\\���\\�ړ�.png", 4, 4, 1, 64, 64, gr_backward);
		gr_venom_estimation = LoadGraph("media\\player\\2P\\venom\\�ŃK�X�\��.png");
		break;
	case 3:
		LoadDivGraph("media\\player\\3P\\venom\\�O\\�ړ�.png", 8, 8, 1, 64, 64, gr_forward);
		LoadDivGraph("media\\player\\3P\\venom\\�E\\�ړ�.png", 8, 8, 1, 64, 64, gr_right);
		LoadDivGraph("media\\player\\3P\\venom\\��\\�ړ�.png", 8, 8, 1, 64, 64, gr_left);
		LoadDivGraph("media\\player\\3P\\venom\\���\\�ړ�.png", 4, 4, 1, 64, 64, gr_backward);
		gr_venom_estimation = LoadGraph("media\\player\\3P\\venom\\�ŃK�X�\��.png");
		break;
	case 4:
		LoadDivGraph("media\\player\\4P\\venom\\�O\\�ړ�.png", 8, 8, 1, 64, 64, gr_forward);
		LoadDivGraph("media\\player\\4P\\venom\\�E\\�ړ�.png", 8, 8, 1, 64, 64, gr_right);
		LoadDivGraph("media\\player\\4P\\venom\\��\\�ړ�.png", 8, 8, 1, 64, 64, gr_left);
		LoadDivGraph("media\\player\\4P\\venom\\���\\�ړ�.png", 4, 4, 1, 64, 64, gr_backward);
		gr_venom_estimation = LoadGraph("media\\player\\4P\\venom\\�ŃK�X�\��.png");
		break;
	default:
		break;
	}

	venomX = 0;
	venomY = 0;

	speed = 4;
	this->x = x;
	this->y = y;
	this->hp = hp;
	this->nP = nP;
	this->direction = direction;
	RTbutton = 0;
	gatlingframe = 0;
	tamanum = 0;
	sniperframe = 0;
	animcount = 0;
	animspeed = 10;
}

Character_Venom::~Character_Venom()
{
	for (int i = 0; i != 8; ++i)
	{
		DeleteGraph(gr_right[i]);
		DeleteGraph(gr_left[i]);
		DeleteGraph(gr_forward[i]);
	}
	for (int i = 0; i != 4; ++i)
	{
		DeleteGraph(gr_backward[i]);
	}
	DeleteGraph(gr_venom_estimation);
}

void Character_Venom::Process()
{
	// ���O���W�Ɉڂ�
	prex = x;
	prey = y;

	Character::MoveControl();

	// �f�o�b�O
	if (nP >= 2)
	{
		Character::MoveControl2();
	}
	if (animcount < animspeed * 8)
	{
		animcount++;
	}
	else
	{
		animcount = 0;
	}
}

void Character_Venom::Draw()
{
	if (direction == 0)
	{
		DrawGraph(x, y, gr_right[(animcount / animspeed) % 8], true);
		venomX = x - (x % 64) + (64 * 4);
		venomY = y;
		if (venomX > (1920 - 128))
		{
			venomX = 1920 - 128;
		}
		if (venomY < 64)
		{
			venomY = 64;
		}
		else if (venomY > 1080 - 64)
		{
			venomY = 1080 - 64;
		}
		DrawGraph(venomX, venomY, gr_venom_estimation, true);
	}
	if (direction == 1)
	{
		DrawGraph(x, y, gr_forward[(animcount / animspeed) % 8], true);
		venomX = x;
		venomY = y - (y % 64) + (64 * 4);
		if (venomY > (1080 - 128))
		{
			venomY = 1080 - 128;
		}
		if (venomX < 64)
		{
			venomX = 64;
		}
		else if (venomX > 1920 - 64)
		{
			venomX = 1920 - 64;
		}
		DrawGraph(venomX, venomY, gr_venom_estimation, true);
	}
	if (direction == 2)
	{
		DrawGraph(x, y, gr_left[(animcount / animspeed) % 8], true);
		venomX = x - (x % 64) - (64 * 3);
		venomY = y;
		if (venomX < 64)
		{
			venomX = 64;
		}
		if (venomY < 64)
		{
			venomY = 64;
		}
		else if (venomY > 1080 - 64)
		{
			venomY = 1080 - 64;
		}
		DrawGraph(venomX, venomY, gr_venom_estimation, true);
	}
	if (direction == 3)
	{
		DrawGraph(x, y, gr_backward[(animcount / animspeed) % 4], true);
		venomX = x;
		venomY = y - (y % 64) - (64 * 3);
		if (venomY < 64)
		{
			venomY = 64;
		}
		if (venomX < 64)
		{
			venomX = 64;
		}
		else if (this->x > 1920 - 64)
		{
			venomX = 1920 - 64;
		}
		DrawGraph(venomX, venomY, gr_venom_estimation, true);
	}
}