#include "Gun_Seat.h"

Gun_Seat::Gun_Seat()
{

}

Gun_Seat::Gun_Seat(int x, int y, int direction)
{
	switch (direction)
	{
	case 0:
		LoadDivGraph("media\\throw\\eÀ@‰¡.png", 2, 2, 1, 64, 64, gr_side);
		break;
	case 1:
		LoadDivGraph("media\\throw\\eÀ@‰º.png", 2, 2, 1, 64, 64, gr_down);
		break;
	case 2:
		LoadDivGraph("media\\throw\\eÀ@‰¡.png", 2, 2, 1, 64, 64, gr_side);
		break;
	case 3:
		LoadDivGraph("media\\throw\\eÀ@ã.png", 2, 2, 1, 64, 64, gr_up);
		break;
	default:
		break;
	}

	this->direction = direction;
	this->x = x;
	this->y = y;
	hp = 150;
	gunnum = 50;
	gunframe = 3;

	animcount = 0;
	animspeed = 10;
	waitcount = 0;
}

Gun_Seat::~Gun_Seat()
{
	for (int i = 0; i != 2; ++i)
	{
		switch (direction)
		{
		case 0:
			DeleteGraph(gr_down[i]);
			break;
		case 1:
			DeleteGraph(gr_up[i]);
			break;
		case 2:
			DeleteGraph(gr_side[i]);
			break;
		case 3:
			DeleteGraph(gr_side[i]);
			break;
		default:
			break;
		}
	}
}

void Gun_Seat::Do()
{
	if (waitcount < 50)
	{
		waitcount++;
	}
	else
	{
		gunframe++;
	}
}

void Gun_Seat::Draw()
{
	if (direction == 0)
	{
		DrawGraph(x, y, gr_side[(animcount / animspeed) % 2], true);
	}
	if (direction == 1)
	{
		DrawGraph(x, y, gr_down[(animcount / animspeed) % 2], true);
	}
	if (direction == 2)
	{
		DrawTurnGraph(x, y, gr_side[(animcount / animspeed) % 2], true);
	}
	if (direction == 3)
	{
		DrawGraph(x, y, gr_up[(animcount / animspeed) % 2], true);
	}

	if (animcount < animspeed * 2 && gunnum > 0)
	{
		animcount++;
	}
	else if(gunnum == 0)
	{
		animcount = 0;
	}
}

int Gun_Seat::GetDire()
{
	return direction;
}

int Gun_Seat::GetX()
{
	return x;
}

int Gun_Seat::GetY()
{
	return y;
}

int Gun_Seat::GetShot()
{
	return gunframe;
}