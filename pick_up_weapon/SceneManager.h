#pragma once
#include "Scene.h"
#include "Game.h"
#include "Title.h"
#include "StageSelect.h"
#include "Extra.h"

class SceneManager
{
private:
	// シーン関係
	eScene preScene;		// 直前のシーン
	eScene nowScene;

	Scene* scene;			// 全部の親

	void Manager();			// シーンの切り替わりに呼ばれる

	int bgm;
	int click_se;

public:
	SceneManager();			// デフォルト
	~SceneManager();		// デフォルト

	void Update();			// mainに呼ばれる部分
};