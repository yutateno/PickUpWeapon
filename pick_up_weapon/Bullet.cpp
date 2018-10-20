#include "Bullet.h"

Bullet::Bullet()
{

}

Bullet::Bullet(int x, int y, int direction, int speed, int power)
{
	gr = LoadGraph("media\\gameother\\tama.png");
	this->x = x;
	this->y = y;
	this->direction = direction;
	this->speed = speed;
	this->power = power;
}

Bullet::~Bullet()
{
	DeleteGraph(gr);
}

void Bullet::Move()
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
}

void Bullet::Draw()
{
	switch (direction)
	{
	case 0:
		DrawRotaGraph(x + 8, y + 8, 1, 0, gr, true, false);
		break;
	case 1:
		DrawRotaGraph(x + 8, y + 8, 1, 3.14159265 / 2, gr, true, false);
		break;
	case 2:
		DrawRotaGraph(x + 8, y + 8, 1, 0, gr, true, true);
		break;
	case 3:
		DrawRotaGraph(x + 8, y + 8, 1, 3.14159265 / 2, gr, true, true);
		break;
	default:
		break;
	}
}

int Bullet::GetX()
{
	return x;
}

int Bullet::GetY()
{
	return y;
}

int Bullet::GetPower()
{
	return power;
}

int Bullet::GetDire()
{
	return direction;
}