#pragma once
#include "CharacterManager.h"
#include "Scene.h"

class Game : public Scene
{
private:
	CharacterManager* charactermanager;		// キャラクター全員

	int bgm;
	int gr_black;

	int endframe;

public:
	Game();			// コンストラクタ
	~Game();		// デストラクタ

	void Update();	// シーンで呼ばれる
};