#include "Character_GunSeat.h"

Character_GunSeat::Character_GunSeat()
{

}

Character_GunSeat::Character_GunSeat(int x, int y, int hp, int nP, int direction)
{
	switch (nP)
	{
	case 1:
		LoadDivGraph("media\\player\\1P\\normal\\装備なし　前.png", 8, 8, 1, 64, 64, gr_forward);
		LoadDivGraph("media\\player\\1P\\normal\\装備なし.png", 8, 8, 1, 64, 64, gr_side);
		LoadDivGraph("media\\player\\1P\\normal\\装備なし　後ろ.png", 4, 4, 1, 64, 64, gr_backward);
		break;
	case 2:
		LoadDivGraph("media\\player\\2P\\normal\\装備なし 前.png", 8, 8, 1, 64, 64, gr_forward);
		LoadDivGraph("media\\player\\2P\\normal\\装備なし 横.png", 8, 8, 1, 64, 64, gr_side);
		LoadDivGraph("media\\player\\2P\\normal\\装備なし 後.png", 4, 4, 1, 64, 64, gr_backward);
		break;
	case 3:
		LoadDivGraph("media\\player\\3P\\normal\\プレイヤー３前.png", 7, 7, 1, 64, 64, gr_forward);
		LoadDivGraph("media\\player\\3P\\normal\\プレイヤー３横.png", 8, 8, 1, 64, 64, gr_side);
		LoadDivGraph("media\\player\\3P\\normal\\プレイヤー３後.png", 4, 4, 1, 64, 64, gr_backward);
		break;
	case 4:
		LoadDivGraph("media\\player\\4P\\normal\\プレイヤー４前.png", 8, 8, 1, 64, 64, gr_forward);
		LoadDivGraph("media\\player\\4P\\normal\\プレイヤー４ 横.png", 8, 8, 1, 64, 64, gr_side);
		LoadDivGraph("media\\player\\4P\\normal\\プレイヤー４後.png", 4, 4, 1, 64, 64, gr_backward);
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

Character_GunSeat::~Character_GunSeat()
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

void Character_GunSeat::Process()
{
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

void Character_GunSeat::Draw()
{
	if (direction == 0)
	{
		DrawGraph(x, y, gr_side[(animcount / animspeed) % 8], true);
	}
	if (direction == 1)
	{
		if (nP != 3)
		{
			DrawGraph(x, y, gr_forward[(animcount / animspeed) % 8], true);
		}
		else
		{
			DrawGraph(x, y, gr_forward[(animcount / animspeed) % 7], true);
		}
	}
	if (direction == 2)
	{
		DrawTurnGraph(x, y, gr_side[(animcount / animspeed) % 8], true);
	}
	if (direction == 3)
	{
		DrawGraph(x, y, gr_backward[(animcount / animspeed) % 4], true);
	}
}