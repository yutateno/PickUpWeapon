#include "Doll.h"

Doll::Doll()
{
	
}

Doll::Doll(int x, int y, int direction, int targetX, int targetY, int targetnP)
{
	LoadDivGraph("media\\throw\\呪いの人形　前.png", 8, 8, 1, 64, 64, gr_down);
	LoadDivGraph("media\\throw\\呪いの人形　後.png", 8, 8, 1, 64, 64, gr_up);
	LoadDivGraph("media\\throw\\呪いの人形　左.png", 8, 8, 1, 64, 64, gr_left);
	LoadDivGraph("media\\throw\\呪いの人形　右.png", 8, 8, 1, 64, 64, gr_right);

	switch (direction)
	{
	case 0:
		this->x = x + 64;
		this->y = y;
		if (this->x >= 1920 - 128)
		{
			this->x = 1920 - 128;
		}
		break;
	case 1:
		this->x = x;
		this->y = y + 64;
		if (this->y >= 1080 - 128)
		{
			this->y = 1080 - 128;
		}
		break;
	case 2:
		this->x = x - 64;
		this->y = y;
		if (this->x <= 64)
		{
			this->x = 64;
		}
		break;
	case 3:
		this->x = x;
		this->y = y - 64;
		if (this->y <= 64)
		{
			this->y = 64;
		}
		break;
	default:
		break;
	}

	this->direction = direction;

	speed = 1;
	hp = 30 * 4;

	this->targetX = targetX;
	this->targetY = targetY;
	this->targetnP = targetnP;

	animcount = 0;
	animspeed = 10;
	anim = false;
	diremove = false;
	hit = false;
	timelimit = 900;
}

Doll::~Doll()
{
	for (int i = 0; i != 6; ++i)
	{
		DeleteGraph(gr_up[i]);
		DeleteGraph(gr_down[i]);
		DeleteGraph(gr_left[i]);
		DeleteGraph(gr_right[i]);
	}
}

void Doll::Draw()
{
	timelimit--;
	if (direction == 0)
	{
		DrawGraph(x, y, gr_right[(animcount / animspeed) % 8], true);
	}
	if (direction == 1)
	{
		DrawGraph(x, y, gr_down[(animcount / animspeed) % 8], true);
	}
	if (direction == 2)
	{
		DrawGraph(x, y, gr_left[(animcount / animspeed) % 8], true);
	}
	if (direction == 3)
	{
		DrawGraph(x, y, gr_up[(animcount / animspeed) % 8], true);
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

void Doll::Move()
{
	if (anim == false)
	{
		if (diremove == false)
		{
			if (targetX >= x + 32)
			{
				direction = 0;
				anim = true;
			}
			else if (targetX <= x - 32)
			{
				direction = 2;
				anim = true;
			}
			else
			{
				diremove = true;
			}
		}
		else if (diremove == true)
		{
			if (targetY >= y + 32)
			{

				direction = 1;
				anim = true;
			}
			else if (targetY <= y - 32)
			{

				direction = 3;
				anim = true;
			}
			else
			{
				diremove = false;
			}
		}
	}
	else
	{
		switch (direction)
		{
		case 0:
			x += speed;
			break;
		case 1:
			y += speed;
			break;
		case 2:
			x -= speed;
			break;
		case 3:
			y -= speed;
			break;
		default:
			break;
		}

		if ((diremove == false && x % 64 == 0)
			|| (diremove == true && y % 64 == 0))
		{
			diremove = !diremove;
			anim = false;
		}
	}
	if (hit == true)
	{
		hitwait++;
	}
	if (hitwait > 10 || hit == false)
	{
		hitwait = 0;
	}
}

void Doll::SetDire()
{
	switch (direction)
	{
	case 3:
		y += speed;
		break;
	case 0:
		x -= speed;
		break;
	case 1:
		y -= speed;
		break;
	case 2:
		x += speed;
		break;
	default:
		break;
	}
	diremove = !diremove;
	anim = false;
}

void Doll::SetXY(int targetX, int targetY)
{
	this->targetX = targetX;
	this->targetY = targetY;
}

int Doll::GetX()
{
	return x;
}

int Doll::GetY()
{
	return y;
}

bool Doll::GetAttack()
{
	return{ hitwait == 1 };
}

int Doll::GetLimit()
{
	return timelimit;
}

int Doll::GetTargetP()
{
	return targetnP;
}