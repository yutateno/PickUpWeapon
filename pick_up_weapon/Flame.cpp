#include "Flame.h"

Flame::Flame()
{

}

Flame::Flame(int x, int y, int direction)
{
	LoadDivGraph("media\\throw\\‰Î‰Š’e.png", 4, 4, 1, 64, 64, gr_move);
	LoadDivGraph("media\\throw\\’…‰Î.png", 4, 4, 1, 64, 64, gr_flame);

	se_flame = LoadSoundMem("sound\\fire!!!!!!!!.wav");

	this->direction = direction;
	moveframe = 0;

	switch (direction)
	{
	case 0:
		this->x = x + 64;
		this->y = y;
		if (this->x >= 1920 - 128)
		{
			this->x = 1920 - 128;
			moveframe = 256;
		}
		break;
	case 1:
		this->x = x;
		this->y = y + 64;
		if (this->y >= 1080 - 128)
		{
			this->y = 1080 - 128;
			moveframe = 256;
		}
		break;
	case 2:
		this->x = x - 64;
		this->y = y;
		if (this->x <= 64)
		{
			this->x = 64;
			moveframe = 256;
		}
		break;
	case 3:
		this->x = x;
		this->y = y - 64;
		if (this->y <= 64)
		{
			this->y = 64;
			moveframe = 256;
		}
		break;
	default:
		break;
	}

	speed = 5;
	animcount = 0;
	animspeed = 10;
	wallhit = false;
}

Flame::~Flame()
{
	for (int i = 0; i != 4; ++i)
	{
		DeleteGraph(gr_move[i]);
		DeleteGraph(gr_flame[i]);
	}
	DeleteSoundMem(se_flame);
}

void Flame::Move()
{
	moveframe += speed;
	if (moveframe == 256)
	{
		PlaySoundMem(se_flame, DX_PLAYTYPE_BACK, FALSE);
	}
	if (moveframe < 256)
	{
		if (direction == 0)
		{
			x += speed;
		}
		else if (direction == 1)
		{
			y += speed;
		}
		else if (direction == 2)
		{
			x -= speed;
		}
		else
		{
			y -= speed;
		}
		if (wallhit == true)
		{
			moveframe = 256;
		}
	}
}

void Flame::Draw()
{
	if (animcount < animspeed * 8)
	{
		animcount++;
	}
	else
	{
		animcount = 0;
	}

	if (moveframe < 256)
	{
		switch (direction)
		{
		case 0:
			DrawRotaGraph(x + 32, y + 32, 1, 0, gr_move[(animcount / animspeed) % 4], true, false);
			break;
		case 1:
			DrawRotaGraph(x + 32, y + 32, 1, 3.14159265 / 2, gr_move[(animcount / animspeed) % 4], true, false);
			break;
		case 2:
			DrawRotaGraph(x + 32, y + 32, 1, 0, gr_move[(animcount / animspeed) % 4], true, true);
			break;
		case 3:
			DrawRotaGraph(x + 32, y + 32, 1, 3.14159265 / 2, gr_move[(animcount / animspeed) % 4], true, true);
			break;
		default:
			break;
		}
	}
	else
	{
		DrawGraph(x, y, gr_flame[(animcount / animspeed) % 4], true);
	}
}

int Flame::GetX()
{
	return x;
}

int Flame::GetY()
{
	return y;
}

int Flame::GetFrame()
{
	return moveframe;
}

int Flame::GetDire()
{
	return direction;
}