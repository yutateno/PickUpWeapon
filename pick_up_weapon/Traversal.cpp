#include "Traversal.h"

Traversal::Traversal()
{

}

Traversal::Traversal(int x, int y, int direction)
{
	gr_wait = LoadGraph("media\\throw\\使用済みトラバサミ.png");
	gr_catch = LoadGraph("media\\throw\\発動トラバサミ.png");
	se_traversal = LoadSoundMem("sound\\トラばさみ.wav");

	switch (direction)
	{
	case 0:
		this->x = x + 70;
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
		this->y = y + 70;
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
		this->x = x - 70;
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
		this->y = y - 70;
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

	traversalframe = 0;
	catchflag = false;
}

Traversal::~Traversal()
{
	DeleteGraph(gr_wait);
	DeleteGraph(gr_catch);

	DeleteSoundMem(se_traversal);
}

void Traversal::Draw()
{
	if (catchflag == true && traversalframe == 0)
	{
		PlaySoundMem(se_traversal, DX_PLAYTYPE_BACK, FALSE);
	}
	if (catchflag == true)
	{
		traversalframe++;
		DrawGraph(x, y, gr_catch, true);
	}
	else
	{
		DrawGraph(x, y, gr_wait, true);
	}
}

int Traversal::GetX()
{
	return x;
}

int Traversal::GetY()
{
	return y;
}

int Traversal::GetFrame()
{
	return traversalframe;
}