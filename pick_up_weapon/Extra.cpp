#include "Extra.h"

Extra::Extra()
{
	characterDefence = new Character_Knife(200, 500, 500, 1, 0);
	characterAttack = new Character_Sniper(1700, 500, 500, 2, 2);

	gr_back = LoadGraph("media\\map\\施設マップ.png");

	sniper_se = LoadSoundMem("sound\\スナイパー効果音.wav");
	damage_se = LoadSoundMem("sound\\damage.wav");

	// 弾に関すること
	bulletinterval = 8;
	sniperspeed = 30;

	great = false;

	endreturnflag = false;
}

Extra::~Extra()
{
	delete characterDefence;
	delete characterAttack;

	DeleteGraph(gr_back);

	DeleteSoundMem(sniper_se);
	DeleteSoundMem(damage_se);

	bullet.clear();
	bullet.shrink_to_fit();
}

void Extra::Update()
{
	Process();
	Draw();
}

void Extra::Draw()
{
	DrawGraph(0, 0, gr_back, false);

	characterDefence->Draw();
	characterAttack->Draw();
	// 弾
	for (int i = 0, m = (int)bullet.size(); i != m; ++i)
	{
		bullet[i]->Draw();
	}

	if (great == true)
	{
		DrawFormatString(200, 450, GetColor(0, 0, 0), "Great!!!");
	}

	DrawFormatString(50, 50, GetColor(0, 0, 0), "スナイパーの弾をナイフで切ってみる、そんなミニゲーム");
}

void Extra::Process()
{
	characterAttack->Process();
	characterAttack->MoveReset();
	characterDefence->Process();
	characterDefence->MoveReset();

	// 銃の玉
	BulletForm();	// 生成
	BulletColl();	// あたり判定

	if (KeyData::Get(KEY_INPUT_E) == 1
		|| (PadData::Get(XINPUT_BUTTON_START, 0) == 1
		&& PadData::Get(XINPUT_BUTTON_BACK, 1) == 1))
	{
		Scene::scene = TITLE;
	}
}

void Extra::BulletForm()
{
	// Attack--------------------------------------------------------------------------
	if ((KeyData::Get(KEY_INPUT_G) == 1
		|| characterAttack->GetRTbutton() % bulletinterval == 1))
	{
		PlaySoundMem(sniper_se, DX_PLAYTYPE_BACK, TRUE);
		if (characterAttack->GetDire() == 0)
		{
			bullet.push_back(new Bullet(1700 + 64 + 5 - sniperspeed, 500 + 21, 0, sniperspeed, 0));
		}
		else if (characterAttack->GetDire() == 1)
		{
			bullet.push_back(new Bullet(1700 + 21, 500 + 64 + 5 - sniperspeed, 1, sniperspeed, 0));
		}
		else if (characterAttack->GetDire() == 2)
		{
			bullet.push_back(new Bullet(1700 - 5 - 16 + sniperspeed, 500 + 21, 2, sniperspeed, 0));
		}
		else
		{
			bullet.push_back(new Bullet(1700 + 21, 500 - 5 - 16 + sniperspeed, 3, sniperspeed, 0));
		}
	}
}

void Extra::BulletColl()
{
	great = false;
	for (int i = 0, m = (int)bullet.size(); i != m; ++i)
	{
		if (bullet[i]->GetX() > 64
			&& bullet[i]->GetX() < 1920 - 64
			&& bullet[i]->GetY() > 64
			&& bullet[i]->GetY() < 1080 - 64)
		{
			bullet[i]->Move();
		}
		else
		{
			bullet.erase(bullet.begin() + i);
			break;
		}
		// 1P
		if (bullet[i]->GetX() <= characterDefence->GetX() + 64 + 32
			&& bullet[i]->GetX() + 16 >= characterDefence->GetX() + 30
			&& characterDefence->GetRBbutton() == 1)
		{
			great = true;
			bullet.erase(bullet.begin() + i);
			break;
		}
		if (bullet[i]->GetX() < characterDefence->GetX() + 30
			&& bullet[i]->GetX() + 16 > characterDefence->GetX())
		{
			PlaySoundMem(damage_se, DX_PLAYTYPE_BACK, FALSE);
			bullet.erase(bullet.begin() + i);
			break;
		}
	}
}