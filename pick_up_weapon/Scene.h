#pragma once
#include "DxLib.h"
#include "Input.h"

// ��܂��Ȑi�s��Ԃ�\��
enum eScene
{
	TITLE, STAGESELECT, GAME, EXTRA
};

class Scene
{
protected:
	// �Q�[������֌W
	static bool endFlag;

	// �V�[���Ǘ��֌W
	static eScene scene;

	static int playmode;		// �l��
	static int nowmode;			// �}�b�v

public:
	Scene();
	virtual ~Scene() {};

	virtual void Update() = 0;		// Manager�ɌĂ΂�镔��

									// �Q�b�^�[
	static bool GetEndFlag();
	static eScene GetScene();
};