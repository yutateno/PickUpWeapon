#include "Title.h"

Title::Title()
{
	gr_back = LoadGraph("media\\title\\title.png");
	gr_two = LoadGraph("media\\title\\two.png");
	gr_three = LoadGraph("media\\title\\three.png");
	gr_four = LoadGraph("media\\title\\four.png");
	gr_end = LoadGraph("media\\title\\end.png");
	gr_extra = LoadGraph("media\\title\\extra.png");

	LoadDivGraph("media\\player\\2P\\sniper\\‰E\\Œ‚‚¿.png", 2, 2, 1, 64, 64, gr_icon_two);
	LoadDivGraph("media\\player\\3P\\sniper\\‰E\\Œ‚‚¿.png", 2, 2, 1, 64, 64, gr_icon_three);
	LoadDivGraph("media\\player\\4P\\sniper\\‰E\\Œ‚‚¿.png", 2, 2, 1, 64, 64, gr_icon_four);
	LoadDivGraph("media\\player\\1P\\bomb\\‰¡\\ˆÚ“®.png", 8, 8, 1, 64, 64, gr_icon_end);
	LoadDivGraph("media\\throw\\”š”­.png", 5, 5, 1, 64, 64, gr_icon_endclick);

	playmode = 0;

	extraflag = false;

	clickflag = false;
}

Title::~Title()
{
	DeleteGraph(gr_back);
	DeleteGraph(gr_two);
	DeleteGraph(gr_three);
	DeleteGraph(gr_four);
	DeleteGraph(gr_end);
	DeleteGraph(gr_extra);

	for (int i = 0; i != 2; ++i)
	{
		DeleteGraph(gr_icon_two[i]);
		DeleteGraph(gr_icon_three[i]);
		DeleteGraph(gr_icon_four[i]);
	}
	for (int i = 0; i != 8; ++i)
	{
		DeleteGraph(gr_icon_end[i]);
	}
	for (int i = 0; i != 5; ++i)
	{
		DeleteGraph(gr_icon_endclick[i]);
	}
}

void Title::Update()
{
	Process();
	Draw();
}

void Title::Process()
{
	if (KeyData::Get(KEY_INPUT_E) == 1
		|| (PadData::Get(XINPUT_BUTTON_BACK, 0) == 1
		&& PadData::Get(XINPUT_BUTTON_START, 1) == 1))
	{
		extraflag = true;
	}


	if (KeyData::Get(KEY_INPUT_UP) == 1
		|| PadData::Get(XINPUT_BUTTON_DPAD_UP, 0) == 1
		|| PadData::Get(XINPUT_BUTTON_DPAD_UP, 1) == 1
		|| PadData::Get(XINPUT_BUTTON_DPAD_UP, 2) == 1
		|| PadData::Get(XINPUT_BUTTON_DPAD_UP, 3) == 1)
	{
		if (playmode != 0)
		{
			playmode--;
		}
	}
	if (KeyData::Get(KEY_INPUT_DOWN) == 1
		|| PadData::Get(XINPUT_BUTTON_DPAD_DOWN, 0) == 1
		|| PadData::Get(XINPUT_BUTTON_DPAD_DOWN, 1) == 1
		|| PadData::Get(XINPUT_BUTTON_DPAD_DOWN, 2) == 1
		|| PadData::Get(XINPUT_BUTTON_DPAD_DOWN, 3) == 1)
	{
		if (playmode != 3)
		{
			playmode++;
		}
	}
	if (KeyData::Get(KEY_INPUT_Z) == 1
		|| PadData::Get(XINPUT_BUTTON_A, 0) == 1
		|| PadData::Get(XINPUT_BUTTON_A, 1) == 1
		|| PadData::Get(XINPUT_BUTTON_A, 2) == 1
		|| PadData::Get(XINPUT_BUTTON_A, 3) == 1)
	{
		clickflag = true;
		switch (playmode)
		{
		case 0:
			Scene::scene = STAGESELECT;
			break;
		case 1:
			Scene::scene = STAGESELECT;
			break;
		case 2:
			Scene::scene = STAGESELECT;
			break;
		case 3:
			if (extraflag == false)
			{
				Scene::endFlag = true;
			}
			else
			{
				Scene::scene = EXTRA;
			}
			break;
		default:
			break;
		}
	}
}

void Title::Draw()
{
	DrawGraph(0, 0, gr_back, false);
	DrawGraph(810, 300, gr_two, false);
	DrawGraph(810, 450, gr_three, false);
	DrawGraph(810, 600, gr_four, false);
	if (extraflag == false)
	{
		DrawGraph(810, 750, gr_end, false);
	}
	else
	{
		DrawGraph(810, 750, gr_extra, false);
	}
	
	switch (playmode)
	{
	case 0:
		DrawGraph(750, 308, gr_icon_two[clickflag], true);
		break;
	case 1:
		DrawGraph(750, 458, gr_icon_three[clickflag], true);
		break;
	case 2:
		DrawGraph(750, 608, gr_icon_four[clickflag], true);
		break;
	case 3:
		if (clickflag == false)
		{
			DrawGraph(750, 758, gr_icon_end[0], true);
		}
		else
		{
			DrawGraph(750, 758, gr_icon_endclick[1], true);
		}
		break;
	default:
		break;
	}
}