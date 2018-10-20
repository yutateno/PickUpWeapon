#include "SceneManager.h"

SceneManager::SceneManager()
{
	// シーン管理
	preScene = TITLE;		// 直前のシーン
	nowScene = TITLE;

	// 最初
	scene = new Title();

	click_se = LoadSoundMem("sound\\決定.wav");
	bgm = LoadSoundMem("sound\\神域の解放.wav");
	PlaySoundMem(bgm, DX_PLAYTYPE_LOOP, TRUE);
}

SceneManager::~SceneManager()
{
	DeleteSoundMem(bgm);
	DeleteSoundMem(click_se);
	// 後処理
	delete scene;
}

void SceneManager::Update()
{
	// 直前のシーンを保存する
	nowScene = Scene::GetScene();
	scene->Update();

	// シーンが切り替わっていれば処理する
	if (preScene != nowScene)
	{
		Manager();
		preScene = nowScene;
	}
}

void SceneManager::Manager()
{
	// いったん消す
	delete scene;

	// 次のシーンを生成
	switch (Scene::GetScene())
	{
	case TITLE:
		StopSoundMem(bgm);
		PlaySoundMem(bgm, DX_PLAYTYPE_LOOP, TRUE);
		scene = new Title();
		break;

	case EXTRA:
		StopSoundMem(bgm);
		scene = new Extra();
		break;

	case STAGESELECT:
		PlaySoundMem(click_se, DX_PLAYTYPE_BACK, FALSE);
		scene = new StageSelect();
		break;

	case GAME:
		StopSoundMem(bgm);
		PlaySoundMem(click_se, DX_PLAYTYPE_BACK, FALSE);
		scene = new Game();
		break;

	default:
		break;
	}
}