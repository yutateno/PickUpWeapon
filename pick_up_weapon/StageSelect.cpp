#include "StageSelect.h"

StageSelect::StageSelect()
{
	gr_back = LoadGraph("media\\stageselect\\stageselect.png");
	gr_one = LoadGraph("media\\stageselect\\�����}�b�v.png");
	gr_two = LoadGraph("media\\stageselect\\�X�у}�b�v.png");
	gr_three = LoadGraph("media\\stageselect\\�{�݃}�b�v.png");

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
		DrawFormatString(120, 120, GetColor(0, 0, 0), "\n\n\n\n\n\n\n�����X�e�[�W\n\n�S�̓I�Ƀo�����X���Ƃꂽ�}�b�v�B\n��̔j��̓����b�g���Ȃ����̂������B");
	}
	else if (nowmode == 1 || nowmode == 3)
	{
		DrawExtendGraph(100, 100, 1000, 1020, gr_two, false);
		DrawFormatString(120, 120, GetColor(0, 0, 0), "\n\n\n\n\n\n\n�X�уX�e�[�W\n\n�قڔj��ł��铹�A\n���H���ۂ����A\n�L���J����������G���A��\n�傫��3�̒n�тɂ킩���B");
	}
	else
	{
		DrawExtendGraph(100, 100, 1000, 1020, gr_three, false);
		DrawFormatString(120, 120, GetColor(0, 0, 0), "\n\n\n\n\n\n\n�{�݃X�e�[�W\n\n���E�Ώ̂Œ����������X�e�[�W\n�ɂȂ��Ă���B\n�̏e�e���g�p���镐��͗L���ɂȂ�B\n�����ɂ͒��S�ӂ�ɃJ�v�Z����\n�ݒu����Ă��j�󂵂Ȃ�����\n�����ɓY�闧������v�������B\n�����ǂ��l�߂ɂ����B");
	}
}