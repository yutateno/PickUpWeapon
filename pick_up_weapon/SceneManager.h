#pragma once
#include "Scene.h"
#include "Game.h"
#include "Title.h"
#include "StageSelect.h"
#include "Extra.h"

class SceneManager
{
private:
	// �V�[���֌W
	eScene preScene;		// ���O�̃V�[��
	eScene nowScene;

	Scene* scene;			// �S���̐e

	void Manager();			// �V�[���̐؂�ւ��ɌĂ΂��

	int bgm;
	int click_se;

public:
	SceneManager();			// �f�t�H���g
	~SceneManager();		// �f�t�H���g

	void Update();			// main�ɌĂ΂�镔��
};