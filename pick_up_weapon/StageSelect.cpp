#include "StageSelect.h"

StageSelect::StageSelect()
{
	gr_back = LoadGraph("media\\stageselect\\stageselect.png");
	gr_one = LoadGraph("media\\stageselect\\砂漠マップ.png");
	gr_two = LoadGraph("media\\stageselect\\森林マップ.png");
	gr_three = LoadGraph("media\\stageselect\\施設マップ.png");

	nowmode = 0;
}

StageSelect::~StageSelect()
{
	DeleteGraph(gr_back);
	DeleteGraph(gr_one);
	DeleteGraph(gr_two);
	DeleteGraph(gr_three);
}

void StageSelect::Update()
{
	Process();
	Draw();
}

void StageSelect::Process()
{
	if (KeyData::Get(KEY_INPUT_UP) == 1
		|| PadData::Get(XINPUT_BUTTON_DPAD_UP, 0) == 1
		|| PadData::Get(XINPUT_BUTTON_DPAD_UP, 1) == 1
		|| PadData::Get(XINPUT_BUTTON_DPAD_UP, 2) == 1
		|| PadData::Get(XINPUT_BUTTON_DPAD_UP, 3) == 1)
	{
		nowmode--;
		if (nowmode == -1)
		{
			nowmode = 3;
		}
	}
	if (KeyData::Get(KEY_INPUT_DOWN) == 1
		|| PadData::Get(XINPUT_BUTTON_DPAD_DOWN, 0) == 1
		|| PadData::Get(XINPUT_BUTTON_DPAD_DOWN, 1) == 1
		|| PadData::Get(XINPUT_BUTTON_DPAD_DOWN, 2) == 1
		|| PadData::Get(XINPUT_BUTTON_DPAD_DOWN, 3) == 1)
	{
		nowmode++;
		if (nowmode == 4)
		{
			nowmode = 0;
		}
	}

	
	if (KeyData::Get(KEY_INPUT_Z) == 1
		|| PadData::Get(XINPUT_BUTTON_A, 0) == 1
		|| PadData::Get(XINPUT_BUTTON_A, 1) == 1
		|| PadData::Get(XINPUT_BUTTON_A, 2) == 1
		|| PadData::Get(XINPUT_BUTTON_A, 3) == 1)
	{
		Scene::scene = GAME;
	}

	if (KeyData::Get(KEY_INPUT_X) == 1
		|| PadData::Get(XINPUT_BUTTON_B, 0) == 1
		|| PadData::Get(XINPUT_BUTTON_B, 1) == 1
		|| PadData::Get(XINPUT_BUTTON_B, 2) == 1
		|| PadData::Get(XINPUT_BUTTON_B, 3) == 1)
	{
		Scene::scene = TITLE;
	}
}

void StageSelect::Draw()
{
	DrawGraph(0, 0, gr_back, false);
	DrawExtendGraph(1200, (0 - nowmode) * 360, 1200 + 640, (0 - nowmode) * 360 + 480, gr_two, false);
	DrawExtendGraph(1200, (1 - nowmode) * 360, 1200 + 640, (1 - nowmode) * 360 + 480, gr_one, false);
	DrawExtendGraph(1200, (2 - nowmode) * 360, 1200 + 640, (2 - nowmode) * 360 + 480, gr_two, false);
	DrawExtendGraph(1200, (3 - nowmode) * 360, 1200 + 640, (3 - nowmode) * 360 + 480, gr_three, false);
	DrawExtendGraph(1200, (4 - nowmode) * 360, 1200 + 640, (4 - nowmode) * 360 + 480, gr_two, false);
	DrawExtendGraph(1200, (5 - nowmode) * 360, 1200 + 640, (5 - nowmode) * 360 + 480, gr_one, false);
	
	if (nowmode == 0)
	{
		DrawExtendGraph(100, 100, 1000, 1020, gr_one, false);
		DrawFormatString(120, 120, GetColor(0, 0, 0), "\n\n\n\n\n\n\n砂漠ステージ\n\n全体的にバランスがとれたマップ。\n岩の破壊はメリットがないものが多い。");
	}
	else if (nowmode == 1 || nowmode == 3)
	{
		DrawExtendGraph(100, 100, 1000, 1020, gr_two, false);
		DrawFormatString(120, 120, GetColor(0, 0, 0), "\n\n\n\n\n\n\n森林ステージ\n\nほぼ破壊できる道、\n迷路っぽい道、\n広く開放感があるエリアの\n大きく3つの地帯にわかれる。");
	}
	else
	{
		DrawExtendGraph(100, 100, 1000, 1020, gr_three, false);
		DrawFormatString(120, 120, GetColor(0, 0, 0), "\n\n\n\n\n\n\n施設ステージ\n\n左右対称で直線が長いステージ\nになっている。\n故銃弾を使用する武器は有利になる。\n部屋には中心辺りにカプセルが\n設置されてい破壊しない限り\n部屋に添る立ち回りを要求される。\n相手を追い詰めにくい。");
	}
}