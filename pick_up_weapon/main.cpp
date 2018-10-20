#include "SceneManager.h"

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
	SetGraphMode(1920, 1080, 32);
	//ChangeWindowMode(TRUE);
	DxLib_Init();
	SetDrawScreen(DX_SCREEN_BACK);
	SceneManager* scenemanager = new SceneManager();
	SetFontSize(50);

	PadData::SetPadNum();

	while (ScreenFlip() == 0 && ProcessMessage() == 0 && ClearDrawScreen() == 0 && KeyData::CheckEnd() == 1 && PadData::CheckEnd() == 1 && Scene::GetEndFlag() == 0)
	{
		KeyData::UpDate();
		PadData::UpDate();
		scenemanager->Update();
	}

	delete scenemanager;

	InitGraph();
	InitSoundMem();

	DxLib_End();
	return 0;
}