#include "Character_Gatling.h"

Character_Gatling::Character_Gatling()
{

}

Character_Gatling::Character_Gatling(int x, int y, int hp, int nP, int direction)
{
	switch (nP)
	{
	case 1:
		LoadDivGraph("media\\player\\1P\\gatling\\前\\移動.png", 8, 8, 1, 64, 64, gr_forward);
		LoadDivGraph("media\\player\\1P\\gatling\\右\\移動.png", 8, 8, 1, 64, 64, gr_right);
		LoadDivGraph("media\\player\\1P\\gatling\\左\\移動.png", 8, 8, 1, 64, 64, gr_left);
		LoadDivGraph("media\\player\\1P\\gatling\\後ろ\\移動.png", 4, 4, 1, 64, 64, gr_backward);

		LoadDivGraph("media\\player\\1P\\gatling\\前\\撃ち.png", 2, 2, 1, 64, 64, gr_shoot_forward);
		LoadDivGraph("media\\player\\1P\\gatling\\前\\溜め.png", 2, 2, 1, 64, 64, gr_frame_forward);
		LoadDivGraph("media\\player\\1P\\gatling\\後ろ\\撃ち.png", 2, 2, 1, 64, 64, gr_shoot_backward);
		LoadDivGraph("media\\player\\1P\\gatling\\右\\撃ち.png", 2, 2, 1, 64, 64, gr_shoot_right);
		LoadDivGraph("media\\player\\1P\\gatling\\右\\溜め.png", 2, 2, 1, 64, 64, gr_frame_right);
		LoadDivGraph("media\\player\\1P\\gatling\\左\\撃ち.png", 2, 2, 1, 64, 64, gr_shoot_left);
		LoadDivGraph("media\\player\\1P\\gatling\\左\\溜め.png", 2, 2, 1, 64, 64, gr_frame_left);
		break;
	case 2:
		LoadDivGraph("media\\player\\2P\\gatling\\前\\移動.png", 8, 8, 1, 64, 64, gr_forward);
		LoadDivGraph("media\\player\\2P\\gatling\\右\\移動.png", 8, 8, 1, 64, 64, gr_right);
		LoadDivGraph("media\\player\\2P\\gatling\\左\\移動.png", 8, 8, 1, 64, 64, gr_left);
		LoadDivGraph("media\\player\\2P\\gatling\\後ろ\\移動.png", 4, 4, 1, 64, 64, gr_backward);

		LoadDivGraph("media\\player\\2P\\gatling\\前\\撃ち.png", 2, 2, 1, 64, 64, gr_shoot_forward);
		LoadDivGraph("media\\player\\2P\\gatling\\前\\溜め.png", 2, 2, 1, 64, 64, gr_frame_forward);
		LoadDivGraph("media\\player\\2P\\gatling\\後ろ\\撃ち.png", 2, 2, 1, 64, 64, gr_shoot_backward);
		LoadDivGraph("media\\player\\2P\\gatling\\右\\撃ち.png", 2, 2, 1, 64, 64, gr_shoot_right);
		LoadDivGraph("media\\player\\2P\\gatling\\右\\溜め.png", 2, 2, 1, 64, 64, gr_frame_right);
		LoadDivGraph("media\\player\\2P\\gatling\\左\\撃ち.png", 2, 2, 1, 64, 64, gr_shoot_left);
		LoadDivGraph("media\\player\\2P\\gatling\\左\\溜め.png", 2, 2, 1, 64, 64, gr_frame_left);
		break;
	case 3:
		LoadDivGraph("media\\player\\3P\\gatling\\前\\移動.png", 8, 8, 1, 64, 64, gr_forward);
		LoadDivGraph("media\\player\\3P\\gatling\\右\\移動.png", 8, 8, 1, 64, 64, gr_right);
		LoadDivGraph("media\\player\\3P\\gatling\\左\\移動.png", 8, 8, 1, 64, 64, gr_left);
		LoadDivGraph("media\\player\\3P\\gatling\\後ろ\\移動.png", 4, 4, 1, 64, 64, gr_backward);

		LoadDivGraph("media\\player\\3P\\gatling\\前\\撃ち.png", 2, 2, 1, 64, 64, gr_shoot_forward);
		LoadDivGraph("media\\player\\3P\\gatling\\前\\溜め.png", 2, 2, 1, 64, 64, gr_frame_forward);
		LoadDivGraph("media\\player\\3P\\gatling\\後ろ\\撃ち.png", 2, 2, 1, 64, 64, gr_shoot_backward);
		LoadDivGraph("media\\player\\3P\\gatling\\右\\撃ち.png", 2, 2, 1, 64, 64, gr_shoot_right);
		LoadDivGraph("media\\player\\3P\\gatling\\右\\溜め.png", 2, 2, 1, 64, 64, gr_frame_right);
		LoadDivGraph("media\\player\\3P\\gatling\\左\\撃ち.png", 2, 2, 1, 64, 64, gr_shoot_left);
		LoadDivGraph("media\\player\\3P\\gatling\\左\\溜め.png", 2, 2, 1, 64, 64, gr_frame_left);
		break;
	case 4:
		LoadDivGraph("media\\player\\4P\\gatling\\前\\移動.png", 8, 8, 1, 64, 64, gr_forward);
		LoadDivGraph("media\\player\\4P\\gatling\\右\\移動.png", 8, 8, 1, 64, 64, gr_right);
		LoadDivGraph("media\\player\\4P\\gatling\\左\\移動.png", 8, 8, 1, 64, 64, gr_left);
		LoadDivGraph("media\\player\\4P\\gatling\\後ろ\\移動.png", 4, 4, 1, 64, 64, gr_backward);

		LoadDivGraph("media\\player\\4P\\gatling\\前\\撃ち.png", 2, 2, 1, 64, 64, gr_shoot_forward);
		LoadDivGraph("media\\player\\4P\\gatling\\前\\溜め.png", 2, 2, 1, 64, 64, gr_frame_forward);
		LoadDivGraph("media\\player\\4P\\gatling\\後ろ\\撃ち.png", 2, 2, 1, 64, 64, gr_shoot_backward);
		LoadDivGraph("media\\player\\4P\\gatling\\右\\撃ち.png", 2, 2, 1, 64, 64, gr_shoot_right);
		LoadDivGraph("media\\player\\4P\\gatling\\右\\溜め.png", 2, 2, 1, 64, 64, gr_frame_right);
		LoadDivGraph("media\\player\\4P\\gatling\\左\\撃ち.png", 2, 2, 1, 64, 64, gr_shoot_left);
		LoadDivGraph("media\\player\\4P\\gatling\\左\\溜め.png", 2, 2, 1, 64, 64, gr_frame_left);
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
	// RTを押している状態
	if (input.Z == -1000)
	{
		gatlingframe++;
	}
	// RTから少しでも離している状態
	else
	{
		gatlingframe = 0;
		RTbutton = 0;
	}
	// ガトリングの溜が終わったら
	if (gatlingframe > 30)
	{
		RTbutton++;
	}

	// 直前座標に移す
	prex = x;
	prey = y;

	Character::MoveControl();


	// デバッグ
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