#include "Map.h"

// �R���X�g���N�^
Map::Map(int nowmode)
{
	if (nowmode == 0)
	{
		back = LoadGraph("media\\map\\�����}�b�v.png");
	}
	else if (nowmode == 1 || nowmode == 3)
	{
		back = LoadGraph("media\\stageselect\\�X�у}�b�v.png");
	}
	else
	{
		back = LoadGraph("media\\stageselect\\�{�݃}�b�v.png");
	}
	kabe = LoadGraph("media\\map\\kabe.png");

	mapchipSize = 64;

	this->nowmode = nowmode;

	ReadMap();
}

// �f�X�g���N�^
Map::~Map()
{
	DeleteGraph(kabe);
	DeleteGraph(back);
}

// �`��
void Map::Draw()
{
	DrawGraph(0, 0, back, false);
	// �}�b�v�`�b�v
	for (int i = 0, n = (int)mapdata.size(); i != n; ++i)
	{
		for (int j = 0, m = (int)mapdata[i].size(); j != m; ++j)
		{
			switch ((int)(mapdata[i][j] * 0.1)) {
			case 0:
				break;
			case 1:	//��
				switch (mapdata[i][j] % 10) {
				case 0:
					DrawGraph(j * mapchipSize, i * mapchipSize, kabe, false);	// ���₳��ł悢
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

// �ǂݍ���
void Map::ReadMap()
{
	int type;				// �����擾�p
	int L_Count = 0;		// �ǂݍ��ݗp�i���s�ڂ�ǂݍ���ł��邩		// �����Ő��l�𑝂₷
	string L_Line;			// �ǂݍ��񂾍s�i1�s�j
	ifstream L_File;		// �ǂݍ��ރt�@�C��

	if (nowmode == 0)
	{
		L_File.open("map\\����.txt");		// �t�@�C���I�[�v��
	}
	else if (nowmode == 1 || nowmode == 3)
	{
		L_File.open("map\\�X��.txt");		// �t�@�C���I�[�v��
	}
	else
	{
		L_File.open("map\\�{��.txt");		// �t�@�C���I�[�v��
	}

	if (L_File.fail()) {	// �t�@�C���ǂݍ���
		DxLib_End();
	}
	else {
		// �ǂݍ��ݐ���
		while (getline(L_File, L_Line)) {	// ��s���ǂݍ���

			mapdata.resize(L_Count + 1);
			for (int i = 0, n = (int)L_Line.length(); i != n; i += 2) {
				// ���l�擾
				type = stoi(L_Line.substr(i, 2));	// 2�������擾
													// MapChip�̎��̍쐬
				mapdata[L_Count].push_back(stoi(L_Line.substr(i, 2)));
			}
			L_Count++;	// ���̍s��

		}
	}
	// �t�@�C�������
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