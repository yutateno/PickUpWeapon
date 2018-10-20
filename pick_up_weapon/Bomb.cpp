#include "Bomb.h"

Bomb::Bomb()
{

}

Bomb::Bomb(int x, int y, int direction)
{
	LoadDivGraph("media\\throw\\����.png", 5, 5, 1, 64, 64, gr);
	se_bomb = LoadSoundMem("sound\\����.wav");

	this->direction = direction;

	switch (direction)
	{
	case 0:
		this->x = x - (x % 64) + (64 * 4);
		this->y = y;
		if (this->x > (1920 - 128))
		{
			this->x = 1920 - 128;
		}
		if (this->y < 64)
		{
			this->y = 64;
		}
		else if (this->y > 1080 - 64)
		{
			this->y = 1080 - 64;
		}
		break;
	case 1:
		this->x = x;
		this->y = y - (y % 64) + (64 * 4);
		if (this->y > (1080 - 128))
		{
			this->y = 1080 - 128;
		}
		if (this->x < 64)
		{
			this->x = 64;
		}
		else if (this->x > 1920 - 64)
		{
			this->x = 1920 - 64;
		}
		break;
	case 2:
		this->x = x - (x % 64) - (64 * 3);
		this->y = y;
		if (this->x < 64)
		{
			this->x = 64;
		}
		if (this->y < 64)
		{
			this->y = 64;
		}
		else if (this->y > 1080 - 64)
		{
			this->y = 1080 - 64;
		}
		break;
	case 3:
		this->x = x;
		this->y = y - (y % 64) - (64 * 3);
		if (this->y < 64)
		{
			this->y = 64;
		}
		if (this->x < 64)
		{
			this->x = 64;
		}
		else if (this->x > 1920 - 64)
		{
			this->x = 1920 - 64;
		}
		break;
	default:
		break;
	}

	animcount = 0;
	animspeed = 10;

	bombframe = 0;
}

Bomb::~Bomb()
{
	for (int i = 0; i != 3; ++i)
	{
		DeleteGraph(gr[i]);
	}
	DeleteSoundMem(se_bomb);
}

void Bomb::Draw()
{
	bombframe++;
	if (bombframe == 1)
	{
		PlaySoundMem(se_bomb, DX_PLAYTYPE_BACK, FALSE);
	}
	if (bombframe >= 0 && bombframe <= 20)
	{
		DrawGraph(x, y, gr[(animcount / animspeed) % 5], true);	// �^��
	}
	if (bombframe >= 20)
	{
		DrawGraph(x - 64, y - 64, gr[(animcount / animspeed) % 5], true);	// ����
		DrawGraph(x, y - 64, gr[(animcount / animspeed) % 5], true);	// ��
		DrawGraph(x + 64, y - 64, gr[(animcount / animspeed) % 5], true);	// �E��
		DrawGraph(x - 64, y, gr[(animcount / animspeed) % 5], true);	// ��
		DrawGraph(x + 64, y, gr[(animcount / animspeed) % 5], true);	// �E
		DrawGraph(x - 64, y + 64, gr[(animcount / animspeed) % 5], true);	// ����
		DrawGraph(x, y + 64, gr[(animcount / animspeed) % 5], true);	// ��
		DrawGraph(x + 64, y + 64, gr[(animcount / animspeed) % 5], true);	// �E��
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

int Bomb::GetX()
{
	return x;
}

int Bomb::GetY()
{
	return y;
}

int Bomb::GetFrame()
{
	return bombframe;
}