#pragma once
#include "CharacterManager.h"
#include "Scene.h"

class Game : public Scene
{
private:
	CharacterManager* charactermanager;		// �L�����N�^�[�S��

	int bgm;
	int gr_black;

	int endframe;

public:
	Game();			// �R���X�g���N�^
	~Game();		// �f�X�g���N�^

	void Update();	// �V�[���ŌĂ΂��
};