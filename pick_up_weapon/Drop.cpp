#include "Drop.h"

Drop::Drop()
{

}

Drop::Drop(int x, int y, int ID)
{
	this->x = x;
	this->y = y;
	this->ID = ID;

	switch (ID)
	{
	case 0:
		Gr = LoadGraph("media\\drop\\knife.png");
		break;
	case 1:
		Gr = LoadGraph("media\\drop\\sword.png");
		break;
	case 2:
		Gr = LoadGraph("media\\drop\\traversal.png");
		break;
	case 3:
		Gr = LoadGraph("media\\drop\\flame_magic_book.png");
		break;
	case 4:
		Gr = LoadGraph("media\\drop\\venom_bottle.png");
		break;
	case 5:
		Gr = LoadGraph("media\\drop\\shield.png");
		break;
	case 6:
		Gr = LoadGraph("media\\drop\\sniper.png");
		break;
	case 7:
		Gr = LoadGraph("media\\drop\\knife.png");
		break;
	case 8:
		Gr = LoadGraph("media\\drop\\gun_seat.png");
		break;
	case 9:
		Gr = LoadGraph("media\\drop\\gatling.png");
		break;
	case 10:
		Gr = LoadGraph("media\\drop\\curse_doll.png");
		break;
	case 11:
		Gr = LoadGraph("media\\drop\\bomb.png");
		break;
	default:
		break;
	}
}

Drop::~Drop()
{
	DeleteGraph(Gr);
}

void Drop::Draw()
{
	DrawGraph(x, y, Gr, true);
}

int Drop::GetX()
{
	return x;
}

int Drop::GetY()
{
	return y;
}

int Drop::GetID()
{
	return ID;
}