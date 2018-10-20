#pragma once
#include "DxLib.h"

#include <vector>
#include <fstream>
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

class Map
{
private:
	// �摜
	int back;
	int kabe;						// �}�b�v�`�b�v�̕`��

	int mapchipSize;				// �}�b�v�`�b�v�̃T�C�Y

	int nowmode;

	// �}�b�v�֘A
	vector<vector<int>>mapdata;		// �}�b�v�f�[�^�{��
	void ReadMap();					// �}�b�v�̓ǂݍ���

public:
	Map(int nowmode);							// �R���X�g���N�^
	~Map();							// �f�X�g���N�^

	void Draw();					// �`��

									// �Q�b�^�[�Z�b�^�[
	int GetMapData(int x, int y);	// �}�b�v�S��
	int GetMapWidth();				// �}�b�v�̉���
	int GetMapHeight();				// �}�b�v�̏c��
};