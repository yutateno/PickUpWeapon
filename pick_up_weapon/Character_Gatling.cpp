#include "Character_Gatling.h"

Character_Gatling::Character_Gatling()
{

}

Character_Gatling::Character_Gatling(int x, int y, int hp, int nP, int direction)
{
	switch (nP)
	{
	case 1:
		LoadDivGraph("media\\player\\1P\\gatling\\�O\\�ړ�.png", 8, 8, 1, 64, 64, gr_forward);
		LoadDivGraph("media\\player\\1P\\gatling\\�E\\�ړ�.png", 8, 8, 1, 64, 64, gr_right);
		LoadDivGraph("media\\player\\1P\\gatling\\��\\�ړ�.png", 8, 8, 1, 64, 64, gr_left);
		LoadDivGraph("media\\player\\1P\\gatling\\���\\�ړ�.png", 4, 4, 1, 64, 64, gr_backward);

		LoadDivGraph("media\\player\\1P\\gatling\\�O\\����.png", 2, 2, 1, 64, 64, gr_shoot_forward);
		LoadDivGraph("media\\player\\1P\\gatling\\�O\\����.png", 2, 2, 1, 64, 64, gr_frame_forward);
		LoadDivGraph("media\\player\\1P\\gatling\\���\\����.png", 2, 2, 1, 64, 64, gr_shoot_backward);
		LoadDivGraph("media\\player\\1P\\gatling\\�E\\����.png", 2, 2, 1, 64, 64, gr_shoot_right);
		LoadDivGraph("media\\player\\1P\\gatling\\�E\\����.png", 2, 2, 1, 64, 64, gr_frame_right);
		LoadDivGraph("media\\player\\1P\\gatling\\��\\����.png", 2, 2, 1, 64, 64, gr_shoot_left);
		LoadDivGraph("media\\player\\1P\\gatling\\��\\����.png", 2, 2, 1, 64, 64, gr_frame_left);
		break;
	case 2:
		LoadDivGraph("media\\player\\2P\\gatling\\�O\\�ړ�.png", 8, 8, 1, 64, 64, gr_forward);
		LoadDivGraph("media\\player\\2P\\gatling\\�E\\�ړ�.png", 8, 8, 1, 64, 64, gr_right);
		LoadDivGraph("media\\player\\2P\\gatling\\��\\�ړ�.png", 8, 8, 1, 64, 64, gr_left);
		LoadDivGraph("media\\player\\2P\\gatling\\���\\�ړ�.png", 4, 4, 1, 64, 64, gr_backward);

		LoadDivGraph("media\\player\\2P\\gatling\\�O\\����.png", 2, 2, 1, 64, 64, gr_shoot_forward);
		LoadDivGraph("media\\player\\2P\\gatling\\�O\\����.png", 2, 2, 1, 64, 64, gr_frame_forward);
		LoadDivGraph("media\\player\\2P\\gatling\\���\\����.png", 2, 2, 1, 64, 64, gr_shoot_backward);
		LoadDivGraph("media\\player\\2P\\gatling\\�E\\����.png", 2, 2, 1, 64, 64, gr_shoot_right);
		LoadDivGraph("media\\player\\2P\\gatling\\�E\\����.png", 2, 2, 1, 64, 64, gr_frame_right);
		LoadDivGraph("media\\player\\2P\\gatling\\��\\����.png", 2, 2, 1, 64, 64, gr_shoot_left);
		LoadDivGraph("media\\player\\2P\\gatling\\��\\����.png", 2, 2, 1, 64, 64, gr_frame_left);
		break;
	case 3:
		LoadDivGraph("media\\player\\3P\\gatling\\�O\\�ړ�.png", 8, 8, 1, 64, 64, gr_forward);
		LoadDivGraph("media\\player\\3P\\gatling\\�E\\�ړ�.png", 8, 8, 1, 64, 64, gr_right);
		LoadDivGraph("media\\player\\3P\\gatling\\��\\�ړ�.png", 8, 8, 1, 64, 64, gr_left);
		LoadDivGraph("media\\player\\3P\\gatling\\���\\�ړ�.png", 4, 4, 1, 64, 64, gr_backward);

		LoadDivGraph("media\\player\\3P\\gatling\\�O\\����.png", 2, 2, 1, 64, 64, gr_shoot_forward);
		LoadDivGraph("media\\player\\3P\\gatling\\�O\\����.png", 2, 2, 1, 64, 64, gr_frame_forward);
		LoadDivGraph("media\\player\\3P\\gatling\\���\\����.png", 2, 2, 1, 64, 64, gr_shoot_backward);
		LoadDivGraph("media\\player\\3P\\gatling\\�E\\����.png", 2, 2, 1, 64, 64, gr_shoot_right);
		LoadDivGraph("media\\player\\3P\\gatling\\�E\\����.png", 2, 2, 1, 64, 64, gr_frame_right);
		LoadDivGraph("media\\player\\3P\\gatling\\��\\����.png", 2, 2, 1, 64, 64, gr_shoot_left);
		LoadDivGraph("media\\player\\3P\\gatling\\��\\����.png", 2, 2, 1, 64, 64, gr_frame_left);
		break;
	case 4:
		LoadDivGraph("media\\player\\4P\\gatling\\�O\\�ړ�.png", 8, 8, 1, 64, 64, gr_forward);
		LoadDivGraph("media\\player\\4P\\gatling\\�E\\�ړ�.png", 8, 8, 1, 64, 64, gr_right);
		LoadDivGraph("media\\player\\4P\\gatling\\��\\�ړ�.png", 8, 8, 1, 64, 64, gr_left);
		LoadDivGraph("media\\player\\4P\\gatling\\���\\�ړ�.png", 4, 4, 1, 64, 64, gr_backward);

		LoadDivGraph("media\\player\\4P\\gatling\\�O\\����.png", 2, 2, 1, 64, 64, gr_shoot_forward);
		LoadDivGraph("media\\player\\4P\\gatling\\�O\\����.png", 2, 2, 1, 64, 64, gr_frame_forward);
		LoadDivGraph("media\\player\\4P\\gatling\\���\\����.png", 2, 2, 1, 64, 64, gr_shoot_backward);
		LoadDivGraph("media\\player\\4P\\gatling\\�E\\����.png", 2, 2, 1, 64, 64, gr_shoot_right);
		LoadDivGraph("media\\player\\4P\\gatling\\�E\\����.png", 2, 2, 1, 64, 64, gr_frame_right);
		LoadDivGraph("media\\player\\4P\\gatling\\��\\����.png", 2, 2, 1, 64, 64, gr_shoot_left);
		LoadDivGraph("media\\player\\4P\\gatling\\��\\����.png", 2, 2, 1, 64, 64, gr_frame_left);
		break;
	default:
		break;
	}
	speed = 2;
	this->x = x;
	this->y = y;
	this->hp = hp;
	this->nP = nP;
	this->direction = direction;
	RTbutton = 0;
	gatlingframe = 0;
	tamanum = 150;
	sniperframe = 0;
	animcount = 0;
	animspeed = 10;
}

