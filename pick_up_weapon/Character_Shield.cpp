#include "Character_Shield.h"

Character_Shield::Character_Shield()
{

}

Character_Shield::Character_Shield(int x, int y, int hp, int nP, int direction)
{
	switch (nP)
	{
	case 1:
		LoadDivGraph("media\\player\\1P\\shield\\前\\移動.png", 8, 8, 1, 64, 64, gr_forward);
		LoadDivGraph("media\\player\\1P\\shield\\後ろ\\移動.png", 4, 4, 1, 64, 64, gr_backward);
		LoadDivGraph("media\\player\\1P\\shield\\横\\移動.png", 8, 8, 1, 64, 64, gr_side);
		break;
	case 2:
		LoadDivGraph("media\\player\\2P\\shield\\前\\移動.png", 8, 8, 1, 64, 64, gr_forward);
		LoadDivGraph("media\\player\\2P\\shield\\後ろ\\移動.png", 4, 4, 1, 64, 64, gr_backward);
		LoadDivGraph("media\\player\\2P\\shield\\横\\移動.png", 8, 8, 1, 64, 64, gr_side);
		break;
	case 3:
		LoadDivGraph("media\\player\\3P\\shield\\前\\移動.png", 8, 8, 1, 64, 64, gr_forward);
		LoadDivGraph("media\\player\\3P\\shield\\後ろ\\移動.png", 4, 4, 1, 64, 64, gr_backward);
		LoadDivGraph("media\\player\\3P\\shield\\横\\移動.png", 8, 8, 1, 64, 64, gr_side);
		break;
	case 4:
		LoadDivGraph("media\\player\\4P\\shield\\前\\移動.png", 8, 8, 1, 64, 64, gr_forward);
		LoadDivGraph("media\\player\\4P\\shield\\後ろ\\移動.png", 4, 4, 1, 64, 64, gr_backward);
		LoadDivGraph("media\\player\\4P\\shield\\横\\移動.png", 8, 8, 1, 64, 64, gr_side);
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
	tamanum = 0;
	sniperframe = 0;
	animcount = 0;
	animspeed = 10;
}

Character_Shield::~Character_Shield()
{
	for (int i = 0; i != 8; ++i)
	{
		DeleteGraph(gr_side[i]);
		DeleteGraph(gr_forward[i]);
	}
	for (int i = 0; i != 4; ++i)
	{
		DeleteGraph(gr_backward[i]);
	}
}

void Character_Shield::Process()
{
	// 直前座標に移す
	prex = x;
	prey = y;

	Character::MoveControl();

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

void Character_Shield::Draw()
{
	if (direction == 0)
	{
		DrawGraph(x, y, gr_side[(animcount / animspeed) % 8], true);
	}
	else if (direction == 1)
	{
		DrawGraph(x, y, gr_forward[(animcount / animspeed) % 8], true);
	}
	else if (direction == 2)
	{
		DrawTurnGraph(x, y, gr_side[(animcount / animspeed) % 8], true);
	}
	else if (direction == 3)
	{
		DrawGraph(x, y, gr_backward[(animcount / animspeed) % 4], true);
	}
}