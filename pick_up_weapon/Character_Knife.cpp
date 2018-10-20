#include "Character_Knife.h"

Character_Knife::Character_Knife()
{

}

Character_Knife::Character_Knife(int x, int y, int hp, int nP, int direction)
{
	switch (nP)
	{
	case 1:
		LoadDivGraph("media\\player\\1P\\knife\\‘O\\ˆÚ“®.png", 8, 8, 1, 64, 64, gr_forward);
		LoadDivGraph("media\\player\\1P\\knife\\Œã‚ë\\ˆÚ“®.png", 4, 4, 1, 64, 64, gr_backward);
		LoadDivGraph("media\\player\\1P\\knife\\‰E\\ˆÚ“®.png", 8, 8, 1, 64, 64, gr_right);
		LoadDivGraph("media\\player\\1P\\knife\\¶\\ˆÚ“®.png", 8, 8, 1, 64, 64, gr_left);
		LoadDivGraph("media\\player\\1P\\knife\\‘O\\U‚è.png", 2, 2, 1, 64, 64, gr_attack_forward);
		LoadDivGraph("media\\player\\1P\\knife\\Œã‚ë\\U‚è.png", 2, 2, 1, 64, 64, gr_attack_backward);
		LoadDivGraph("media\\player\\1P\\knife\\‰E\\U‚è.png", 2, 2, 1, 64, 64, gr_attack_right);
		LoadDivGraph("media\\player\\1P\\knife\\¶\\U‚è.png", 2, 2, 1, 64, 64, gr_attack_left);
		break;
	case 2:
		LoadDivGraph("media\\player\\2P\\knife\\‘O\\ˆÚ“®.png", 8, 8, 1, 64, 64, gr_forward);
		LoadDivGraph("media\\player\\2P\\knife\\Œã‚ë\\ˆÚ“®.png", 4, 4, 1, 64, 64, gr_backward);
		LoadDivGraph("media\\player\\2P\\knife\\‰E\\ˆÚ“®.png", 8, 8, 1, 64, 64, gr_right);
		LoadDivGraph("media\\player\\2P\\knife\\¶\\ˆÚ“®.png", 8, 8, 1, 64, 64, gr_left);
		LoadDivGraph("media\\player\\2P\\knife\\‘O\\U‚è.png", 2, 2, 1, 64, 64, gr_attack_forward);
		LoadDivGraph("media\\player\\2P\\knife\\Œã‚ë\\U‚è.png", 2, 2, 1, 64, 64, gr_attack_backward);
		LoadDivGraph("media\\player\\2P\\knife\\‰E\\U‚è.png", 2, 2, 1, 64, 64, gr_attack_right);
		LoadDivGraph("media\\player\\2P\\knife\\¶\\U‚è.png", 2, 2, 1, 64, 64, gr_attack_left);
		break;
	case 3:
		LoadDivGraph("media\\player\\3P\\knife\\‘O\\ˆÚ“®.png", 8, 8, 1, 64, 64, gr_forward);
		LoadDivGraph("media\\player\\3P\\knife\\Œã‚ë\\ˆÚ“®.png", 4, 4, 1, 64, 64, gr_backward);
		LoadDivGraph("media\\player\\3P\\knife\\‰E\\ˆÚ“®.png", 8, 8, 1, 64, 64, gr_right);
		LoadDivGraph("media\\player\\3P\\knife\\¶\\ˆÚ“®.png", 8, 8, 1, 64, 64, gr_left);
		LoadDivGraph("media\\player\\3P\\knife\\‘O\\U‚è.png", 2, 2, 1, 64, 64, gr_attack_forward);
		LoadDivGraph("media\\player\\3P\\knife\\Œã‚ë\\U‚è.png", 2, 2, 1, 64, 64, gr_attack_backward);
		LoadDivGraph("media\\player\\3P\\knife\\‰E\\U‚è.png", 2, 2, 1, 64, 64, gr_attack_right);
		LoadDivGraph("media\\player\\3P\\knife\\¶\\U‚è.png", 2, 2, 1, 64, 64, gr_attack_left);
		break;
	case 4:
		LoadDivGraph("media\\player\\4P\\knife\\‘O\\ˆÚ“®.png", 8, 8, 1, 64, 64, gr_forward);
		LoadDivGraph("media\\player\\4P\\knife\\Œã‚ë\\ˆÚ“®.png", 4, 4, 1, 64, 64, gr_backward);
		LoadDivGraph("media\\player\\4P\\knife\\‰E\\ˆÚ“®.png", 8, 8, 1, 64, 64, gr_right);
		LoadDivGraph("media\\player\\4P\\knife\\¶\\ˆÚ“®.png", 8, 8, 1, 64, 64, gr_left);
		LoadDivGraph("media\\player\\4P\\knife\\‘O\\U‚è.png", 2, 2, 1, 64, 64, gr_attack_forward);
		LoadDivGraph("media\\player\\4P\\knife\\Œã‚ë\\U‚è.png", 2, 2, 1, 64, 64, gr_attack_backward);
		LoadDivGraph("media\\player\\4P\\knife\\‰E\\U‚è.png", 2, 2, 1, 64, 64, gr_attack_right);
		LoadDivGraph("media\\player\\4P\\knife\\¶\\U‚è.png", 2, 2, 1, 64, 64, gr_attack_left);
		break;
	default:
		break;
	}

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
	attackflag = false;
	attackframe = 0;
}

Character_Knife::~Character_Knife()
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
	for (int i = 0; i != 2; ++i)
	{
		DeleteGraph(gr_attack_forward[i]);
		DeleteGraph(gr_attack_backward[i]);
		DeleteGraph(gr_attack_right[i]);
		DeleteGraph(gr_attack_left[i]);
	}
}

void Character_Knife::Process()
{
	// ’¼‘OÀ•W‚ÉˆÚ‚·
	prex = x;
	prey = y;

	Character::MoveControl();
	
	if (nP >= 2)
	{
		Character::MoveControl2();
	}

	if (GetRBbutton() == 1)
	{
		attackflag = true;
	}
	if (attackflag == true)
	{
		attackframe++;
	}
	if (attackframe > 3)
	{
		attackflag = false;
		attackframe = 0;
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

void Character_Knife::Draw()
{
	if (attackflag != true)
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
	else
	{
		if (direction == 0)
		{
			DrawGraph(x, y, gr_attack_right[(animcount / animspeed) % 2], true);
		}
		if (direction == 1)
		{
			DrawGraph(x, y, gr_attack_forward[(animcount / animspeed) % 2], true);
		}
		if (direction == 2)
		{
			DrawGraph(x, y, gr_attack_left[(animcount / animspeed) % 2], true);
		}
		if (direction == 3)
		{
			DrawGraph(x, y, gr_attack_backward[(animcount / animspeed) % 2], true);
		}
	}
}