Character_Gatling::~Character_Gatling()
{
	for (int i = 0; i != 8; ++i)
	{
		DeleteGraph(gr_left[i]);
		DeleteGraph(gr_right[i]);
		DeleteGraph(gr_forward[i]);
	}
	for (int i = 0; i != 4; ++i)
	{
		DeleteGraph(gr_backward[i]);
	}
	for (int i = 0; i != 2; ++i)
	{
		DeleteGraph(gr_shoot_forward[i]);
		DeleteGraph(gr_frame_forward[i]);
		DeleteGraph(gr_shoot_backward[i]);
		DeleteGraph(gr_shoot_right[i]);
		DeleteGraph(gr_frame_right[i]);
		DeleteGraph(gr_shoot_left[i]);
		DeleteGraph(gr_frame_left[i]);
	}
}

void Character_Gatling::Process()
{
	// RT�������Ă�����
	if (input.Z == -1000)
	{
		gatlingframe++;
	}
	// RT���班���ł������Ă�����
	else
	{
		gatlingframe = 0;
		RTbutton = 0;
	}
	// �K�g�����O�̗����I�������
	if (gatlingframe > 30)
	{
		RTbutton++;
	}

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

void Character_Gatling::Draw()
{
	if (gatlingframe == 0)
	{
		if (direction == 0)
		{
			DrawGraph(x, y, gr_right[(animcount / animspeed) % 8], true);
		}
		if (direction == 1)
		{
			DrawGraph(x, y, gr_forward[(animcount / animspeed) % 8], true);
		}
		if (direction == 2)
		{
			DrawGraph(x, y, gr_left[(animcount / animspeed) % 8], true);
		}
		if (direction == 3)
		{
			DrawGraph(x, y, gr_backward[(animcount / animspeed) % 4], true);
		}
	}
	else if (gatlingframe <= 30 && gatlingframe > 0)
	{
		x = prex;
		y = prey;
		if (direction == 0)
		{
			DrawGraph(x, y, gr_frame_right[(animcount / animspeed) % 2], true);
		}
		if (direction == 1)
		{
			DrawGraph(x, y, gr_frame_forward[(animcount / animspeed) % 2], true);
		}
		if (direction == 2)
		{
			DrawGraph(x, y, gr_frame_left[(animcount / animspeed) % 2], true);
		}
		if (direction == 3)
		{
			DrawGraph(x, y, gr_backward[(animcount / animspeed) % 4], true);
		}
	}
	else
	{
		x = prex;
		y = prey;
		if (direction == 0)
		{
			DrawGraph(x, y, gr_shoot_right[(animcount / animspeed) % 2], true);
		}
		if (direction == 1)
		{
			DrawGraph(x, y, gr_shoot_forward[(animcount / animspeed) % 2], true);
		}
		if (direction == 2)
		{
			DrawGraph(x, y, gr_shoot_left[(animcount / animspeed) % 2], true);
		}
		if (direction == 3)
		{
			DrawGraph(x, y, gr_shoot_backward[(animcount / animspeed) % 2], true);
		}
	}
}