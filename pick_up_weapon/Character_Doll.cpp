#include "Character_Doll.h"

Character_Doll::Character_Doll()
{

}

Character_Doll::Character_Doll(int x, int y, int hp, int nP, int direction)
{
	switch (nP)
	{
	case 1:
		LoadDivGraph("media\\player\\1P\\doll\\前\\移動.png", 8, 8, 1, 64, 64, gr_forward);
		LoadDivGraph("media\\player\\1P\\doll\\右\\移動.png", 8, 8, 1, 64, 64, gr_right);
		LoadDivGraph("media\\player\\1P\\doll\\左\\移動.png", 8, 8, 1, 64, 64, gr_left);
		LoadDivGraph("media\\player\\1P\\doll\\後ろ\\移動.png", 4, 4, 1, 64, 64, gr_backward);
		break;
	case 2:
		LoadDivGraph("media\\player\\2P\\doll\\前\\移動.png", 8, 8, 1, 64, 64, gr_forward);
		LoadDivGraph("media\\player\\2P\\doll\\右\\移動.png", 8, 8, 1, 64, 64, gr_right);
		LoadDivGraph("media\\player\\2P\\doll\\左\\移動.png", 8, 8, 1, 64, 64, gr_left);
		LoadDivGraph("media\\player\\2P\\doll\\後ろ\\移動.png", 4, 4, 1, 64, 64, gr_backward);
		break;
	case 3:
		LoadDivGraph("media\\player\\3P\\doll\\前\\移動.png", 8, 8, 1, 64, 64, gr_forward);
		LoadDivGraph("media\\player\\3P\\doll\\右\\移動.png", 8, 8, 1, 64, 64, gr_right);
		LoadDivGraph("media\\player\\3P\\doll\\左\\移動.png", 8, 8, 1, 64, 64, gr_left);
		LoadDivGraph("media\\player\\3P\\doll\\後ろ\\移動.png", 4, 4, 1, 64, 64, gr_backward);
		break;
	case 4:
		LoadDivGraph("media\\player\\4P\\doll\\前\\移動.png", 8, 8, 1, 64, 64, gr_forward);
		LoadDivGraph("media\\player\\4P\\doll\\右\\移動.png", 8, 8, 1, 64, 64, gr_right);
		LoadDivGraph("media\\player\\4P\\doll\\左\\移動.png", 8, 8, 1, 64, 64, gr_left);
		LoadDivGraph("media\\player\\4P\\doll\\後ろ\\移動.png", 4, 4, 1, 64, 64, gr_backward);
		break;
	default:
		break;
	}
	speed = 3;
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

Character_Doll::~Character_Doll()
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
}

void Character_Doll::Process()
{
	// 直前座標に現在地を移す
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

void Character_Doll::Draw()
{
	switch (direction)
	{
	case 0:
		DrawGraph(x, y, gr_right[(animcount / animspeed) % 8], true);
		break;
	case 1:
		DrawGraph(x, y, gr_forward[(animcount / animspeed) % 8], true);
		break;
	case 2:
		DrawGraph(x, y, gr_left[(animcount / animspeed) % 8], true);
		break;
	case 3:
		DrawGraph(x, y, gr_backward[(animcount / animspeed) % 4], true);
		break;
	default:
		break;
	}
}