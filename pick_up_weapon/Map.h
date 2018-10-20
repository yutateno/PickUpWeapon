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
	// 画像
	int back;
	int kabe;						// マップチップの描画

	int mapchipSize;				// マップチップのサイズ

	int nowmode;

	// マップ関連
	vector<vector<int>>mapdata;		// マップデータ本体
	void ReadMap();					// マップの読み込み

public:
	Map(int nowmode);							// コンストラクタ
	~Map();							// デストラクタ

	void Draw();					// 描画

									// ゲッターセッター
	int GetMapData(int x, int y);	// マップ全体
	int GetMapWidth();				// マップの横幅
	int GetMapHeight();				// マップの縦幅
};