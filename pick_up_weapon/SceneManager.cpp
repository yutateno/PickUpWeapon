#include "SceneManager.h"

SceneManager::SceneManager()
{
	// �V�[���Ǘ�
	preScene = TITLE;		// ���O�̃V�[��
	nowScene = TITLE;

	// �ŏ�
	scene = new Title();

	click_se = LoadSoundMem("sound\\����.wav");
	bgm = LoadSoundMem("sound\\�_��̉��.wav");
	PlaySoundMem(bgm, DX_PLAYTYPE_LOOP, TRUE);
}

SceneManager::~SceneManager()
{
	DeleteSoundMem(bgm);
	DeleteSoundMem(click_se);
	// �㏈��
	delete scene;
}

void SceneManager::Update()
{
	// ���O�̃V�[����ۑ�����
	nowScene = Scene::GetScene();
	scene->Update();

	// �V�[�����؂�ւ���Ă���Ώ�������
	if (preScene != nowScene)
	{
		Manager();
		preScene = nowScene;
	}
}

void SceneManager::Manager()
{
	// �����������
	delete scene;

	// ���̃V�[���𐶐�
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