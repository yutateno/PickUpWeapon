#include "Map.h"

// コンストラクタ
Map::Map(int nowmode)
{
	if (nowmode == 0)
	{
		back = LoadGraph("media\\map\\砂漠マップ.png");
	}
	else if (nowmode == 1 || nowmode == 3)
	{
		back = LoadGraph("media\\stageselect\\森林マップ.png");
	}
	else
	{
		back = LoadGraph("media\\stageselect\\施設マップ.png");
	}
	kabe = LoadGraph("media\\map\\kabe.png");

	mapchipSize = 64;

	this->nowmode = nowmode;

	ReadMap();
}

// デストラクタ
Map::~Map()
{
	DeleteGraph(kabe);
	DeleteGraph(back);
}

// 描画
void Map::Draw()
{
	DrawGraph(0, 0, back, false);
	// マップチップ
	for (int i = 0, n = (int)mapdata.size(); i != n; ++i)
	{
		for (int j = 0, m = (int)mapdata[i].size(); j != m; ++j)
		{
			switch ((int)(mapdata[i][j] * 0.1)) {
			case 0:
				break;
			case 1:	//壁
				switch (mapdata[i][j] % 10) {
				case 0:
					DrawGraph(j * mapchipSize, i * mapchipSize, kabe, false);	// 増やさんでよい
					break;
				default:
					break;
				}
				break;
			default:
				break;
			}
		}
	}
}

// 読み込み
void Map::ReadMap()
{
	int type;				// 数字取得用
	int L_Count = 0;		// 読み込み用（何行目を読み込んでいるか		// ここで数値を増やす
	string L_Line;			// 読み込んだ行（1行）
	ifstream L_File;		// 読み込むファイル

	if (nowmode == 0)
	{
		L_File.open("map\\砂漠.txt");		// ファイルオープン
	}
	else if (nowmode == 1 || nowmode == 3)
	{
		L_File.open("map\\森林.txt");		// ファイルオープン
	}
	else
	{
		L_File.open("map\\施設.txt");		// ファイルオープン
	}

	if (L_File.fail()) {	// ファイル読み込み
		DxLib_End();
	}
	else {
		// 読み込み成功
		while (getline(L_File, L_Line)) {	// 一行ずつ読み込み

			mapdata.resize(L_Count + 1);
			for (int i = 0, n = (int)L_Line.length(); i != n; i += 2) {
				// 数値取得
				type = stoi(L_Line.substr(i, 2));	// 2文字ずつ取得
													// MapChipの実体作成
				mapdata[L_Count].push_back(stoi(L_Line.substr(i, 2)));
			}
			L_Count++;	// 次の行に

		}
	}
	// ファイルを閉じる
	L_File.close();
}

int Map::GetMapData(int x, int y)
{
	return mapdata[(int)(y / mapchipSize)][(int)(x / mapchipSize)];
}
int Map::GetMapWidth()
{
	return (int)mapdata[0].size();
}
int Map::GetMapHeight()
{
	return (int)mapdata.size();
}