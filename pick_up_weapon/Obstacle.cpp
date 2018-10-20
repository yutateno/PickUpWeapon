#include "Obstacle.h"

Obstacle::Obstacle()
{

}

Obstacle::Obstacle(int ID, int x, int y)
{
	hitflag = false;
	brokenflag = false;
	breakflag = false;

	animcount = 0;
	animbreakcount = 39;
	breakcount = 0;
	animspeed = 10;

	this->ID = ID;
	this->x = x;
	this->y = y;

	switch (ID)
	{
	case 11:
		LoadDivGraph("media\\map\\capsule.png", 6, 6, 1, 64, 64, capsule);
		LoadDivGraph("media\\map\\capsule_break.png", 13, 10, 2, 64, 64, capsule_break);
		capsule_broken = LoadGraph("media\\map\\capsule_broken.png");
		break;
	case 12:
		rock = LoadGraph("media\\map\\rock.png");
		LoadDivGraph("media\\map\\rock_break.png", 11, 10, 2, 64, 64, rock_break);
		rock_broken = LoadGraph("media\\map\\rock_broken.png");
		break;
	}
}

Obstacle::~Obstacle()
{
	switch (ID)
	{
	case 11:
		for (int i = 0; i != 6; ++i)
		{
			DeleteGraph(capsule[i]);
		}
		for (int i = 0; i != 13; ++i)
		{
			DeleteGraph(capsule_break[i]);
		}
		DeleteGraph(capsule_broken);
		break;
	case 12:
		DeleteGraph(rock);
		for (int i = 0; i != 11; ++i)
		{
			DeleteGraph(rock_break[i]);
		}
		DeleteGraph(rock_broken);
		break;
	}
}

void Obstacle::Draw_Normal()
{
	switch (ID)
	{
	case 11:
		DrawGraph(x, y, capsule[(animcount / animspeed) % 6], true);
		break;
	case 12:
		DrawGraph(x, y, rock, true);
		break;
	}
	if (ID == 11)
	{
		if (animcount < animspeed * 6)
		{
			animcount++;
		}
		else
		{
			animcount = 0;
		}
	}
	if (hitflag == true)
	{
		breakflag = true;
	}
}

void Obstacle::Draw_Break()
{
	switch (ID)
	{
	case 11:
		if (breakcount > 3)
		{
			DrawGraph(x, y, capsule_break[(animbreakcount / animspeed) % 13], true);
		}
		else
		{
			DrawGraph(x, y, capsule_break[breakcount], true);
		}
		break;
	case 12:
		if (breakcount > 4)
		{
			DrawGraph(x, y, rock_break[(animbreakcount / animspeed) % 11], true);
		}
		else
		{
			DrawGraph(x, y, rock_break[breakcount], true);
		}
		break;
	}
	if (hitflag == true)
	{
		breakcount++;
		hitflag = false;
	}
	if (ID == 11)
	{
		if (breakcount > 3)
		{
			hitflag = true;
			if (animbreakcount < animspeed * 11)
			{
				animbreakcount++;
			}
			else
			{
				brokenflag = true;
			}
		}
	}
	else if (ID == 12)
	{
		if (breakcount > 4)
		{
			hitflag = true;
			if (animbreakcount < animspeed * 10)
			{
				animbreakcount++;
			}
			else
			{
				brokenflag = true;
			}
		}
	}
}

void Obstacle::Draw_Broken()
{
	switch (ID)
	{
	case 11:
		DrawGraph(x, y, capsule_broken, true);
		break;
	case 12:
		DrawGraph(x, y, rock_broken, true);
		break;
	}
}

bool Obstacle::GetBrokenFlag()
{
	return brokenflag;
}

bool Obstacle::GetBreakFlag()
{
	return breakflag;
}

int Obstacle::GetX()
{
	return x;
}

int Obstacle::GetY()
{
	return y;
}

int Obstacle::GetID()
{
	return ID;
}

int Obstacle::GetHowBreak()
{
	return animbreakcount;
}