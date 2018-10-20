#include "Character.h"

Character::Character()
{
	RTbutton = 0;
	RBframe = 0;
	LBframe = 0;
	Aframe = 0;
	startwaitcount = 0;
}

void Character::MoveControl()
{
	// “ü—Íó‘Ô‚ðŽæ“¾
	switch (nP)
	{
	case 1:
		GetJoypadDirectInputState(DX_INPUT_PAD1, &input);
		break;
	case 2:
		GetJoypadDirectInputState(DX_INPUT_PAD2, &input);
		break;
	case 3:
		GetJoypadDirectInputState(DX_INPUT_PAD3, &input);
		break;
	case 4:
		GetJoypadDirectInputState(DX_INPUT_PAD4, &input);
		break;
	default:
		break;
	}

	// ˆÚ“®
	if (startwaitcount >= 3)
	{
		if (hp > 0)
		{
			if (KeyData::Get(KEY_INPUT_RIGHT) > 0
				|| input.X > 0)
			{
				x += speed;
			}
			if (KeyData::Get(KEY_INPUT_LEFT) > 0
				|| input.X < 0)
			{
				x -= speed;
			}
			if (KeyData::Get(KEY_INPUT_UP) > 0
				|| input.Y < 0)
			{
				y -= speed;
			}
			if (KeyData::Get(KEY_INPUT_DOWN) > 0
				|| input.Y > 0)
			{
				y += speed;
			}
		}
	}
	else
	{
		startwaitcount++;
	}
	// Œü‚«
	if (input.Rx > 0)
	{
		direction = 0;
	}
	if (input.Rx < 0)
	{
		direction = 2;
	}
	if (input.Ry < 0)
	{
		direction = 3;
	}
	if (input.Ry > 0)
	{
		direction = 1;
	}

	if (input.Buttons[0] == 128)
	{
		if (Aframe != 128)
		{
			Aframe++;
		}
	}
	else
	{
		Aframe = 0;
	}
	if (input.Buttons[5] == 128)
	{
		if (RBframe != 128)
		{
			RBframe++;
		}
	}
	else
	{
		RBframe = 0;
	}
	if (input.Buttons[4] == 128)
	{
		if (LBframe != 128)
		{
			LBframe++;
		}
	}
	else
	{
		LBframe = 0;
	}
}

void Character::MoveControl2()
{
	if (KeyData::Get(KEY_INPUT_D) > 0)
	{
		x += speed;
		direction = 0;
	}
	if (KeyData::Get(KEY_INPUT_A) > 0)
	{
		x -= speed;
		direction = 2;
	}
	if (KeyData::Get(KEY_INPUT_W) > 0)
	{
		y -= speed;
		direction = 3;
	}
	if (KeyData::Get(KEY_INPUT_S) > 0)
	{
		y += speed;
		direction = 1;
	}
}

int Character::GetX()
{
	return x;
}

int Character::GetY()
{
	return y;
}

int Character::GetDire()
{
	return direction;
}

void Character::MoveReset()
{
	x = prex;
	y = prey;
}

int Character::GetRTbutton()
{
	return RTbutton;
}

int Character::GetAbutton()
{
	return Aframe;
}

int Character::GetRBbutton()
{
	return RBframe;
}

int Character::GetLBbutton()
{
	return LBframe;
}