#include "Character_Bomb.h"

Character_Bomb::Character_Bomb()
{

}

Character_Bomb::Character_Bomb(int x, int y, int hp, int nP, int direction)
{
	switch (nP)
	{
	case 1:
		LoadDivGraph("media\\player\\1P\\bomb\\‘O\\ˆÚ“®.png", 8, 8, 1, 64, 64, gr_forward);
		LoadDivGraph("media\\player\\1P\\bomb\\‰¡\\ˆÚ“®.png", 8, 8, 1, 64, 64, gr_side);
		LoadDivGraph("media\\player\\1P\\bomb\\Œã‚ë\\ˆÚ“®.png", 4, 4, 1, 64, 64, gr_backward);
		gr_bomb_estimation = LoadGraph("media\\player\\1P\\bomb\\”š’e—\‘ª.png");
		break;
	case 2:
		LoadDivGraph("media\\player\\2P\\bomb\\‘O\\ˆÚ“®.png", 8, 8, 1, 64, 64, gr_forward);
		LoadDivGraph("media\\player\\2P\\bomb\\‰¡\\ˆÚ“®.png", 8, 8, 1, 64, 64, gr_side);
		LoadDivGraph("media\\player\\2P\\bomb\\Œã‚ë\\ˆÚ“®.png", 4, 4, 1, 64, 64, gr_backward);
		gr_bomb_estimation = LoadGraph("media\\player\\2P\\bomb\\”š’e—\‘ª.png");
		break;
	case 3:
		LoadDivGraph("media\\player\\3P\\bomb\\‘O\\ˆÚ“®.png", 8, 8, 1, 64, 64, gr_forward);
		LoadDivGraph("media\\player\\3P\\bomb\\‰¡\\ˆÚ“®.png", 8, 8, 1, 64, 64, gr_side);
		LoadDivGraph("media\\player\\3P\\bomb\\Œã‚ë\\ˆÚ“®.png", 4, 4, 1, 64, 64, gr_backward);
		gr_bomb_estimation = LoadGraph("media\\player\\3P\\bomb\\”š’e—\‘ª.png");
		break;
	case 4:
		LoadDivGraph("media\\player\\4P\\bomb\\‘O\\ˆÚ“®.png", 8, 8, 1, 64, 64, gr_forward);
		LoadDivGraph("media\\player\\4P\\bomb\\‰¡\\ˆÚ“®.png", 8, 8, 1, 64, 64, gr_side);
		LoadDivGraph("media\\player\\4P\\bomb\\Œã‚ë\\ˆÚ“®.png", 4, 4, 1, 64, 64, gr_backward);
		gr_bomb_estimation = LoadGraph("media\\player\\4P\\bomb\\”š’e—\‘ª.png");
		break;
	default:
		break;
	}

	bombX = 0;
	bombY = 0;

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

Character_Bomb::~Character_Bomb()
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
	DeleteGraph(gr_bomb_estimation);
}

void Character_Bomb::Process()
{
	// ’¼‘OÀ•W‚ÉˆÚ‚·
	prex = x;
	prey = y;

	Character::MoveControl();

	// ƒfƒoƒbƒO
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

void Character_Bomb::Draw()
{
	if (direction == 0)
	{
		DrawGraph(x, y, gr_side[(animcount / animspeed) % 8], true);
		bombX = x - (x % 64) + (64 * 4);
		bombY = y;
		if (bombX > (1920 - 128))
		{
			bombX = 1920 - 128;
		}
		if (bombY < 64)
		{
			bombY = 64;
		}
		else if (bombY > 1080 - 64)
		{
			bombY = 1080 - 64;
		}
		DrawGraph(bombX, bombY, gr_bomb_estimation, true);
	}
	if (direction == 1)
	{
		DrawGraph(x, y, gr_forward[(animcount / animspeed) % 8], true);
		bombX = x;
		bombY = y - (y % 64) + (64 * 4);
		if (bombY > (1080 - 128))
		{
			bombY = 1080 - 128;
		}
		if (bombX < 64)
		{
			bombX = 64;
		}
		else if (bombX > 1920 - 64)
		{
			bombX = 1920 - 64;
		}
		DrawGraph(bombX, bombY, gr_bomb_estimation, true);
	}
	if (direction == 2)
	{
		DrawTurnGraph(x, y, gr_side[(animcount / animspeed) % 8], true);
		bombX = x - (x % 64) - (64 * 3);
		bombY = y;
		if (bombX < 64)
		{
			bombX = 64;
		}
		if (bombY < 64)
		{
			bombY = 64;
		}
		else if (bombY > 1080 - 64)
		{
			bombY = 1080 - 64;
		}
		DrawGraph(bombX, bombY, gr_bomb_estimation, true);
	}
	if (direction == 3)
	{
		DrawGraph(x, y, gr_backward[(animcount / animspeed) % 4], true);
		bombX = x;
		bombY = y - (y % 64) - (64 * 3);
		if (bombY < 64)
		{
			bombY = 64;
		}
		if (bombX < 64)
		{
			bombX = 64;
		}
		else if (this->x > 1920 - 64)
		{
			bombX = 1920 - 64;
		}
		DrawGraph(bombX, bombY, gr_bomb_estimation, true);
	}
}