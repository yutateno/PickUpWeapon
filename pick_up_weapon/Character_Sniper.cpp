#include "Character_Sniper.h"

Character_Sniper::Character_Sniper()
{

}

Character_Sniper::Character_Sniper(int x, int y, int hp, int nP, int direction)
{
	switch (nP)
	{
	case 1:
		LoadDivGraph("media\\player\\1P\\sniper\\前\\移動.png", 4, 4, 1, 64, 64, gr_forward);
		LoadDivGraph("media\\player\\1P\\sniper\\右\\移動.png", 4, 4, 1, 64, 64, gr_right);
		LoadDivGraph("media\\player\\1P\\sniper\\左\\移動.png", 4, 4, 1, 64, 64, gr_left);
		LoadDivGraph("media\\player\\1P\\sniper\\後ろ\\移動.png", 4, 4, 1, 64, 64, gr_backward);

		LoadDivGraph("media\\player\\1P\\sniper\\前\\撃ち.png", 2, 2, 1, 64, 64, gr_shoot_forward);
		LoadDivGraph("media\\player\\1P\\sniper\\右\\撃ち.png", 2, 2, 1, 64, 64, gr_shoot_right);
		LoadDivGraph("media\\player\\1P\\sniper\\左\\撃ち.png", 2, 2, 1, 64, 64, gr_shoot_left);
		break;
	case 2:
		LoadDivGraph("media\\player\\2P\\sniper\\前\\移動.png", 4, 4, 1, 64, 64, gr_forward);
		LoadDivGraph("media\\player\\2P\\sniper\\右\\移動.png", 4, 4, 1, 64, 64, gr_right);
		LoadDivGraph("media\\player\\2P\\sniper\\左\\移動.png", 4, 4, 1, 64, 64, gr_left);
		LoadDivGraph("media\\player\\2P\\sniper\\後ろ\\移動.png", 4, 4, 1, 64, 64, gr_backward);

		LoadDivGraph("media\\player\\2P\\sniper\\前\\撃ち.png", 2, 2, 1, 64, 64, gr_shoot_forward);
		LoadDivGraph("media\\player\\2P\\sniper\\右\\撃ち.png", 2, 2, 1, 64, 64, gr_shoot_right);
		LoadDivGraph("media\\player\\2P\\sniper\\左\\撃ち.png", 2, 2, 1, 64, 64, gr_shoot_left);
		break;
	case 3:
		LoadDivGraph("media\\player\\3P\\sniper\\前\\移動.png", 4, 4, 1, 64, 64, gr_forward);
		LoadDivGraph("media\\player\\3P\\sniper\\右\\移動.png", 4, 4, 1, 64, 64, gr_right);
		LoadDivGraph("media\\player\\3P\\sniper\\左\\移動.png", 4, 4, 1, 64, 64, gr_left);
		LoadDivGraph("media\\player\\3P\\sniper\\後ろ\\移動.png", 4, 4, 1, 64, 64, gr_backward);

		LoadDivGraph("media\\player\\3P\\sniper\\前\\撃ち.png", 2, 2, 1, 64, 64, gr_shoot_forward);
		LoadDivGraph("media\\player\\3P\\sniper\\右\\撃ち.png", 2, 2, 1, 64, 64, gr_shoot_right);
		LoadDivGraph("media\\player\\3P\\sniper\\左\\撃ち.png", 2, 2, 1, 64, 64, gr_shoot_left);
		break;
	case 4:
		LoadDivGraph("media\\player\\4P\\sniper\\前\\移動.png", 4, 4, 1, 64, 64, gr_forward);
		LoadDivGraph("media\\player\\4P\\sniper\\右\\移動.png", 4, 4, 1, 64, 64, gr_right);
		LoadDivGraph("media\\player\\4P\\sniper\\左\\移動.png", 4, 4, 1, 64, 64, gr_left);
		LoadDivGraph("media\\player\\4P\\sniper\\後ろ\\移動.png", 4, 4, 1, 64, 64, gr_backward);

		LoadDivGraph("media\\player\\4P\\sniper\\前\\撃ち.png", 2, 2, 1, 64, 64, gr_shoot_forward);
		LoadDivGraph("media\\player\\4P\\sniper\\右\\撃ち.png", 2, 2, 1, 64, 64, gr_shoot_right);
		LoadDivGraph("media\\player\\4P\\sniper\\左\\撃ち.png", 2, 2, 1, 64, 64, gr_shoot_left);
		break;
	default:
		break;
	}

	reload_se = LoadSoundMem("sound\\reload.wav");
	speed = 3;
	this->x = x;
	this->y = y;
	this->hp = hp;
	this->nP = nP;
	this->direction = direction;
	RTbutton = 0;
	tamanum = 7;
	waitcount = 110;
	sniperframe = 0;
	animcount = 0;
	animspeed = 10;
}

Character_Sniper::~Character_Sniper()
{
	for (int i = 0; i != 4; ++i)
	{
		DeleteGraph(gr_backward[i]);
		DeleteGraph(gr_left[i]);
		DeleteGraph(gr_right[i]);
		DeleteGraph(gr_forward[i]);
	}
	for (int i = 0; i != 2; ++i)
	{
		DeleteGraph(gr_shoot_forward[i]);
		DeleteGraph(gr_shoot_right[i]);
		DeleteGraph(gr_shoot_left[i]);
	}
	DeleteSoundMem(reload_se);
}

void Character_Sniper::Process()
{
	// RTを押した状態でスナイパーのリロードが終えていたら
	if (input.Z == -1000 && waitcount > 100)
	{
		sniperframe++;
	}
	// RTから少しでも離していたら
	else if(input.Z != -1000)
	{
		sniperframe = 0;
		RTbutton = 0;
		if (waitcount < 110)
		{
			waitcount++;
			if (waitcount == 90)
			{
				PlaySoundMem(reload_se, DX_PLAYTYPE_BACK, TRUE);
			}
		}
	}
	// リロードを終えている状態でRTを押したら一回だけ撃つように処理
	if (sniperframe == 1)
	{
		RTbutton = 1;
	}
	// 一回でも撃ったらリロードさせる
	else if (sniperframe > 1)
	{
		RTbutton = 3;
		waitcount = 0;
	}

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

void Character_Sniper::Draw()
{
	if (waitcount > 16)
	{
		switch (direction)
		{
		case 0:
			DrawGraph(x, y, gr_right[(animcount / animspeed) % 4], true);
			break;
		case 1:
			DrawGraph(x, y, gr_forward[(animcount / animspeed) % 4], true);
			break;
		case 2:
			DrawGraph(x, y, gr_left[(animcount / animspeed) % 4], true);
			break;
		case 3:
			DrawGraph(x, y, gr_backward[(animcount / animspeed) % 4], true);
			break;
		default:
			break;
		}
	}
	else
	{
		switch (direction)
		{
		case 0:
			DrawGraph(x, y, gr_shoot_right[(animcount / animspeed) % 2], true);
			break;
		case 1:
			DrawGraph(x, y, gr_shoot_forward[(animcount / animspeed) % 2], true);
			break;
		case 2:
			DrawGraph(x, y, gr_shoot_left[(animcount / animspeed) % 2], true);
			break;
		case 3:
			DrawGraph(x, y, gr_backward[(animcount / animspeed) % 2], true);
			break;
		default:
			break;
		}
	}
}