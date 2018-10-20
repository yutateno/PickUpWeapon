#pragma once
#include "DxLib.h"
#include "Input.h"

// 大まかな進行状態を表す
enum eScene
{
	TITLE, STAGESELECT, GAME, EXTRA
};

class Scene
{
protected:
	// ゲーム動作関係
	static bool endFlag;

	// シーン管理関係
	static eScene scene;

	static int playmode;		// 人数
	static int nowmode;			// マップ

public:
	Scene();
	virtual ~Scene() {};

	virtual void Update() = 0;		// Managerに呼ばれる部分

									// ゲッター
	static bool GetEndFlag();
	static eScene GetScene();
};