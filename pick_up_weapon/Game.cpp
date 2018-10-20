#include "Game.h"

Game::Game()
{
	charactermanager = new CharacterManager(playmode, nowmode);

	bgm = LoadSoundMem("sound\\main.wav");
	gr_black = LoadGraph("media\\gameother\\black.png");
	PlaySoundMem(bgm, DX_PLAYTYPE_LOOP, TRUE);

	endframe = 0;
}

Game::~Game()
{
	DeleteSoundMem(bgm);
	DeleteGraph(gr_black);
	delete charactermanager;
}

void Game::Update()
{
	charactermanager->Update();
	if (charactermanager->GetEnd() == true)
	{
		StopSoundMem(bgm);
	}
	if (charactermanager->GetToTitle() == true)
	{
		endframe++;
		SetDrawBlendMode(DX_BLENDMODE_ALPHA, endframe + 30);
		DrawGraph(0, 0, gr_black, false);
		SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 255);
		if (endframe >= 180)
		{
			Scene::scene = TITLE;
		}
	}
}