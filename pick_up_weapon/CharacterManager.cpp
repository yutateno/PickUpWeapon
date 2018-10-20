#include "CharacterManager.h"

CharacterManager::CharacterManager(int playmode, int nowmode)
{
	// 画像
	gr_hp_cover = LoadGraph("media\\gameother\\体力バー周り.png");
	gr_start_black = LoadGraph("media\\gameother\\black.png");
	gr_startcount[0] = LoadGraph("media\\gameother\\1.png");
	gr_startcount[1] = LoadGraph("media\\gameother\\2.png");
	gr_startcount[2] = LoadGraph("media\\gameother\\3.png");
	gr_startcount[3] = LoadGraph("media\\gameother\\4.png");
	gr_startcount[4] = LoadGraph("media\\gameother\\5.png");
	gr_startcount[5] = LoadGraph("media\\gameother\\start.png");
	gr_draw = LoadGraph("media\\end\\draw.png");

	character[0].gr_hpbar = LoadGraph("media\\player\\1P\\hp1.png");
	character[1].gr_hpbar = LoadGraph("media\\player\\2P\\hp2.png");
	if (playmode >= 1)
	{
		character[2].gr_hpbar = LoadGraph("media\\player\\3P\\hp3.png");
	}
	if (playmode == 2)
	{
		character[3].gr_hpbar = LoadGraph("media\\player\\4P\\hp4.png");
	}

	character[0].gr_win = LoadGraph("media\\end\\1P\\リザルト1.png");
	character[1].gr_win = LoadGraph("media\\end\\2P\\リザルト1.png");
	if (playmode >= 1)
	{
		character[2].gr_win = LoadGraph("media\\end\\3P\\リザルト1.png");
	}
	if (playmode == 2)
	{
		character[3].gr_win = LoadGraph("media\\end\\4P\\リザルト1.png");
	}

	LoadDivGraph("media\\player\\1P\\lose\\負けましたー.png", 28, 10, 3, 64, 64, character[0].gr_lose);
	LoadDivGraph("media\\player\\2P\\lose\\負けましたー.png", 28, 10, 3, 64, 64, character[1].gr_lose);
	if (playmode >= 1)
	{
		LoadDivGraph("media\\player\\3P\\lose\\負けましたー.png", 28, 10, 3, 64, 64, character[2].gr_lose);
	}
	if (playmode == 2)
	{
		LoadDivGraph("media\\player\\4P\\lose\\負けましたー.png", 28, 10, 3, 64, 64, character[3].gr_lose);
	}

	// 音楽
	win_bgm = LoadSoundMem("sound\\fun.wav");
	gatling_se = LoadSoundMem("sound\\ガトリング.wav");
	sniper_se = LoadSoundMem("sound\\スナイパー効果音.wav");
	damage_se = LoadSoundMem("sound\\damage.wav");
	gunseat_se = LoadSoundMem("sound\\たれっと 銃声.wav");
	gunseatend_se = LoadSoundMem("sound\\たれっと.wav");
	doll_se = LoadSoundMem("sound\\呪い人形.wav");
	knife_se = LoadSoundMem("sound\\近接系武器.wav");
	shield_se = LoadSoundMem("sound\\盾attack.wav");

	starttime = 300;
	startblendframe = 0;
	end_bgm_flag = false;

	timer = 3600 * 4;
	timeframe = 0;

	this->playmode = playmode;

	if (playmode == 0)
	{
		playernum = 2;
	}
	else if (playmode == 1)
	{
		playernum = 3;
	}
	else
	{
		playernum = 4;
	}

	// 1P
	character[0].dropID = 12;
	character[0].x = 64;
	character[0].y = 64;
	character[0].hp = 50 * 4;
	character[0].prehp = character[0].hp;
	character[0].direction = 0;
	character[0].chara = 12;
	character[0].loseframe = 10;
	character[0].losecount = 0;

	// 2P
	character[1].dropID = 12;
	character[1].x = 1920 -128;
	character[1].y = 64;
	character[1].hp = 50 * 4;
	character[1].prehp = character[1].hp;
	character[1].direction = 2;
	character[1].chara = 12;
	character[1].loseframe = 10;
	character[1].losecount = 0;

	// 3P
	character[2].dropID = 12;
	character[2].x = 64;
	character[2].y = 1080 - 128;
	character[2].hp = 50 * 4;
	character[2].prehp = character[2].hp;
	character[2].direction = 0;
	character[2].chara = 12;
	character[2].loseframe = 10;
	character[2].losecount = 0;

	// 4P
	character[3].dropID = 12;
	character[3].x = 1920 - 128;
	character[3].y = 1080 - 128;
	character[3].hp = 50 * 4;
	character[3].prehp = character[3].hp;
	character[3].direction = 2;
	character[3].chara = 12;
	character[3].loseframe = 10;
	character[3].losecount = 0;

	// 落ちている武器の個数
	dropnum = 0;

	// 弾に関すること
	bulletinterval = 8;
	gatlingspeed = 60;
	sniperspeed = 80;
	gunseatspeed = 50;

	for (int i = 0; i != 4; ++i)
	{
		// 弾
		character[i].gunspeed = 5;
		// 切る系
		character[i].knifeframe = 0;
		// 毒ガス
		character[i].venomflag = false;
		character[i].venomframe = 0;
		// 爆弾
		character[i].bombhit = false;
		// 炎
		character[i].flamemovehit = false;
		// トラバサミ
		character[i].traversalcatch = false;
		// キャラクターたちの生成
		character[i].character = new Character_Normal(character[i].x, character[i].y, character[i].hp, i + 1, character[i].direction);
	}


	// 終了フラッグ
	endtotitle = false;
	endflag = false;
	endframe = 0;

	// 落ちている武器に関して
	for (int i = 0; i != 13; ++i)
	{
		drop[i].dropflag = false;
	}
	count = 0;
	effectcount = 0;

	// マップの表示(こやつに引数取らせて背景を変えるように
	map = new Map(nowmode);

	// 落ちている武器の初期生成
	DropWeaponInit();

	// ガラス等の初期生成
	ObstacleInit();
}

CharacterManager::~CharacterManager()
{
	DeleteGraph(gr_hp_cover);
	for (int i = 0; i != playernum; ++i)
	{
		DeleteGraph(character[i].gr_hpbar);
		DeleteGraph(character[i].gr_win);
	}
	
	DeleteGraph(gr_start_black);
	DeleteGraph(gr_draw);
	for (int i = 0; i != 6; ++i)
	{
		DeleteGraph(gr_startcount[i]);
	}

	DeleteSoundMem(win_bgm);
	DeleteSoundMem(gatling_se);
	DeleteSoundMem(sniper_se);
	DeleteSoundMem(damage_se);
	DeleteSoundMem(gunseat_se);
	DeleteSoundMem(gunseatend_se);
	DeleteSoundMem(doll_se);
	DeleteSoundMem(knife_se);
	DeleteSoundMem(shield_se);

	delete map;
	for (int i = 0; i != 4; ++i)
	{
		delete character[i].character;
	}

	for (int i = 0; i != 13; ++i)
	{
		if (drop[i].dropflag == true)
		{
			delete drop[i].drop;
		}
	}

	bullet.clear();
	bullet.shrink_to_fit();

	obstacle.clear();
	obstacle.shrink_to_fit();

	doll.clear();
	doll.shrink_to_fit();

	gunseat.clear();
	gunseat.shrink_to_fit();

	venom.clear();
	venom.shrink_to_fit();

	bomb.clear();
	bomb.shrink_to_fit();

	traversal.clear();
	traversal.shrink_to_fit();
}

void CharacterManager::Update()
{
	if (playmode == 0)
	{
		TwoUpdate();
	}
	else if (playmode == 1)
	{
		ThreeUpdate();
	}
	else if (playmode == 2)
	{
		FourUpdate();
	}

	if (startblendframe < 255)
	{
		starttime--;
		if (starttime <= 0)
		{
			startblendframe = 255;
			DrawGraph(0, 0, gr_startcount[5] , true);
		}
		else if (starttime >= 5 && starttime < 60)
		{
			startblendframe = 204;
			DrawGraph(0, 0, gr_startcount[0], true);
		}
		else if (starttime >= 60 && starttime < 120)
		{
			startblendframe = 153;
			DrawGraph(0, 0, gr_startcount[1], true);
		}
		else if (starttime >= 120 && starttime < 180)
		{
			startblendframe = 102;
			DrawGraph(0, 0, gr_startcount[2], true);
		}
		else if (starttime >= 180 && starttime < 240)
		{
			startblendframe = 51;
			DrawGraph(0, 0, gr_startcount[3], true);
		}
		else if (starttime >= 240 && starttime < 300)
		{
			startblendframe = 40;
			DrawGraph(0, 0, gr_startcount[4], true);
		}
	}
}

void CharacterManager::TwoUpdate()
{
	// 一人も死んでいなかったら(二人用なのでこうなっている)
	if (character[0].hp > 0 && character[1].hp > 0)
	{
		Draw();
		if (startblendframe >= 255)
		{
			Process();
		}
		else
		{
			SetDrawBlendMode(DX_BLENDMODE_ALPHA, 255 - startblendframe);
			DrawGraph(0, 0, gr_start_black, false);
			SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 255);
		}
		//PlaySoundMem(game_bgm, DX_PLAYTYPE_LOOP, FALSE);
	}
	else if (character[0].hp <= 0 && character[1].hp <= 0)		// 引き分け
	{
		endflag = true;
		CharacterProcess();
		if (endframe < 120)
		{
			endframe++;
		}
		//StopSoundMem(game_bgm);
		if (end_bgm_flag == false)
		{
			PlaySoundMem(win_bgm, DX_PLAYTYPE_BACK, FALSE);
		}
		end_bgm_flag = true;
		SetDrawBlendMode(DX_BLENDMODE_ALPHA, 255 - endframe);
		Draw();
		SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 255);
		SetDrawBlendMode(DX_BLENDMODE_ALPHA, endframe * 2);
		DrawGraph(0, 0, gr_draw, true);
		SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 255);
		if (KeyData::Get(KEY_INPUT_Z) == 1
			|| character[0].character->GetAbutton() == 1
			|| character[1].character->GetAbutton() == 1)
		{
			StopSoundMem(win_bgm);
			endtotitle = true;
		}
	}
	else if (character[1].hp <= 0)		// 1P勝利
	{
		endflag = true;
		CharacterProcess();
		if (endframe < 120 && endflag == true)
		{
			endframe++;
		}
		//StopSoundMem(game_bgm);
		if (end_bgm_flag == false)
		{
			PlaySoundMem(win_bgm, DX_PLAYTYPE_BACK, FALSE);
		}
		end_bgm_flag = true;
		SetDrawBlendMode(DX_BLENDMODE_ALPHA, 255 - endframe);
		Draw();
		SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 255);
		SetDrawBlendMode(DX_BLENDMODE_ALPHA, endframe * 2);
		DrawGraph(0, 0, character[0].gr_win, true);
		SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 255);
		if (KeyData::Get(KEY_INPUT_Z) == 1
			|| character[0].character->GetAbutton() == 1
			|| character[1].character->GetAbutton() == 1)
		{
			StopSoundMem(win_bgm);
			endtotitle = true;
		}
	}
	else if (character[0].hp <= 0)				// 2P勝利
	{
		endflag = true;
		CharacterProcess();
		if (endframe < 120)
		{
			endframe++;
		}
		//StopSoundMem(game_bgm);
		if (end_bgm_flag == false)
		{
			PlaySoundMem(win_bgm, DX_PLAYTYPE_BACK, FALSE);
		}
		end_bgm_flag = true;
		SetDrawBlendMode(DX_BLENDMODE_ALPHA, 255 - endframe);
		Draw();
		SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 255);
		SetDrawBlendMode(DX_BLENDMODE_ALPHA, endframe * 2);
		DrawGraph(0, 0, character[1].gr_win, true);
		SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 255);
		if (KeyData::Get(KEY_INPUT_Z) == 1
			|| character[0].character->GetAbutton() == 1
			|| character[1].character->GetAbutton() == 1)
		{
			StopSoundMem(win_bgm);
			endtotitle = true;
		}
	}
}

void CharacterManager::ThreeUpdate()
{
	// 一人でも生きていたら
	if ((character[0].hp > 0 && character[1].hp > 0 && character[2].hp > 0)
		|| (character[0].hp > 0 && character[1].hp > 0 && character[2].hp <= 0)
		|| (character[0].hp > 0 && character[1].hp <= 0 && character[2].hp > 0)
		|| (character[0].hp <= 0 && character[1].hp > 0 && character[2].hp > 0))
	{
		Draw();
		if (startblendframe >= 255)
		{
			Process();
		}
		else
		{
			SetDrawBlendMode(DX_BLENDMODE_ALPHA, 255 - startblendframe);
			DrawGraph(0, 0, gr_start_black, false);
			SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 255);
		}
	}
	else if (character[0].hp <= 0 && character[1].hp <= 0 && character[2].hp <= 0)				// 引き分け
	{
		endflag = true;
		CharacterProcess();
		if (endframe < 120)
		{
			endframe++;
		}
		if (end_bgm_flag == false)
		{
			PlaySoundMem(win_bgm, DX_PLAYTYPE_BACK, FALSE);
		}
		end_bgm_flag = true;
		SetDrawBlendMode(DX_BLENDMODE_ALPHA, 255 - endframe);
		Draw();
		SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 255);
		SetDrawBlendMode(DX_BLENDMODE_ALPHA, endframe * 2);
		DrawGraph(0, 0, gr_draw, true);
		SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 255);
		if (KeyData::Get(KEY_INPUT_Z) == 1
			|| character[0].character->GetAbutton() == 1
			|| character[1].character->GetAbutton() == 1
			|| character[2].character->GetAbutton() == 1)
		{
			StopSoundMem(win_bgm);
			endtotitle = true;
		}
	}
	else if (character[1].hp <= 0 && character[2].hp <= 0)		// 1P勝利
	{
		endflag = true;
		CharacterProcess();
		if (endframe < 120 && endflag == true)
		{
			endframe++;
		}
		if (end_bgm_flag == false)
		{
			PlaySoundMem(win_bgm, DX_PLAYTYPE_BACK, FALSE);
		}
		end_bgm_flag = true;
		SetDrawBlendMode(DX_BLENDMODE_ALPHA, 255 - endframe);
		Draw();
		SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 255);
		SetDrawBlendMode(DX_BLENDMODE_ALPHA, endframe * 2);
		DrawGraph(0, 0, character[0].gr_win, true);
		SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 255);
		if (KeyData::Get(KEY_INPUT_Z) == 1
			|| character[0].character->GetAbutton() == 1
			|| character[1].character->GetAbutton() == 1
			|| character[2].character->GetAbutton() == 1)
		{
			StopSoundMem(win_bgm);
			endtotitle = true;
		}
	}
	else if (character[0].hp <= 0 && character[2].hp <= 0)				// 2P勝利
	{
		endflag = true;
		CharacterProcess();
		if (endframe < 120)
		{
			endframe++;
		}
		if (end_bgm_flag == false)
		{
			PlaySoundMem(win_bgm, DX_PLAYTYPE_BACK, FALSE);
		}
		end_bgm_flag = true;
		SetDrawBlendMode(DX_BLENDMODE_ALPHA, 255 - endframe);
		Draw();
		SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 255);
		SetDrawBlendMode(DX_BLENDMODE_ALPHA, endframe * 2);
		DrawGraph(0, 0, character[1].gr_win, true);
		SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 255);
		if (KeyData::Get(KEY_INPUT_Z) == 1
			|| character[0].character->GetAbutton() == 1
			|| character[1].character->GetAbutton() == 1
			|| character[2].character->GetAbutton() == 1)
		{
			StopSoundMem(win_bgm);
			endtotitle = true;
		}
	}
	else if (character[0].hp <= 0 && character[1].hp <= 0)				// 3P勝利
	{
		endflag = true;
		CharacterProcess();
		if (endframe < 120)
		{
			endframe++;
		}
		if (end_bgm_flag == false)
		{
			PlaySoundMem(win_bgm, DX_PLAYTYPE_BACK, FALSE);
		}
		end_bgm_flag = true;
		SetDrawBlendMode(DX_BLENDMODE_ALPHA, 255 - endframe);
		Draw();
		SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 255);
		SetDrawBlendMode(DX_BLENDMODE_ALPHA, endframe * 2);
		DrawGraph(0, 0, character[2].gr_win, true);
		SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 255);
		if (KeyData::Get(KEY_INPUT_Z) == 1
			|| character[0].character->GetAbutton() == 1
			|| character[1].character->GetAbutton() == 1
			|| character[2].character->GetAbutton() == 1)
		{
			StopSoundMem(win_bgm);
			endtotitle = true;
		}
	}
}

void CharacterManager::FourUpdate()
{
	// 一人でも生きていたら
	if ((character[0].hp > 0 && character[1].hp > 0 && character[2].hp > 0 && character[3].hp > 0)
		|| (character[0].hp > 0 && character[1].hp > 0 && character[2].hp > 0 && character[3].hp <= 0)
		|| (character[0].hp > 0 && character[1].hp > 0 && character[2].hp <= 0 && character[3].hp <= 0)
		|| (character[0].hp > 0 && character[1].hp > 0 && character[2].hp <= 0 && character[3].hp > 0)
		|| (character[0].hp > 0 && character[1].hp <= 0 && character[2].hp > 0 && character[3].hp > 0)
		|| (character[0].hp > 0 && character[1].hp <= 0 && character[2].hp <= 0 && character[3].hp > 0)
		|| (character[0].hp > 0 && character[1].hp <= 0 && character[2].hp > 0 && character[3].hp <= 0)
		|| (character[0].hp <= 0 && character[1].hp > 0 && character[2].hp > 0 && character[3].hp > 0)
		|| (character[0].hp <= 0 && character[1].hp <= 0 && character[2].hp > 0 && character[3].hp > 0)
		|| (character[0].hp <= 0 && character[1].hp > 0 && character[2].hp <= 0 && character[3].hp > 0)
		|| (character[0].hp <= 0 && character[1].hp > 0 && character[2].hp > 0 && character[3].hp <= 0))
	{
		Draw();
		if (startblendframe >= 255)
		{
			Process();
		}
		else
		{
			SetDrawBlendMode(DX_BLENDMODE_ALPHA, 255 - startblendframe);
			DrawGraph(0, 0, gr_start_black, false);
			SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 255);
		}
	}
	else if (character[0].hp <= 0 && character[1].hp <= 0 && character[2].hp <= 0 && character[3].hp <= 0)				// 引き分け
	{
		endflag = true;
		CharacterProcess();
		if (endframe < 120)
		{
			endframe++;
		}
		if (end_bgm_flag == false)
		{
			PlaySoundMem(win_bgm, DX_PLAYTYPE_BACK, FALSE);
		}
		end_bgm_flag = true;
		SetDrawBlendMode(DX_BLENDMODE_ALPHA, 255 - endframe);
		Draw();
		SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 255);
		SetDrawBlendMode(DX_BLENDMODE_ALPHA, endframe * 2);
		DrawGraph(0, 0, gr_draw, true);
		SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 255);
		if (KeyData::Get(KEY_INPUT_Z) == 1
			|| character[0].character->GetAbutton() == 1
			|| character[1].character->GetAbutton() == 1
			|| character[2].character->GetAbutton() == 1
			|| character[3].character->GetAbutton() == 1)
		{
			StopSoundMem(win_bgm);
			endtotitle = true;
		}
	}
	else if (character[1].hp <= 0 && character[2].hp <= 0 && character[3].hp <= 0)		// 1P勝利
	{
		endflag = true;
		CharacterProcess();
		if (endframe < 120 && endflag == true)
		{
			endframe++;
		}
		if (end_bgm_flag == false)
		{
			PlaySoundMem(win_bgm, DX_PLAYTYPE_BACK, FALSE);
		}
		end_bgm_flag = true;
		SetDrawBlendMode(DX_BLENDMODE_ALPHA, 255 - endframe);
		Draw();
		SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 255);
		SetDrawBlendMode(DX_BLENDMODE_ALPHA, endframe * 2);
		DrawGraph(0, 0, character[0].gr_win, true);
		SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 255);
		if (KeyData::Get(KEY_INPUT_Z) == 1
			|| character[0].character->GetAbutton() == 1
			|| character[1].character->GetAbutton() == 1
			|| character[2].character->GetAbutton() == 1
			|| character[3].character->GetAbutton() == 1)
		{
			StopSoundMem(win_bgm);
			endtotitle = true;
		}
	}
	else if (character[0].hp <= 0 && character[2].hp <= 0 && character[3].hp <= 0)				// 2P勝利
	{
		endflag = true;
		CharacterProcess();
		if (endframe < 120)
		{
			endframe++;
		}
		if (end_bgm_flag == false)
		{
			PlaySoundMem(win_bgm, DX_PLAYTYPE_BACK, FALSE);
		}
		end_bgm_flag = true;
		SetDrawBlendMode(DX_BLENDMODE_ALPHA, 255 - endframe);
		Draw();
		SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 255);
		SetDrawBlendMode(DX_BLENDMODE_ALPHA, endframe * 2);
		DrawGraph(0, 0, character[1].gr_win, true);
		SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 255);
		if (KeyData::Get(KEY_INPUT_Z) == 1
			|| character[0].character->GetAbutton() == 1
			|| character[1].character->GetAbutton() == 1
			|| character[2].character->GetAbutton() == 1
			|| character[3].character->GetAbutton() == 1)
		{
			StopSoundMem(win_bgm);
			endtotitle = true;
		}
	}
	else if (character[0].hp <= 0 && character[1].hp <= 0 && character[3].hp <= 0)				// 3P勝利
	{
		endflag = true;
		CharacterProcess();
		if (endframe < 120)
		{
			endframe++;
		}
		if (end_bgm_flag == false)
		{
			PlaySoundMem(win_bgm, DX_PLAYTYPE_BACK, FALSE);
		}
		end_bgm_flag = true;
		SetDrawBlendMode(DX_BLENDMODE_ALPHA, 255 - endframe);
		Draw();
		SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 255);
		SetDrawBlendMode(DX_BLENDMODE_ALPHA, endframe * 2);
		DrawGraph(0, 0, character[2].gr_win, true);
		SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 255);
		if (KeyData::Get(KEY_INPUT_Z) == 1
			|| character[0].character->GetAbutton() == 1
			|| character[1].character->GetAbutton() == 1
			|| character[2].character->GetAbutton() == 1
			|| character[3].character->GetAbutton() == 1)
		{
			StopSoundMem(win_bgm);
			endtotitle = true;
		}
	}
	else if (character[0].hp <= 0 && character[1].hp <= 0 && character[2].hp <= 0)				// 4P勝利
	{
		endflag = true;
		CharacterProcess();
		if (endframe < 120)
		{
			endframe++;
		}
		if (end_bgm_flag == false)
		{
			PlaySoundMem(win_bgm, DX_PLAYTYPE_BACK, FALSE);
		}
		end_bgm_flag = true;
		SetDrawBlendMode(DX_BLENDMODE_ALPHA, 255 - endframe);
		Draw();
		SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 255);
		SetDrawBlendMode(DX_BLENDMODE_ALPHA, endframe * 2);
		DrawGraph(0, 0, character[3].gr_win, true);
		SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 255);
		if (KeyData::Get(KEY_INPUT_Z) == 1
			|| character[0].character->GetAbutton() == 1
			|| character[1].character->GetAbutton() == 1
			|| character[2].character->GetAbutton() == 1
			|| character[3].character->GetAbutton() == 1)
		{
			StopSoundMem(win_bgm);
			endtotitle = true;
		}
	}
}

void CharacterManager::Process()
{
	CharacterProcess();
	
	// 落ちてる武器の再生成
	if (dropnum <= 3)
	{
		count++;
		if (count == 300)
		{
			DropWeapon();
			count = 0;
		}
	}

	// 落ちてる武器のエフェクト
	effectcount++;
	if (effectcount >= 255)
	{
		effectcount = 0;
	}

	// 銃の玉
	BulletForm();	// 生成
	BulletColl();	// あたり判定

	// ナイフに関して
	KnifeProcess();

	// 剣に関して
	SwordProcess();

	// 炎に関して
	FlameProcess();

	// 爆弾に関して
	BombProcess();

	// 毒瓶に関して
	VenomProcess();

	// 銃座に関して
	GunSeatProcess();

	// 人形
	DollProcess();

	// トラバサミ
	TraversalProcess();

	// 盾
	ShieldProcess();

	timer--;

	for (int i = 0; i != playernum; ++i)
	{
		if (timer <= 0)
		{
			timeframe++;
			if (timeframe % 10 == 0)
			{
				character[i].hp--;
			}
		}
	}
}

void CharacterManager::Draw()
{
	// マップ
	map->Draw();

	// 炎
	for (int i = 0, m = (int)flame.size(); i != m; ++i)
	{
		flame[i]->Draw();
	}

	// トラバサミ
	for (int i = 0, m = (int)traversal.size(); i != m; ++i)
	{
		traversal[i]->Draw();
	}

	// 落ちもの
	if (startblendframe >= 255)
	{
		for (int i = 0, m = 13; i != m; ++i)
		{
			if (drop[i].dropflag == true)
			{
				SetDrawBright(255, 255, effectcount);
				drop[i].drop->Draw();
				SetDrawBright(255, 255, 255);
			}
		}
	}

	// 障害物
	for (int i = 0, m = (int)obstacle.size(); i != m; ++i)
	{
		if (obstacle[i]->GetBrokenFlag() == false && obstacle[i]->GetBreakFlag() == false)
		{
			obstacle[i]->Draw_Normal();
		}
		else if (obstacle[i]->GetBrokenFlag() == false && obstacle[i]->GetBreakFlag() == true)
		{
			obstacle[i]->Draw_Break();
		}
		else if (obstacle[i]->GetBrokenFlag() == true)
		{
			obstacle[i]->Draw_Broken();
		}
	}

	// 毒ガス
	for (int i = 0, m = (int)venom.size(); i != m; ++i)
	{
		venom[i]->Draw();
	}

	// 爆弾
	for (int i = 0, m = (int)bomb.size(); i != m; ++i)
	{
		bomb[i]->Draw();
	}

	// 弾
	for (int i = 0, m = (int)bullet.size(); i != m; ++i)
	{
		bullet[i]->Draw();
	}

	// P
	for (int i = 0; i != playernum; ++i)
	{
		if (character[i].hp > 0)
		{
			if (character[i].hp != character[i].prehp)
			{
				SetDrawBright(255, 0, 0);
				character[i].character->Draw();
				SetDrawBright(255, 255, 255);
				character[i].prehp = character[i].hp;
			}
			else
			{
				character[i].character->Draw();
			}
		}
		else
		{
			DrawGraph(character[i].x, character[i].y, character[i].gr_lose[(character[i].losecount / character[i].loseframe) % 28], true);
			if (character[i].losecount < (character[i].loseframe * 28) - 1)
			{
				++character[i].losecount;
			}
			else
			{
				character[i].losecount = 160;
			}
		}
	}

	// 1P
	DrawGraph(175, 25, gr_hp_cover, true);
	DrawFormatString(395, 20, GetColor(255, 0, 0), "1P");
	if (character[0].hp > 0)
	{
		DrawExtendGraph(185, 30, 185 + character[0].hp, 55, character[0].gr_hpbar, false);
	}
	if (character[0].chara == 3 || character[0].chara == 6 || character[0].chara == 9)
	{
		DrawFormatString(0, 20, GetColor(125, 125, 125), "残弾%d", character[0].character->tamanum);
	}

	// 2P
	DrawGraph(1515, 25, gr_hp_cover, true);
	DrawFormatString(1465, 20, GetColor(50, 50, 255), "2P");
	if (character[1].hp > 0)
	{
		DrawExtendGraph(1525, 30, 1525 + character[1].hp, 55, character[1].gr_hpbar, false);
	}
	if (character[1].chara == 3 || character[1].chara == 6 || character[1].chara == 9)
	{
		DrawFormatString(1730, 20, GetColor(125, 125, 125), "残弾%d", character[1].character->tamanum);
	}

	// 3P
	if (playmode >= 1)
	{
		DrawGraph(175, 1080 - 55, gr_hp_cover, true);
		DrawFormatString(395, 1080 - 55, GetColor(0, 255, 0), "3P");
		if (character[2].hp > 0)
		{
			DrawExtendGraph(185, 1080 - 50, 185 + character[2].hp, 1080 - 25, character[2].gr_hpbar, false);
		}
		if (character[2].chara == 3 || character[2].chara == 6 || character[2].chara == 9)
		{
			DrawFormatString(0, 1080 - 50, GetColor(125, 125, 125), "残弾%d", character[2].character->tamanum);
		}
	}

	// 4P
	if (playmode == 2)
	{
		DrawGraph(1515, 1080 - 55, gr_hp_cover, true);
		DrawFormatString(1465, 1080 - 55, GetColor(255, 0, 255), "4P");
		if (character[3].hp > 0)
		{
			DrawExtendGraph(1525, 1080 - 50, 1525 + character[3].hp, 1080 - 25, character[3].gr_hpbar, false);
		}
		if (character[3].chara == 3 || character[3].chara == 6 || character[3].chara == 9)
		{
			DrawFormatString(1730, 1080 - 50, GetColor(125, 125, 125), "残弾%d", character[3].character->tamanum);
		}
	}

	// 人形
	for (int i = 0, m = (int)doll.size(); i != m; ++i)
	{
		doll[i]->Draw();
	}

	// 銃座
	for (int i = 0, m = (int)gunseat.size(); i != m; ++i)
	{
		gunseat[i]->Draw();
	}

	if (timer >= 0)
	{
		DrawFormatString(650, 0, GetColor(255, 0, 0), "非情ダメージまで残り：%d分%d秒", (timer / 3600), (timer % 3600) / 60);
	}
	else
	{
		DrawFormatString(650, 0, GetColor(255, 0, 0), "非情ダメージ開始");
	}
}

// 一人
void CharacterManager::Change(CharacterS character[], int nP)
{
	// 消す
	delete character[nP - 1].character;
	switch (character[nP - 1].dropID)
	{
	case 0:
		character[nP - 1].character = new Character_Knife(character[nP - 1].x, character[nP - 1].y, character[nP - 1].hp, nP, character[nP - 1].direction);
		character[nP - 1].chara = 0;
		break;
	case 1:
		character[nP - 1].character = new Character_Sword(character[nP - 1].x, character[nP - 1].y, character[nP - 1].hp, nP, character[nP - 1].direction);
		character[nP - 1].chara = 1;
		break;
	case 2:
		character[nP - 1].character = new Character_Traversal(character[nP - 1].x, character[nP - 1].y, character[nP - 1].hp, nP, character[nP - 1].direction);
		character[nP - 1].chara = 2;
		break;
	case 3:
		character[nP - 1].character = new Character_Flame(character[nP - 1].x, character[nP - 1].y, character[nP - 1].hp, nP, character[nP - 1].direction);
		character[nP - 1].chara = 3;
		break;
	case 4:
		character[nP - 1].character = new Character_Venom(character[nP - 1].x, character[nP - 1].y, character[nP - 1].hp, nP, character[nP - 1].direction);
		character[nP - 1].chara = 4;
		break;
	case 5:
		character[nP - 1].character = new Character_Shield(character[nP - 1].x, character[nP - 1].y, character[nP - 1].hp, nP, character[nP - 1].direction);
		character[nP - 1].chara = 5;
		character[nP - 1].hp_shield = 30 * 4;
		break;
	case 6:
		character[nP - 1].character = new Character_Sniper(character[nP - 1].x, character[nP - 1].y, character[nP - 1].hp, nP, character[nP - 1].direction);
		character[nP - 1].chara = 6;
		break;
	case 7:
		character[nP - 1].character = new Character_Knife(character[nP - 1].x, character[nP - 1].y, character[nP - 1].hp, nP, character[nP - 1].direction);
		character[nP - 1].chara = 0;
		break;
	case 8:
		character[nP - 1].character = new Character_GunSeat(character[nP - 1].x, character[nP - 1].y, character[nP - 1].hp, nP, character[nP - 1].direction);
		character[nP - 1].chara = 8;
		break;
	case 9:
		character[nP - 1].character = new Character_Gatling(character[nP - 1].x, character[nP - 1].y, character[nP - 1].hp, nP, character[nP - 1].direction);
		character[nP - 1].chara = 9;
		break;
	case 10:
		character[nP - 1].character = new Character_Doll(character[nP - 1].x, character[nP - 1].y, character[nP - 1].hp, nP, character[nP - 1].direction);
		character[nP - 1].chara = 10;
		break;
	case 11:
		character[nP - 1].character = new Character_Bomb(character[nP - 1].x, character[nP - 1].y, character[nP - 1].hp, nP, character[nP - 1].direction);
		character[nP - 1].chara = 11;
		break;
	default:
		character[nP - 1].character = new Character_Normal(character[nP - 1].x, character[nP - 1].y, character[nP - 1].hp, nP, character[nP - 1].direction);
		character[nP - 1].chara = 12;
		break;
	}
}

// キャラクター
void CharacterManager::CharacterProcess()
{
	for (int k = 0; k != playernum; ++k)
	{
		if (character[k].hp <= 0)
		{
			character[k].dropID = 12;
			Change(character, k + 1);
		}
		if (character[k].hp > 0)
		{
			// 落ちている武器を拾う
			if (KeyData::Get(KEY_INPUT_V) == 1
				|| character[k].character->GetAbutton() == 1)
			{

				for (int i = 0, m = 13; i != m; ++i)
				{
					if (drop[i].drop->GetX() < character[k].character->GetX() + 32
						&& drop[i].drop->GetX() + 64 > character[k].character->GetX() + 32
						&& drop[i].drop->GetY() < character[k].character->GetY() + 32
						&& drop[i].drop->GetY() + 64 > character[k].character->GetY() + 32
						&& drop[i].dropflag == true)
					{
						drop[i].dropflag = false;
						character[k].dropID = drop[i].drop->GetID();
						dropnum--;
						delete drop[i].drop;
						Change(character, k + 1);
					}
				}
			}
			// 武器を捨てる
			if (character[k].character->GetLBbutton() == 1)
			{
				character[k].dropID = 12;
				Change(character, k + 1);
			}
		}

		character[k].x = character[k].character->GetX();
		character[k].y = character[k].character->GetY();
		character[k].character->Process();
		character[k].direction = character[k].character->GetDire();
		// 位置修正
		for (int i = 0; i != 2; ++i)
		{
			for (int j = 0; j != 2; ++j)
			{
				switch (map->GetMapData(character[k].character->GetX() + (i * (64 - 14)), character[k].character->GetY() + (j * (64 - 14))))
				{
				case 10:	// 壁
					character[k].character->MoveReset();
					break;
					//case 11:	// 壁
					//	character[k].character->MoveReset();
					//	break;
					//case 12:	// 壁
					//	character[k].character->MoveReset();
					//	break;

				default:
					break;

				}
			}
		}
		for (int i = 0, n = (int)obstacle.size(); i != n; ++i)
		{
			if (character[k].character->GetX() < obstacle[i]->GetX() + 54
				&& character[k].character->GetX() + 54 >obstacle[i]->GetX()
				&& character[k].character->GetY() < obstacle[i]->GetY() + 54
				&& character[k].character->GetY() + 54 > obstacle[i]->GetY()
				&& obstacle[i]->GetBrokenFlag() == false)
			{
				character[k].character->MoveReset();
			}
		}
	}

	// キャラクター同士のあたり判定
	// 1Pと2P
	if (character[0].character->GetX() <= character[1].character->GetX() + 64 - 5
		&& character[0].character->GetX() + 64 - 5 >= character[1].character->GetX()
		&& character[0].character->GetY() <= character[1].character->GetY() + 64 - 5
		&& character[0].character->GetY() + 64 - 5 >= character[1].character->GetY())
	{
		if (character[0].hp > 0)
		{
			character[1].character->MoveReset();
		}
		if (character[1].hp > 0)
		{
			character[0].character->MoveReset();
		}
		
		// 拳
		if (character[0].chara == 12
			&& character[0].character->GetRBbutton() == 1
			&& character[1].hp > 0)
		{
			if (character[1].chara == 5)
			{
				if ((character[0].direction == 0 && character[1].direction == 2)
					|| (character[0].direction == 1 && character[1].direction == 3)
					|| (character[0].direction == 2 && character[1].direction == 0)
					|| (character[0].direction == 3 && character[1].direction == 1))
				{
					PlaySoundMem(shield_se, DX_PLAYTYPE_BACK, FALSE);
					character[1].hp_shield -= 2;
				}
				else
				{
					PlaySoundMem(damage_se, DX_PLAYTYPE_BACK, FALSE);
					character[1].hp -= 2;
				}
			}
			else
			{
				PlaySoundMem(damage_se, DX_PLAYTYPE_BACK, FALSE);
				character[1].hp -= 2;
			}
		}
		if (character[1].chara == 12
			&& character[1].character->GetRBbutton() == 1
			&& character[0].hp > 0)
		{
			if (character[0].chara == 5)
			{
				if ((character[0].direction == 0 && character[1].direction == 2)
					|| (character[0].direction == 1 && character[1].direction == 3)
					|| (character[0].direction == 2 && character[1].direction == 0)
					|| (character[0].direction == 3 && character[1].direction == 1))
				{
					PlaySoundMem(shield_se, DX_PLAYTYPE_BACK, FALSE);
					character[0].hp_shield -= 2;
				}
				else
				{
					PlaySoundMem(damage_se, DX_PLAYTYPE_BACK, FALSE);
					character[0].hp -= 2;
				}
			}
			else
			{
				PlaySoundMem(damage_se, DX_PLAYTYPE_BACK, FALSE);
				character[0].hp -= 2;
			}
		}
	}

	// 1Pと3P
	if (character[0].character->GetX() <= character[2].character->GetX() + 64 - 5
		&& character[0].character->GetX() + 64 - 5 >= character[2].character->GetX()
		&& character[0].character->GetY() <= character[2].character->GetY() + 64 - 5
		&& character[0].character->GetY() + 64 - 5 >= character[2].character->GetY()
		&& playmode >= 1)
	{
		if (character[0].hp > 0)
		{
			character[2].character->MoveReset();
		}
		if (character[2].hp > 0)
		{
			character[0].character->MoveReset();
		}
		
		// 拳
		if (character[0].chara == 12
			&& character[0].character->GetRBbutton() == 1
			&& character[2].hp > 0)
		{
			if (character[2].chara == 5)
			{
				if ((character[0].direction == 0 && character[2].direction == 2)
					|| (character[0].direction == 1 && character[2].direction == 3)
					|| (character[0].direction == 2 && character[2].direction == 0)
					|| (character[0].direction == 3 && character[2].direction == 1))
				{
					PlaySoundMem(shield_se, DX_PLAYTYPE_BACK, FALSE);
					character[2].hp_shield -= 2;
				}
				else
				{
					PlaySoundMem(damage_se, DX_PLAYTYPE_BACK, FALSE);
					character[2].hp -= 2;
				}
			}
			else
			{
				PlaySoundMem(damage_se, DX_PLAYTYPE_BACK, FALSE);
				character[2].hp -= 2;
			}
		}
		if (character[2].chara == 12
			&& character[2].character->GetRBbutton() == 1
			&& character[0].hp > 0)
		{
			if (character[0].chara == 5)
			{
				if ((character[0].direction == 0 && character[2].direction == 2)
					|| (character[0].direction == 1 && character[2].direction == 3)
					|| (character[0].direction == 2 && character[2].direction == 0)
					|| (character[0].direction == 3 && character[2].direction == 1))
				{
					PlaySoundMem(shield_se, DX_PLAYTYPE_BACK, FALSE);
					character[0].hp_shield -= 2;
				}
				else
				{
					PlaySoundMem(damage_se, DX_PLAYTYPE_BACK, FALSE);
					character[0].hp -= 2;
				}
			}
			else
			{
				PlaySoundMem(damage_se, DX_PLAYTYPE_BACK, FALSE);
				character[0].hp -= 2;
			}
		}
	}

	// 1Pと4P
	if (character[0].character->GetX() <= character[3].character->GetX() + 64 - 5
		&& character[0].character->GetX() + 64 - 5 >= character[3].character->GetX() - 5
		&& character[0].character->GetY() <= character[3].character->GetY() + 64 - 5
		&& character[0].character->GetY() + 64 - 5 >= character[3].character->GetY()
		&& playmode == 2)
	{
		if (character[0].hp > 0)
		{
			character[3].character->MoveReset();
		}
		if (character[3].hp > 0)
		{
			character[0].character->MoveReset();
		}
		
		// 拳
		if (character[0].chara == 12
			&& character[0].character->GetRBbutton() == 1
			&& character[3].hp > 0)
		{
			if (character[3].chara == 5)
			{
				if ((character[0].direction == 0 && character[3].direction == 2)
					|| (character[0].direction == 1 && character[3].direction == 3)
					|| (character[0].direction == 2 && character[3].direction == 0)
					|| (character[0].direction == 3 && character[3].direction == 1))
				{
					PlaySoundMem(shield_se, DX_PLAYTYPE_BACK, FALSE);
					character[3].hp_shield -= 2;
				}
				else
				{
					PlaySoundMem(damage_se, DX_PLAYTYPE_BACK, FALSE);
					character[3].hp -= 2;
				}
			}
			else
			{
				PlaySoundMem(damage_se, DX_PLAYTYPE_BACK, FALSE);
				character[3].hp -= 2;
			}
		}
		if (character[3].chara == 12
			&& character[3].character->GetRBbutton() == 1
			&& character[0].hp > 0)
		{
			if (character[0].chara == 5)
			{
				if ((character[0].direction == 0 && character[3].direction == 2)
					|| (character[0].direction == 1 && character[3].direction == 3)
					|| (character[0].direction == 2 && character[3].direction == 0)
					|| (character[0].direction == 3 && character[3].direction == 1))
				{
					PlaySoundMem(shield_se, DX_PLAYTYPE_BACK, FALSE);
					character[0].hp_shield -= 2;
				}
				else
				{
					PlaySoundMem(damage_se, DX_PLAYTYPE_BACK, FALSE);
					character[0].hp -= 2;
				}
			}
			else
			{
				PlaySoundMem(damage_se, DX_PLAYTYPE_BACK, FALSE);
				character[0].hp -= 2;
			}
		}
	}

	// 2Pと3P
	if (character[1].character->GetX() <= character[2].character->GetX() + 64 - 5
		&& character[1].character->GetX() + 64 - 5 >= character[2].character->GetX()
		&& character[1].character->GetY() <= character[2].character->GetY() + 64 - 5
		&& character[1].character->GetY() + 64 - 5 >= character[2].character->GetY()
		&& playmode >= 1)
	{
		if (character[1].hp > 0)
		{
			character[2].character->MoveReset();
		}
		if (character[2].hp > 0)
		{
			character[1].character->MoveReset();
		}
		
		// 拳
		if (character[1].chara == 12
			&& character[1].character->GetRBbutton() == 1
			&& character[2].hp > 0)
		{
			if (character[2].chara == 5)
			{
				if ((character[1].direction == 0 && character[2].direction == 2)
					|| (character[1].direction == 1 && character[2].direction == 3)
					|| (character[1].direction == 2 && character[2].direction == 0)
					|| (character[1].direction == 3 && character[2].direction == 1))
				{
					PlaySoundMem(shield_se, DX_PLAYTYPE_BACK, FALSE);
					character[2].hp_shield -= 2;
				}
				else
				{
					PlaySoundMem(damage_se, DX_PLAYTYPE_BACK, FALSE);
					character[2].hp -= 2;
				}
			}
			else
			{
				PlaySoundMem(damage_se, DX_PLAYTYPE_BACK, FALSE);
				character[2].hp -= 2;
			}
		}
		if (character[2].chara == 12
			&& character[2].character->GetRBbutton() == 1
			&& character[1].hp > 0)
		{
			if (character[1].chara == 5)
			{
				if ((character[1].direction == 0 && character[2].direction == 2)
					|| (character[1].direction == 1 && character[2].direction == 3)
					|| (character[1].direction == 2 && character[2].direction == 0)
					|| (character[1].direction == 3 && character[2].direction == 1))
				{
					PlaySoundMem(shield_se, DX_PLAYTYPE_BACK, FALSE);
					character[1].hp_shield -= 2;
				}
				else
				{
					PlaySoundMem(damage_se, DX_PLAYTYPE_BACK, FALSE);
					character[1].hp -= 2;
				}
			}
			else
			{
				PlaySoundMem(damage_se, DX_PLAYTYPE_BACK, FALSE);
				character[1].hp -= 2;
			}
		}
	}

	// 2Pと4P
	if (character[1].character->GetX() <= character[3].character->GetX() + 64 - 5
		&& character[1].character->GetX() + 64 - 5 >= character[3].character->GetX()
		&& character[1].character->GetY() <= character[3].character->GetY() + 64 - 5
		&& character[1].character->GetY() + 64 - 5 >= character[3].character->GetY()
		&& playmode == 2)
	{
		if (character[1].hp > 0)
		{
			character[3].character->MoveReset();
		}
		if (character[3].hp > 0)
		{
			character[1].character->MoveReset();
		}
		
		// 拳
		if (character[1].chara == 12
			&& character[1].character->GetRBbutton() == 1
			&& character[3].hp > 0)
		{
			if (character[3].chara == 5)
			{
				if ((character[1].direction == 0 && character[3].direction == 2)
					|| (character[1].direction == 1 && character[3].direction == 3)
					|| (character[1].direction == 2 && character[3].direction == 0)
					|| (character[1].direction == 3 && character[3].direction == 1))
				{
					PlaySoundMem(shield_se, DX_PLAYTYPE_BACK, FALSE);
					character[3].hp_shield -= 2;
				}
				else
				{
					PlaySoundMem(damage_se, DX_PLAYTYPE_BACK, FALSE);
					character[3].hp -= 2;
				}
			}
			else
			{
				PlaySoundMem(damage_se, DX_PLAYTYPE_BACK, FALSE);
				character[3].hp -= 2;
			}
		}
		if (character[3].chara == 12
			&& character[3].character->GetRBbutton() == 1
			&& character[1].hp > 0)
		{
			if (character[1].chara == 5)
			{
				if ((character[1].direction == 0 && character[3].direction == 2)
					|| (character[1].direction == 1 && character[3].direction == 3)
					|| (character[1].direction == 2 && character[3].direction == 0)
					|| (character[1].direction == 3 && character[3].direction == 1))
				{
					PlaySoundMem(shield_se, DX_PLAYTYPE_BACK, FALSE);
					character[1].hp_shield -= 2;
				}
				else
				{
					PlaySoundMem(damage_se, DX_PLAYTYPE_BACK, FALSE);
					character[1].hp -= 2;
				}
			}
			else
			{
				PlaySoundMem(damage_se, DX_PLAYTYPE_BACK, FALSE);
				character[1].hp -= 2;
			}
		}
	}

	// 3Pと4P
	if (character[2].character->GetX() <= character[3].character->GetX() + 64 - 5
		&& character[2].character->GetX() + 64 - 5 >= character[3].character->GetX()
		&& character[2].character->GetY() <= character[3].character->GetY() + 64 - 5
		&& character[2].character->GetY() + 64 - 5 >= character[3].character->GetY()
		&& playmode == 2)
	{
		if (character[2].hp > 0)
		{
			character[3].character->MoveReset();
		}
		if (character[3].hp > 0)
		{
			character[2].character->MoveReset();
		}
		
		// 拳
		if (character[2].chara == 12
			&& character[2].character->GetRBbutton() == 1
			&& character[3].hp > 0)
		{
			if (character[3].chara == 5)
			{
				if ((character[2].direction == 0 && character[3].direction == 2)
					|| (character[2].direction == 1 && character[3].direction == 3)
					|| (character[2].direction == 2 && character[3].direction == 0)
					|| (character[2].direction == 3 && character[3].direction == 1))
				{
					PlaySoundMem(shield_se, DX_PLAYTYPE_BACK, FALSE);
					character[3].hp_shield -= 2;
				}
				else
				{
					PlaySoundMem(damage_se, DX_PLAYTYPE_BACK, FALSE);
					character[3].hp -= 2;
				}
			}
			else
			{
				PlaySoundMem(damage_se, DX_PLAYTYPE_BACK, FALSE);
				character[3].hp -= 2;
			}
		}
		if (character[3].chara == 12
			&& character[3].character->GetRBbutton() == 1
			&& character[2].hp > 0)
		{
			if (character[2].chara == 5)
			{
				if ((character[2].direction == 0 && character[3].direction == 2)
					|| (character[2].direction == 1 && character[3].direction == 3)
					|| (character[2].direction == 2 && character[3].direction == 0)
					|| (character[2].direction == 3 && character[3].direction == 1))
				{
					PlaySoundMem(shield_se, DX_PLAYTYPE_BACK, FALSE);
					character[2].hp_shield -= 2;
				}
				else
				{
					PlaySoundMem(damage_se, DX_PLAYTYPE_BACK, FALSE);
					character[2].hp -= 2;
				}
			}
			else
			{
				PlaySoundMem(damage_se, DX_PLAYTYPE_BACK, FALSE);
				character[2].hp -= 2;
			}
		}
	}
}

// 武器ドロップ
void CharacterManager::DropWeaponInit()
{
	mt19937 mt(rnd());     //  メルセンヌ・ツイスタの32ビット版、引数は初期シード値
	uniform_int_distribution<> randW(2, map->GetMapWidth() - 3);        // [0, 99] 範囲の一様乱数
	uniform_int_distribution<> randD(0, 11);        // [0, 99] 範囲の一様乱数
	int j = 0;

	for (int i = 2, n = map->GetMapHeight() - 2; i != n;)
	{
		j = randW(mt);
		if (map->GetMapData(j * 64, i * 64) == 00)
		{
			drop[i - 2].dropflag = true;		// iが2からなので減らしてる
			drop[i - 2].drop = new Drop(j * 64, i * 64, randD(mt));		// 武器生成
			//drop.push_back(new Drop(j * 64, i * 64, 10));
			dropnum++;		// 落ちた数を観測してる
			++i;		// 横一列に一個のみしか生成させないようにしてる
		}
		else
		{
			j = randW(mt);
		}
	}
}

// 初期以外の武器ドロップ
void CharacterManager::DropWeapon()
{
	mt19937 mt(rnd());     //  メルセンヌ・ツイスタの32ビット版、引数は初期シード値
	uniform_int_distribution<> randW(2, map->GetMapWidth() - 3);        // [0, 99] 範囲の一様乱数
	uniform_int_distribution<> randD(0, 11);        // [0, 99] 範囲の一様乱数
	int j = 0;

	for (int i = 2, n = map->GetMapHeight() - 2; i != n;)
	{
		// 武器がその列に落ちていなかった場合
		if (drop[i - 2].dropflag == false)
		{
			j = randW(mt);
			if (map->GetMapData(j * 64, i * 64) == 00)		// そこが00だった場合
			{
				drop[i - 2].dropflag = true;
				drop[i - 2].drop = new Drop(j * 64, i * 64, randD(mt));
				dropnum++;
				++i;
			}
			else
			{
				j = randW(mt);
			}
		}
		// 武器がその列に落ちていた場合
		else
		{
			++i;
		}
	}
}

void CharacterManager::BulletForm()
{
	// P
	for (int i = 0; i != playernum; ++i)
	{
		if (character[i].chara == 6)
		{
			character[i].gunspeed = sniperspeed;
		}
		else if (character[i].chara == 9)
		{
			character[i].gunspeed = gatlingspeed;
		}
		if ((KeyData::Get(KEY_INPUT_G) % bulletinterval == 1
			|| character[i].character->GetRTbutton() % bulletinterval == 1)
			&& character[i].character->tamanum > 0)
		{
			character[i].character->tamanum--;		// 減らしてから生成している、仕様です
			if (character[i].chara == 6)
			{
				PlaySoundMem(sniper_se, DX_PLAYTYPE_BACK, TRUE);
				if (character[i].direction == 0)
				{
					bullet.push_back(new Bullet(character[i].x + 64 + 5 - character[i].gunspeed, character[i].y + 21, 0, character[i].gunspeed, 10 * 4));
				}
				else if (character[i].direction == 1)
				{
					bullet.push_back(new Bullet(character[i].x + 21, character[i].y + 64 + 5 - character[i].gunspeed, 1, character[i].gunspeed, 10 * 4));
				}
				else if (character[i].direction == 2)
				{
					bullet.push_back(new Bullet(character[i].x - 5 - 16 + character[i].gunspeed, character[i].y + 21, 2, character[i].gunspeed, 10 * 4));
				}
				else
				{
					bullet.push_back(new Bullet(character[i].x + 21, character[i].y - 5 - 16 + character[i].gunspeed, 3, character[i].gunspeed, 10 * 4));
				}
			}
			else if (character[i].chara == 9)
			{
				PlaySoundMem(gatling_se, DX_PLAYTYPE_BACK, TRUE);
				if (character[i].direction == 0)
				{
					bullet.push_back(new Bullet(character[i].x + 64 + 5 - character[i].gunspeed, character[i].y + 21 + 12, 0, character[i].gunspeed, 2 * 4));
				}
				else if (character[i].direction == 1)
				{
					bullet.push_back(new Bullet(character[i].x + 21 - 8, character[i].y + 64 + 5 - character[i].gunspeed, 1, character[i].gunspeed, 2 * 4));
				}
				else if (character[i].direction == 2)
				{
					bullet.push_back(new Bullet(character[i].x - 5 - 16 + character[i].gunspeed, character[i].y + 21 + 12, 2, character[i].gunspeed, 2 * 4));
				}
				else
				{
					bullet.push_back(new Bullet(character[i].x + 21 + 8, character[i].y - 5 - 16 + character[i].gunspeed, 3, character[i].gunspeed, 2 * 4));
				}
			}
		}
	}

	// 銃座
	int speedGS = 5;
	speedGS = gunseatspeed;
	for (int i = 0, m = (int)gunseat.size(); i != m; ++i)
	{
		if (gunseat[i]->gunnum > 0
			&& gunseat[i]->hp > 0
			&& gunseat[i]->GetShot() % bulletinterval == 1)
		{
			gunseat[i]->gunnum--;		// 減らしてから生成している、仕様です
			PlaySoundMem(gunseat_se, DX_PLAYTYPE_BACK, FALSE);
			if (gunseat[i]->GetDire() == 0)
			{
				bullet.push_back(new Bullet(gunseat[i]->GetX() + 64 + 5 - speedGS, gunseat[i]->GetY() + 21, 0, speedGS, 2 * 4));
			}
			else if (gunseat[i]->GetDire() == 1)
			{
				bullet.push_back(new Bullet(gunseat[i]->GetX() + 21, gunseat[i]->GetY() + 64 + 5 - speedGS, 1, speedGS, 2 * 4));
			}
			else if (gunseat[i]->GetDire() == 2)
			{
				bullet.push_back(new Bullet(gunseat[i]->GetX() - 5 - 64 + speedGS, gunseat[i]->GetY() + 21, 2, speedGS, 2 * 4));
			}
			else
			{
				bullet.push_back(new Bullet(gunseat[i]->GetX() + 21, gunseat[i]->GetY() - 5 - 64 + speedGS, 3, speedGS, 2 * 4));
			}
		}
	}
}

void CharacterManager::BulletColl()
{
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
		// map
		for (int k = 0; k != 2; ++k)
		{
			for (int j = 0; j != 2; ++j)
			{
				if (map->GetMapData(bullet[i]->GetX() + (k * (64 - 48)), bullet[i]->GetY() + (j * (64 - 48))) == 10)
				{
					bullet.erase(bullet.begin() + i);
					goto MAP;
				}
			}
		}
		// P
		for (int j = 0; j != playernum; ++j)
		{
			if (bullet[i]->GetX() < character[j].character->GetX() + 64 + 5
				&& bullet[i]->GetX() + 16 - 5 > character[j].character->GetX()
				&& bullet[i]->GetY() < character[j].character->GetY() + 64 + 5
				&& bullet[i]->GetY() + 16 - 5 > character[j].character->GetY()
				&& character[j].hp > 0)
			{
				if (character[j].chara == 5)
				{
					if ((character[j].direction == 0 && bullet[i]->GetDire() == 2)
						|| (character[j].direction == 1 && bullet[i]->GetDire() == 3)
						|| (character[j].direction == 2 && bullet[i]->GetDire() == 0)
						|| (character[j].direction == 3 && bullet[i]->GetDire() == 1))
					{
						character[j].hp_shield -= bullet[i]->GetPower();
						PlaySoundMem(shield_se, DX_PLAYTYPE_BACK, FALSE);
					}
					else
					{
						character[j].hp -= bullet[i]->GetPower();
						PlaySoundMem(damage_se, DX_PLAYTYPE_BACK, FALSE);
					}
				}
				else
				{
					character[j].hp -= bullet[i]->GetPower();
					PlaySoundMem(damage_se, DX_PLAYTYPE_BACK, FALSE);
				}
				bullet.erase(bullet.begin() + i);
				goto PLAYER;
			}
		}
		for (int j = 0, n = (int)obstacle.size(); j != n; ++j)
		{
			if (bullet[i]->GetX() < obstacle[j]->GetX() + 64 + 5
				&& bullet[i]->GetX() + 16 - 5 > obstacle[j]->GetX()
				&& bullet[i]->GetY() < obstacle[j]->GetY() + 64 + 5
				&& bullet[i]->GetY() + 16 - 5 > obstacle[j]->GetY()
				&& obstacle[j]->hitflag == false)
			{
				obstacle[j]->hitflag = true;
				bullet.erase(bullet.begin() + i);
				goto OBSTACLE;
			}
		}
		for (int j = 0, n = (int)gunseat.size(); j != n; ++j)
		{
			if (bullet[i]->GetX() < gunseat[j]->GetX() + 64
				&& bullet[i]->GetX() + 64 > gunseat[j]->GetX()
				&& bullet[i]->GetY() < gunseat[j]->GetY() + 64
				&& bullet[i]->GetY() + 64 > gunseat[j]->GetY()
				&& gunseat[j]->hp > 0)
			{
				gunseat[j]->hp -= bullet[i]->GetPower();
				bullet.erase(bullet.begin() + i);
				goto GUNSEAT;
			}
		}
		for (int j = 0, n = (int)doll.size(); j != n; ++j)
		{
			if (bullet[i]->GetX() < doll[j]->GetX() + 64
				&& bullet[i]->GetX() + 64 > doll[j]->GetX()
				&& bullet[i]->GetY() < doll[j]->GetY() + 64
				&& bullet[i]->GetY() + 64 > doll[j]->GetY()
				&& doll[j]->hp > 0)
			{
				doll[j]->hp -= bullet[i]->GetPower();
				bullet.erase(bullet.begin() + i);
				goto DOLL;
			}
		}
	}
MAP:
PLAYER:
OBSTACLE:
GUNSEAT:
DOLL:
	return;
}

void CharacterManager::ObstacleInit()
{
	for (int i = 0, n = map->GetMapHeight(); i != n; ++i)
	{
		for (int j = 0, m = map->GetMapWidth(); j != m; ++j)
		{
			switch (map->GetMapData(j * 64, i * 64)) {
			case 11:
				obstacle.push_back(new Obstacle(11, j * 64, i * 64));
				break;
			case 12:
				obstacle.push_back(new Obstacle(12, j * 64, i * 64));
				break;
			default:
				break;
			}
		}
	}
}

// ナイフに関して
void CharacterManager::KnifeProcess()
{
	// 1P
	// ナイフだった時
	if (character[0].chara == 0 || character[0].chara == 7)
	{
		if (KeyData::Get(KEY_INPUT_G) == 1
			|| character[0].character->GetRBbutton() == 1)
		{
			PlaySoundMem(knife_se, DX_PLAYTYPE_BACK, FALSE);
			character[0].knifeframe = 1;
		}
		else
		{
			character[0].knifeframe = 0;
		}
	}
	if (character[0].knifeframe == 1)
	{
		for (int i = 1; i != playernum; ++i)
		{
			switch (character[0].direction)
			{
			case 0:		// 右
				if (character[0].character->GetX() + 64 + 32 >= character[i].character->GetX()
					&& character[0].character->GetX() + 64 <= character[i].character->GetX()
					&& character[0].character->GetY() < character[i].character->GetY() + 64
					&& character[0].character->GetY() + 64 > character[i].character->GetY()
					&& character[i].hp > 0)
				{
					if (character[i].chara == 5)
					{
						if (character[i].direction == 2)
						{
							PlaySoundMem(shield_se, DX_PLAYTYPE_BACK, FALSE);
							character[i].hp_shield -= 1;
						}
						else
						{
							PlaySoundMem(damage_se, DX_PLAYTYPE_BACK, FALSE);
							character[i].hp -= 1;
						}
					}
					else
					{
						PlaySoundMem(damage_se, DX_PLAYTYPE_BACK, FALSE);
						character[i].hp -= 1;
					}
				}
				break;
			case 1:	// 下
				if (character[0].character->GetY() + 64 + 32 >= character[i].character->GetY()
					&& character[0].character->GetY() + 64 <= character[i].character->GetY()
					&& character[0].character->GetX() < character[i].character->GetX() + 64
					&& character[0].character->GetX() + 64 > character[i].character->GetX()
					&& character[i].hp > 0)
				{
					if (character[i].chara == 5)
					{
						if (character[i].direction == 3)
						{
							PlaySoundMem(shield_se, DX_PLAYTYPE_BACK, FALSE);
							character[i].hp_shield -= 1;
						}
						else
						{
							PlaySoundMem(damage_se, DX_PLAYTYPE_BACK, FALSE);
							character[i].hp -= 1;
						}
					}
					else
					{
						PlaySoundMem(damage_se, DX_PLAYTYPE_BACK, FALSE);
						character[i].hp -= 1;
					}
				}
				break;
			case 2:	// 左
				if (character[0].character->GetX() - 32 <= character[i].character->GetX() + 64
					&& character[0].character->GetX() >= character[i].character->GetX() + 64
					&& character[0].character->GetY() < character[i].character->GetY() + 64
					&& character[0].character->GetY() + 64 > character[i].character->GetY()
					&& character[i].hp > 0)
				{
					if (character[i].chara == 5)
					{
						if (character[i].direction == 0)
						{
							PlaySoundMem(shield_se, DX_PLAYTYPE_BACK, FALSE);
							character[i].hp_shield -= 1;
						}
						else
						{
							PlaySoundMem(damage_se, DX_PLAYTYPE_BACK, FALSE);
							character[i].hp -= 1;
						}
					}
					else
					{
						PlaySoundMem(damage_se, DX_PLAYTYPE_BACK, FALSE);
						character[i].hp -= 1;
					}
				}
				break;
			case 3:	// 上
				if (character[0].character->GetY() - 32 <= character[i].character->GetY() + 64
					&& character[0].character->GetY() >= character[i].character->GetY() + 64
					&& character[0].character->GetX() < character[i].character->GetX() + 64
					&& character[0].character->GetX() + 64 > character[i].character->GetX()
					&& character[i].hp > 0)
				{
					if (character[i].chara == 5)
					{
						if (character[i].direction == 1)
						{
							PlaySoundMem(shield_se, DX_PLAYTYPE_BACK, FALSE);
							character[i].hp_shield -= 1;
						}
						else
						{
							PlaySoundMem(damage_se, DX_PLAYTYPE_BACK, FALSE);
							character[i].hp -= 1;
						}
					}
					else
					{
						PlaySoundMem(damage_se, DX_PLAYTYPE_BACK, FALSE);
						character[i].hp -= 1;
					}
				}
				break;
			default:
				break;
			}
		}
	}

	// 2P
	// ナイフだった時
	if (character[1].chara == 0 || character[1].chara == 7)
	{
		if ((KeyData::Get(KEY_INPUT_H) == 1
			|| character[1].character->GetRBbutton() == 1))
		{
			PlaySoundMem(knife_se, DX_PLAYTYPE_BACK, FALSE);
			character[1].knifeframe = 1;
		}
		else
		{
			character[1].knifeframe = 0;
		}
	}
	if (character[1].knifeframe == 1)
	{
		for (int i = 0; i != playernum; ++i)
		{
			if (i == 1)
			{
				continue;
			}
			switch (character[1].direction)
			{
			case 0:	// 右
				if (character[1].character->GetX() + 64 + 32 >= character[i].character->GetX()
					&& character[1].character->GetX() + 64 <= character[i].character->GetX()
					&& character[1].character->GetY() < character[i].character->GetY() + 64
					&& character[1].character->GetY() + 64 > character[i].character->GetY()
					&& character[i].hp > 0)
				{
					if (character[i].chara == 5)
					{
						if (character[i].direction == 2)
						{
							PlaySoundMem(shield_se, DX_PLAYTYPE_BACK, FALSE);
							character[i].hp_shield -= 1;
						}
						else
						{
							PlaySoundMem(damage_se, DX_PLAYTYPE_BACK, FALSE);
							character[i].hp -= 1;
						}
					}
					else
					{
						PlaySoundMem(damage_se, DX_PLAYTYPE_BACK, FALSE);
						character[i].hp -= 1;
					}
				}
				break;
			case 1:	// 下
				if (character[1].character->GetY() + 32 + 64 >= character[i].character->GetY()
					&& character[1].character->GetY() + 64 <= character[i].character->GetY()
					&& character[1].character->GetX() < character[i].character->GetX() + 64
					&& character[1].character->GetX() + 64 > character[i].character->GetX()
					&& character[i].hp > 0)
				{
					if (character[i].chara == 5)
					{
						if (character[i].direction == 3)
						{
							PlaySoundMem(shield_se, DX_PLAYTYPE_BACK, FALSE);
							character[i].hp_shield -= 1;
						}
						else
						{
							PlaySoundMem(damage_se, DX_PLAYTYPE_BACK, FALSE);
							character[i].hp -= 1;
						}
					}
					else
					{
						PlaySoundMem(damage_se, DX_PLAYTYPE_BACK, FALSE);
						character[i].hp -= 1;
					}
				}
				break;
			case 2:	// 左
				if (character[1].character->GetX() - 32 <= character[i].character->GetX() + 64
					&& character[1].character->GetX() >= character[i].character->GetX() + 64
					&& character[1].character->GetY() < character[i].character->GetY() + 64
					&& character[1].character->GetY() + 64 > character[i].character->GetY()
					&& character[i].hp > 0)
				{
					if (character[i].chara == 5)
					{
						if (character[i].direction == 0)
						{
							PlaySoundMem(shield_se, DX_PLAYTYPE_BACK, FALSE);
							character[i].hp_shield -= 1;
						}
						else
						{
							PlaySoundMem(damage_se, DX_PLAYTYPE_BACK, FALSE);
							character[i].hp -= 1;
						}
					}
					else
					{
						PlaySoundMem(damage_se, DX_PLAYTYPE_BACK, FALSE);
						character[i].hp -= 1;
					}
				}
				break;
			case 3:	// 上
				if (character[1].character->GetY() - 32 <= character[i].character->GetY() + 64
					&& character[1].character->GetY() >= character[i].character->GetY() + 64
					&& character[1].character->GetX() < character[i].character->GetX() + 64
					&& character[1].character->GetX() + 64 > character[i].character->GetX()
					&& character[i].hp > 0)
				{
					if (character[i].chara == 5)
					{
						if (character[i].direction == 1)
						{
							PlaySoundMem(shield_se, DX_PLAYTYPE_BACK, FALSE);
							character[i].hp_shield -= 1;
						}
						else
						{
							PlaySoundMem(damage_se, DX_PLAYTYPE_BACK, FALSE);
							character[i].hp -= 1;
						}
					}
					else
					{
						PlaySoundMem(damage_se, DX_PLAYTYPE_BACK, FALSE);
						character[i].hp -= 1;
					}
				}
				break;
			default:
				break;
			}
		}
	}

	// 3P
	// ナイフだった時
	if ((character[2].chara == 0 || character[2].chara == 7)
		&& playmode >= 1)
	{
		if (KeyData::Get(KEY_INPUT_J) == 1
			|| character[2].character->GetRBbutton() == 1)
		{
			PlaySoundMem(knife_se, DX_PLAYTYPE_BACK, FALSE);
			character[2].knifeframe = 1;
		}
		else
		{
			character[2].knifeframe = 0;
		}
	}
	if (character[2].knifeframe == 1
		&& playmode >= 1)
	{
		for (int i = 0; i != playernum; ++i)
		{
			if (i == 2)
			{
				continue;
			}
			switch (character[2].direction)
			{
			case 0:		// 右
				if (character[2].character->GetX() + 64 + 32 >= character[i].character->GetX()
					&& character[2].character->GetX() + 64 <= character[i].character->GetX()
					&& character[2].character->GetY() < character[i].character->GetY() + 64
					&& character[2].character->GetY() + 64 > character[i].character->GetY()
					&& character[i].hp > 0)
				{
					if (character[i].chara == 5)
					{
						if (character[i].direction == 2)
						{
							PlaySoundMem(shield_se, DX_PLAYTYPE_BACK, FALSE);
							character[i].hp_shield -= 1;
						}
						else
						{
							PlaySoundMem(damage_se, DX_PLAYTYPE_BACK, FALSE);
							character[i].hp -= 1;
						}
					}
					else
					{
						PlaySoundMem(damage_se, DX_PLAYTYPE_BACK, FALSE);
						character[i].hp -= 1;
					}
				}
				break;
			case 1:	// 下
				if (character[2].character->GetY() + 64 + 32 >= character[i].character->GetY()
					&& character[2].character->GetY() + 64 <= character[i].character->GetY()
					&& character[2].character->GetX() < character[i].character->GetX() + 64
					&& character[2].character->GetX() + 64 > character[i].character->GetX()
					&& character[i].hp > 0)
				{
					if (character[i].chara == 5)
					{
						if (character[i].direction == 3)
						{
							PlaySoundMem(shield_se, DX_PLAYTYPE_BACK, FALSE);
							character[i].hp_shield -= 1;
						}
						else
						{
							PlaySoundMem(damage_se, DX_PLAYTYPE_BACK, FALSE);
							character[i].hp -= 1;
						}
					}
					else
					{
						PlaySoundMem(damage_se, DX_PLAYTYPE_BACK, FALSE);
						character[i].hp -= 1;
					}
				}
				break;
			case 2:	// 左
				if (character[2].character->GetX() - 32 <= character[i].character->GetX() + 64
					&& character[2].character->GetX() >= character[i].character->GetX() + 64
					&& character[2].character->GetY() < character[i].character->GetY() + 64
					&& character[2].character->GetY() + 64 > character[i].character->GetY()
					&& character[i].hp > 0)
				{
					if (character[i].chara == 5)
					{
						if (character[i].direction == 0)
						{
							PlaySoundMem(shield_se, DX_PLAYTYPE_BACK, FALSE);
							character[i].hp_shield -= 1;
						}
						else
						{
							PlaySoundMem(damage_se, DX_PLAYTYPE_BACK, FALSE);
							character[i].hp -= 1;
						}
					}
					else
					{
						PlaySoundMem(damage_se, DX_PLAYTYPE_BACK, FALSE);
						character[i].hp -= 1;
					}
				}
				break;
			case 3:	// 上
				if (character[2].character->GetY() - 32 <= character[i].character->GetY() + 64
					&& character[2].character->GetY() >= character[i].character->GetY() + 64
					&& character[2].character->GetX() < character[i].character->GetX() + 64
					&& character[2].character->GetX() + 64 > character[i].character->GetX()
					&& character[i].hp > 0)
				{
					if (character[i].chara == 5)
					{
						if (character[i].direction == 1)
						{
							PlaySoundMem(shield_se, DX_PLAYTYPE_BACK, FALSE);
							character[i].hp_shield -= 1;
						}
						else
						{
							PlaySoundMem(damage_se, DX_PLAYTYPE_BACK, FALSE);
							character[i].hp -= 1;
						}
					}
					else
					{
						PlaySoundMem(damage_se, DX_PLAYTYPE_BACK, FALSE);
						character[i].hp -= 1;
					}
				}
				break;
			default:
				break;
			}
		}
	}

	// 4P
	// ナイフだった時
	if ((character[3].chara == 0 || character[3].chara == 7)
		&& playmode == 2)
	{
		if (KeyData::Get(KEY_INPUT_K) == 1
			|| character[3].character->GetRBbutton() == 1)
		{
			PlaySoundMem(knife_se, DX_PLAYTYPE_BACK, FALSE);
			character[3].knifeframe = 1;
		}
		else
		{
			character[3].knifeframe = 0;
		}
	}
	if (character[3].knifeframe == 1
		&& playmode == 2)
	{
		for (int i = 0; i != playernum - 1; ++i)
		{
			switch (character[3].direction)
			{
			case 0:		// 右
				if (character[3].character->GetX() + 64 + 32 >= character[i].character->GetX()
					&& character[3].character->GetX() + 64 <= character[i].character->GetX()
					&& character[3].character->GetY() < character[i].character->GetY() + 64
					&& character[3].character->GetY() + 64 > character[i].character->GetY()
					&& character[i].hp > 0)
				{
					if (character[i].chara == 5)
					{
						if (character[i].direction == 2)
						{
							PlaySoundMem(shield_se, DX_PLAYTYPE_BACK, FALSE);
							character[i].hp_shield -= 1;
						}
						else
						{
							PlaySoundMem(damage_se, DX_PLAYTYPE_BACK, FALSE);
							character[i].hp -= 1;
						}
					}
					else
					{
						PlaySoundMem(damage_se, DX_PLAYTYPE_BACK, FALSE);
						character[i].hp -= 1;
					}
				}
				break;
			case 1:	// 下
				if (character[3].character->GetY() + 64 + 32 >= character[i].character->GetY()
					&& character[3].character->GetY() + 64 <= character[i].character->GetY()
					&& character[3].character->GetX() < character[i].character->GetX() + 64
					&& character[3].character->GetX() + 64 > character[i].character->GetX()
					&& character[i].hp > 0)
				{
					if (character[i].chara == 5)
					{
						if (character[i].direction == 3)
						{
							PlaySoundMem(shield_se, DX_PLAYTYPE_BACK, FALSE);
							character[i].hp_shield -= 1;
						}
						else
						{
							PlaySoundMem(damage_se, DX_PLAYTYPE_BACK, FALSE);
							character[i].hp -= 1;
						}
					}
					else
					{
						PlaySoundMem(damage_se, DX_PLAYTYPE_BACK, FALSE);
						character[i].hp -= 1;
					}
				}
				break;
			case 2:	// 左
				if (character[3].character->GetX() - 32 <= character[i].character->GetX() + 64
					&& character[3].character->GetX() >= character[i].character->GetX() + 64
					&& character[3].character->GetY() < character[i].character->GetY() + 64
					&& character[3].character->GetY() + 64 > character[i].character->GetY()
					&& character[i].hp > 0)
				{
					if (character[i].chara == 5)
					{
						if (character[i].direction == 0)
						{
							PlaySoundMem(shield_se, DX_PLAYTYPE_BACK, FALSE);
							character[i].hp_shield -= 1;
						}
						else
						{
							PlaySoundMem(damage_se, DX_PLAYTYPE_BACK, FALSE);
							character[i].hp -= 1;
						}
					}
					else
					{
						PlaySoundMem(damage_se, DX_PLAYTYPE_BACK, FALSE);
						character[i].hp -= 1;
					}
				}
				break;
			case 3:	// 上
				if (character[3].character->GetY() - 32 <= character[i].character->GetY() + 64
					&& character[3].character->GetY() >= character[i].character->GetY() + 64
					&& character[3].character->GetX() < character[i].character->GetX() + 64
					&& character[3].character->GetX() + 64 > character[i].character->GetX()
					&& character[i].hp > 0)
				{
					if (character[i].chara == 5)
					{
						if (character[i].direction == 1)
						{
							PlaySoundMem(shield_se, DX_PLAYTYPE_BACK, FALSE);
							character[i].hp_shield -= 1;
						}
						else
						{
							PlaySoundMem(damage_se, DX_PLAYTYPE_BACK, FALSE);
							character[i].hp -= 1;
						}
					}
					else
					{
						PlaySoundMem(damage_se, DX_PLAYTYPE_BACK, FALSE);
						character[i].hp -= 1;
					}
				}
				break;
			default:
				break;
			}
		}
	}
}

// 剣に関して
void CharacterManager::SwordProcess()
{
	// 1P
	// 剣のとき
	if (character[0].chara == 1)
	{
		if ((KeyData::Get(KEY_INPUT_G) == 1
			|| character[0].character->GetRBbutton() == 1)
			&& character[0].knifeframe < -60)
		{
			PlaySoundMem(knife_se, DX_PLAYTYPE_BACK, FALSE);
			character[0].knifeframe = 10;
		}
		else
		{
			if (character[0].knifeframe > -65)
			{
				character[0].knifeframe--;
			}
		}
	}
	if (character[0].knifeframe == 5)
	{
		for (int i = 1; i != playernum; ++i)
		{
			switch (character[0].direction)
			{
			case 0:	// 右
				if (character[0].character->GetX() + 48 + 64 >= character[i].character->GetX()
					&& character[0].character->GetX() + 64 <= character[i].character->GetX()
					&& character[0].character->GetY() < character[i].character->GetY() + 64
					&& character[0].character->GetY() + 64 > character[i].character->GetY()
					&& character[i].hp > 0)
				{
					if (character[i].chara == 5)
					{
						if (character[i].direction == 2)
						{
							PlaySoundMem(shield_se, DX_PLAYTYPE_BACK, FALSE);
							character[i].hp_shield -= 3;
						}
						else
						{
							PlaySoundMem(damage_se, DX_PLAYTYPE_BACK, FALSE);
							character[i].hp -= 3;
						}
					}
					else
					{
						PlaySoundMem(damage_se, DX_PLAYTYPE_BACK, FALSE);
						character[i].hp -= 3;
					}
				}
				break;
			case 1:	// 下
				if (character[0].character->GetY() + 48 + 64 >= character[i].character->GetY()
					&& character[0].character->GetY() + 64 <= character[i].character->GetY()
					&& character[0].character->GetX() < character[i].character->GetX() + 64
					&& character[0].character->GetX() + 64 > character[i].character->GetX()
					&& character[i].hp > 0)
				{
					if (character[i].chara == 5)
					{
						if (character[i].direction == 3)
						{
							PlaySoundMem(shield_se, DX_PLAYTYPE_BACK, FALSE);
							character[i].hp_shield -= 3;
						}
						else
						{
							PlaySoundMem(damage_se, DX_PLAYTYPE_BACK, FALSE);
							character[i].hp -= 3;
						}
					}
					else
					{
						PlaySoundMem(damage_se, DX_PLAYTYPE_BACK, FALSE);
						character[i].hp -= 3;
					}
				}
				break;
			case 2:	// 左
				if (character[0].character->GetX() - 48 <= character[i].character->GetX() + 64
					&& character[0].character->GetX() >= character[i].character->GetX() + 64
					&& character[0].character->GetY() < character[i].character->GetY() + 64
					&& character[0].character->GetY() + 64 > character[i].character->GetY()
					&& character[i].hp > 0)
				{
					if (character[i].chara == 5)
					{
						if (character[i].direction == 0)
						{
							PlaySoundMem(shield_se, DX_PLAYTYPE_BACK, FALSE);
							character[i].hp_shield -= 3;
						}
						else
						{
							PlaySoundMem(damage_se, DX_PLAYTYPE_BACK, FALSE);
							character[i].hp -= 3;
						}
					}
					else
					{
						PlaySoundMem(damage_se, DX_PLAYTYPE_BACK, FALSE);
						character[i].hp -= 3;
					}
				}
				break;
			case 3:	// 上
				if (character[0].character->GetY() - 48 <= character[i].character->GetY() + 64
					&& character[0].character->GetY() >= character[i].character->GetY() + 64
					&& character[0].character->GetX() < character[i].character->GetX() + 64
					&& character[0].character->GetX() + 64 > character[i].character->GetX()
					&& character[i].hp > 0)
				{
					if (character[i].chara == 5)
					{
						if (character[i].direction == 1)
						{
							PlaySoundMem(shield_se, DX_PLAYTYPE_BACK, FALSE);
							character[i].hp_shield -= 3;
						}
						else
						{
							PlaySoundMem(damage_se, DX_PLAYTYPE_BACK, FALSE);
							character[i].hp -= 3;
						}
					}
					else
					{
						PlaySoundMem(damage_se, DX_PLAYTYPE_BACK, FALSE);
						character[i].hp -= 3;
					}
				}
				break;
			default:
				break;
			}
		}
	}

	// 2P
	// 剣のとき
	if (character[1].chara == 1)
	{
		if ((KeyData::Get(KEY_INPUT_H) == 1
			|| character[1].character->GetRBbutton() == 1)
			&& character[1].knifeframe < -60)
		{
			PlaySoundMem(knife_se, DX_PLAYTYPE_BACK, FALSE);
			character[1].knifeframe = 10;
		}
		else
		{
			if (character[1].knifeframe > -65)
			{
				character[1].knifeframe--;
			}
		}
	}
	if (character[1].knifeframe == 5)
	{
		for (int i = 0; i != playernum; ++i)
		{
			if (i == 1)
			{
				continue;
			}
			switch (character[1].direction)
			{
			case 0:	// 右
				if (character[1].character->GetX() + 48 + 64 >= character[i].character->GetX()
					&& character[1].character->GetX() + 64 <= character[i].character->GetX()
					&& character[1].character->GetY() < character[i].character->GetY() + 64
					&& character[1].character->GetY() + 64 > character[i].character->GetY()
					&& character[i].hp > 0)
				{
					if (character[i].chara == 5)
					{
						if (character[i].direction == 2)
						{
							PlaySoundMem(shield_se, DX_PLAYTYPE_BACK, FALSE);
							character[i].hp_shield -= 3;
						}
						else
						{
							PlaySoundMem(damage_se, DX_PLAYTYPE_BACK, FALSE);
							character[i].hp -= 3;
						}
					}
					else
					{
						PlaySoundMem(damage_se, DX_PLAYTYPE_BACK, FALSE);
						character[i].hp -= 3;
					}
				}
				break;
			case 1:	// 下
				if (character[1].character->GetY() + 48 + 64 >= character[i].character->GetY()
					&& character[1].character->GetY() + 64 <= character[i].character->GetY()
					&& character[1].character->GetX() < character[i].character->GetX() + 64
					&& character[1].character->GetX() + 64 > character[i].character->GetX()
					&& character[i].hp > 0)
				{
					if (character[i].chara == 5)
					{
						if (character[i].direction == 3)
						{
							PlaySoundMem(shield_se, DX_PLAYTYPE_BACK, FALSE);
							character[i].hp_shield -= 3;
						}
						else
						{
							PlaySoundMem(damage_se, DX_PLAYTYPE_BACK, FALSE);
							character[i].hp -= 3;
						}
					}
					else
					{
						PlaySoundMem(damage_se, DX_PLAYTYPE_BACK, FALSE);
						character[i].hp -= 3;
					}
				}
				break;
			case 2:	// 左
				if (character[1].character->GetX() - 48 <= character[i].character->GetX() + 64
					&& character[1].character->GetX() >= character[i].character->GetX() + 64
					&& character[1].character->GetY() < character[i].character->GetY() + 64
					&& character[1].character->GetY() + 64 > character[i].character->GetY()
					&& character[i].hp > 0)
				{
					if (character[i].chara == 5)
					{
						if (character[i].direction == 0)
						{
							PlaySoundMem(shield_se, DX_PLAYTYPE_BACK, FALSE);
							character[i].hp_shield -= 3;
						}
						else
						{
							PlaySoundMem(damage_se, DX_PLAYTYPE_BACK, FALSE);
							character[i].hp -= 3;
						}
					}
					else
					{
						PlaySoundMem(damage_se, DX_PLAYTYPE_BACK, FALSE);
						character[i].hp -= 3;
					}
				}
				break;
			case 3:	// 上
				if (character[1].character->GetY() - 48 <= character[i].character->GetY() + 64
					&& character[1].character->GetY() >= character[i].character->GetY() + 64
					&& character[1].character->GetX() < character[i].character->GetX() + 64
					&& character[1].character->GetX() + 64 > character[i].character->GetX()
					&& character[i].hp > 0)
				{
					if (character[i].chara == 5)
					{
						if (character[i].direction == 1)
						{
							PlaySoundMem(shield_se, DX_PLAYTYPE_BACK, FALSE);
							character[i].hp_shield -= 3;
						}
						else
						{
							PlaySoundMem(damage_se, DX_PLAYTYPE_BACK, FALSE);
							character[i].hp -= 3;
						}
					}
					else
					{
						PlaySoundMem(damage_se, DX_PLAYTYPE_BACK, FALSE);
						character[i].hp -= 3;
					}
				}
				break;
			default:
				break;
			}
		}
	}

	// 3P
	// 剣のとき
	if (character[2].chara == 1
		&& playmode >= 1)
	{
		if ((KeyData::Get(KEY_INPUT_J) == 1
			|| character[2].character->GetRBbutton() == 1)
			&& character[2].knifeframe < -60)
		{
			PlaySoundMem(knife_se, DX_PLAYTYPE_BACK, FALSE);
			character[2].knifeframe = 10;
		}
		else
		{
			if (character[2].knifeframe > -65)
			{
				character[2].knifeframe--;
			}
		}
	}
	if (character[2].knifeframe == 5
		&& playmode >= 1)
	{
		for (int i = 0; i != playernum; ++i)
		{
			if (i == 2)
			{
				continue;
			}
			switch (character[2].direction)
			{
			case 0:	// 右
				if (character[2].character->GetX() + 48 + 64 >= character[i].character->GetX()
					&& character[2].character->GetX() + 64 <= character[i].character->GetX()
					&& character[2].character->GetY() < character[i].character->GetY() + 64
					&& character[2].character->GetY() + 64 > character[i].character->GetY()
					&& character[i].hp > 0)
				{
					if (character[i].chara == 5)
					{
						if (character[i].direction == 2)
						{
							PlaySoundMem(shield_se, DX_PLAYTYPE_BACK, FALSE);
							character[i].hp_shield -= 3;
						}
						else
						{
							PlaySoundMem(damage_se, DX_PLAYTYPE_BACK, FALSE);
							character[i].hp -= 3;
						}
					}
					else
					{
						PlaySoundMem(damage_se, DX_PLAYTYPE_BACK, FALSE);
						character[i].hp -= 3;
					}
				}
				break;
			case 1:	// 下
				if (character[2].character->GetY() + 48 + 64 >= character[i].character->GetY()
					&& character[2].character->GetY() + 64 <= character[i].character->GetY()
					&& character[2].character->GetX() < character[i].character->GetX() + 64
					&& character[2].character->GetX() + 64 > character[i].character->GetX()
					&& character[i].hp > 0)
				{
					if (character[i].chara == 5)
					{
						if (character[i].direction == 3)
						{
							PlaySoundMem(shield_se, DX_PLAYTYPE_BACK, FALSE);
							character[i].hp_shield -= 3;
						}
						else
						{
							PlaySoundMem(damage_se, DX_PLAYTYPE_BACK, FALSE);
							character[i].hp -= 3;
						}
					}
					else
					{
						PlaySoundMem(damage_se, DX_PLAYTYPE_BACK, FALSE);
						character[i].hp -= 3;
					}
				}
				break;
			case 2:	// 左
				if (character[2].character->GetX() - 48 <= character[i].character->GetX() + 64
					&& character[2].character->GetX() >= character[i].character->GetX() + 64
					&& character[2].character->GetY() < character[i].character->GetY() + 64
					&& character[2].character->GetY() + 64 > character[i].character->GetY()
					&& character[i].hp > 0)
				{
					if (character[i].chara == 5)
					{
						if (character[i].direction == 0)
						{
							PlaySoundMem(shield_se, DX_PLAYTYPE_BACK, FALSE);
							character[i].hp_shield -= 3;
						}
						else
						{
							PlaySoundMem(damage_se, DX_PLAYTYPE_BACK, FALSE);
							character[i].hp -= 3;
						}
					}
					else
					{
						PlaySoundMem(damage_se, DX_PLAYTYPE_BACK, FALSE);
						character[i].hp -= 3;
					}
				}
				break;
			case 3:	// 上
				if (character[2].character->GetY() - 48 <= character[i].character->GetY() + 64
					&& character[2].character->GetY() >= character[i].character->GetY() + 64
					&& character[2].character->GetX() < character[i].character->GetX() + 64
					&& character[2].character->GetX() + 64 > character[i].character->GetX()
					&& character[i].hp > 0)
				{
					if (character[i].chara == 5)
					{
						if (character[i].direction == 1)
						{
							PlaySoundMem(shield_se, DX_PLAYTYPE_BACK, FALSE);
							character[i].hp_shield -= 3;
						}
						else
						{
							PlaySoundMem(damage_se, DX_PLAYTYPE_BACK, FALSE);
							character[i].hp -= 3;
						}
					}
					else
					{
						PlaySoundMem(damage_se, DX_PLAYTYPE_BACK, FALSE);
						character[i].hp -= 3;
					}
				}
				break;
			default:
				break;
			}
		}
	}

	// 4P
	// 剣のとき
	if (character[3].chara == 1
		&& playmode == 2)
	{
		if ((KeyData::Get(KEY_INPUT_K) == 1
			|| character[3].character->GetRBbutton() == 1)
			&& character[3].knifeframe < -60)
		{
			PlaySoundMem(knife_se, DX_PLAYTYPE_BACK, FALSE);
			character[3].knifeframe = 10;
		}
		else
		{
			if (character[3].knifeframe > -65)
			{
				character[3].knifeframe--;
			}
		}
	}
	if (character[3].knifeframe == 5
		&& playmode == 2)
	{
		for (int i = 0; i != playernum - 1; ++i)
		{
			switch (character[3].direction)
			{
			case 0:	// 右
				if (character[3].character->GetX() + 48 + 64 >= character[i].character->GetX()
					&& character[3].character->GetX() + 64 <= character[i].character->GetX()
					&& character[3].character->GetY() < character[i].character->GetY() + 64
					&& character[3].character->GetY() + 64 > character[i].character->GetY()
					&& character[i].hp > 0)
				{
					if (character[i].chara == 5)
					{
						if (character[i].direction == 2)
						{
							PlaySoundMem(shield_se, DX_PLAYTYPE_BACK, FALSE);
							character[i].hp_shield -= 3;
						}
						else
						{
							PlaySoundMem(damage_se, DX_PLAYTYPE_BACK, FALSE);
							character[i].hp -= 3;
						}
					}
					else
					{
						PlaySoundMem(damage_se, DX_PLAYTYPE_BACK, FALSE);
						character[i].hp -= 3;
					}
				}
				break;
			case 1:	// 下
				if (character[3].character->GetY() + 48 + 64 >= character[i].character->GetY()
					&& character[3].character->GetY() + 64 <= character[i].character->GetY()
					&& character[3].character->GetX() < character[i].character->GetX() + 64
					&& character[3].character->GetX() + 64 > character[i].character->GetX()
					&& character[i].hp > 0)
				{
					if (character[i].chara == 5)
					{
						if (character[i].direction == 3)
						{
							PlaySoundMem(shield_se, DX_PLAYTYPE_BACK, FALSE);
							character[i].hp_shield -= 3;
						}
						else
						{
							PlaySoundMem(damage_se, DX_PLAYTYPE_BACK, FALSE);
							character[i].hp -= 3;
						}
					}
					else
					{
						PlaySoundMem(damage_se, DX_PLAYTYPE_BACK, FALSE);
						character[i].hp -= 3;
					}
				}
				break;
			case 2:	// 左
				if (character[3].character->GetX() - 48 <= character[i].character->GetX() + 64
					&& character[3].character->GetX() >= character[i].character->GetX() + 64
					&& character[3].character->GetY() < character[i].character->GetY() + 64
					&& character[3].character->GetY() + 64 > character[i].character->GetY()
					&& character[i].hp > 0)
				{
					if (character[i].chara == 5)
					{
						if (character[i].direction == 0)
						{
							PlaySoundMem(shield_se, DX_PLAYTYPE_BACK, FALSE);
							character[i].hp_shield -= 3;
						}
						else
						{
							PlaySoundMem(damage_se, DX_PLAYTYPE_BACK, FALSE);
							character[i].hp -= 3;
						}
					}
					else
					{
						PlaySoundMem(damage_se, DX_PLAYTYPE_BACK, FALSE);
						character[i].hp -= 3;
					}
				}
				break;
			case 3:	// 上
				if (character[3].character->GetY() - 48 <= character[i].character->GetY() + 64
					&& character[3].character->GetY() >= character[i].character->GetY() + 64
					&& character[3].character->GetX() < character[i].character->GetX() + 64
					&& character[3].character->GetX() + 64 > character[i].character->GetX()
					&& character[i].hp > 0)
				{
					if (character[i].chara == 5)
					{
						if (character[i].direction == 1)
						{
							PlaySoundMem(shield_se, DX_PLAYTYPE_BACK, FALSE);
							character[i].hp_shield -= 3;
						}
						else
						{
							PlaySoundMem(damage_se, DX_PLAYTYPE_BACK, FALSE);
							character[i].hp -= 3;
						}
					}
					else
					{
						PlaySoundMem(damage_se, DX_PLAYTYPE_BACK, FALSE);
						character[i].hp -= 3;
					}
				}
				break;
			default:
				break;
			}
		}
	}
}

// 炎に関して
void CharacterManager::FlameProcess()
{
	// character_flameのときの炎生成
	for (int i = 0; i != playernum; ++i)
	{
		if ((KeyData::Get(KEY_INPUT_G) == 1
			|| character[i].character->GetRBbutton() == 1)
			&& character[i].chara == 3)
		{
			character[i].character->tamanum--;
			flame.push_back(new Flame(character[i].x, character[i].y, character[i].direction));
			if (character[i].character->tamanum <= 0)
			{
				character[i].dropID = 12;
				Change(character, i + 1);
			}
		}
	}

	// 炎
	for (int i = 0, m = (int)flame.size(); i != m; ++i)
	{
		if (flame[i]->GetX() < 64
			|| flame[i]->GetX() > 1920 - 128
			|| flame[i]->GetY() < 64
			|| flame[i]->GetY() > 1080 - 128)
		{
			flame[i]->wallhit = true;
		}
		// map
		for (int k = 0; k != 2; ++k)
		{
			for (int j = 0; j != 2; ++j)
			{
				if (map->GetMapData(flame[i]->GetX() + (k * (64 - 48)), flame[i]->GetY() + (j * (64 - 48))) == 10)
				{
					flame[i]->wallhit = true;
				}
			}
		}
		for (int j = 0, n = (int)obstacle.size(); j != n; ++j)
		{
			if (flame[i]->GetX() < obstacle[j]->GetX() + 64 + 5
				&& flame[i]->GetX() + 16 - 5 > obstacle[j]->GetX()
				&& flame[i]->GetY() < obstacle[j]->GetY() + 64 + 5
				&& flame[i]->GetY() + 16 - 5 > obstacle[j]->GetY()
				&& obstacle[j]->hitflag == false)
			{
				flame[i]->wallhit = true;
			}
		}
		for (int j = 0, n = (int)gunseat.size(); j != n; ++j)
		{
			if (flame[i]->GetX() < gunseat[j]->GetX() + 64
				&& flame[i]->GetX() + 64 > gunseat[j]->GetX()
				&& flame[i]->GetY() < gunseat[j]->GetY() + 64
				&& flame[i]->GetY() + 64 > gunseat[j]->GetY()
				&& gunseat[j]->hp > 0)
			{
				flame[i]->wallhit = true;
			}
		}

		// P
		for (int j = 0; j != playernum; ++j)
		{
			if (flame[i]->GetX() < character[j].character->GetX() + 64
				&& flame[i]->GetX() + 64 > character[j].character->GetX()
				&& flame[i]->GetY() < character[j].character->GetY() + 64
				&& flame[i]->GetY() + 64 > character[j].character->GetY()
				&& character[j].hp > 0)
			{
				if (flame[i]->GetFrame() < 256
					&& character[j].flamemovehit == false)
				{
					if (character[j].chara == 5)
					{
						if ((character[j].direction == 0 && flame[i]->GetDire() == 2)
							|| (character[j].direction == 1 && flame[i]->GetDire() == 3)
							|| (character[j].direction == 2 && flame[i]->GetDire() == 0)
							|| (character[j].direction == 3 && flame[i]->GetDire() == 1))
						{
							PlaySoundMem(shield_se, DX_PLAYTYPE_BACK, FALSE);
							character[j].hp_shield -= 7 * 3;
						}
						else
						{
							PlaySoundMem(damage_se, DX_PLAYTYPE_BACK, FALSE);
							character[j].hp -= 7 * 3;
						}
					}
					else
					{
						PlaySoundMem(damage_se, DX_PLAYTYPE_BACK, FALSE);
						character[j].hp -= 7 * 3;
					}
					character[j].flamemovehit = true;
				}
				else if (flame[i]->GetFrame() >= 256)
				{
					PlaySoundMem(damage_se, DX_PLAYTYPE_BACK, FALSE);
					character[j].hp -= 1 * 2;
				}
			}
		}

		if (flame[i]->GetFrame() <= 1820)
		{
			flame[i]->Move();
		}
		else
		{
			flame.erase(flame.begin() + i);
			for (int j = 0; j != playernum; ++j)
			{
				character[j].flamemovehit = false;
			}
			break;
		}
	}
}

// 爆弾に関して
void CharacterManager::BombProcess()
{
	// character_bombのときの爆弾生成
	for (int i = 0; i != playernum; ++i)
	{
		if ((KeyData::Get(KEY_INPUT_G) == 1
			|| character[i].character->GetRBbutton() == 1)
			&& character[i].chara == 11)
		{
			bomb.push_back(new Bomb(character[i].x, character[i].y, character[i].direction));
			character[i].dropID = 12;
			Change(character, i + 1);
		}
	}

	// 爆弾
	for (int i = 0, m = (int)bomb.size(); i != m; ++i)
	{
		if (bomb[i]->GetFrame() >= 40)
		{
			bomb.erase(bomb.begin() + i);
			for (int j = 0; j != playernum; ++j)
			{
				character[j].bombhit = false;
			}
			break;
		}
		// P
		for (int j = 0; j != playernum; ++j)
		{
			if (bomb[i]->GetX() < character[j].character->GetX() + 64
				&& bomb[i]->GetX() + 64 > character[j].character->GetX()
				&& bomb[i]->GetY() < character[j].character->GetY() + 64
				&& bomb[i]->GetY() + 64 > character[j].character->GetY()
				&& bomb[i]->GetFrame() < 20
				&& character[j].hp > 0
				&& character[j].bombhit == false)
			{
				if (character[j].chara == 5)
				{
					PlaySoundMem(shield_se, DX_PLAYTYPE_BACK, FALSE);
					character[j].hp_shield = 0;
				}
				else
				{
					PlaySoundMem(damage_se, DX_PLAYTYPE_BACK, FALSE);
					character[j].hp -= 25 * 3;
				}
				character[j].bombhit = true;
			}
			if (bomb[i]->GetX() - 64 < character[j].character->GetX() + 64
				&& bomb[i]->GetX() + 128 > character[j].character->GetX()
				&& bomb[i]->GetY() - 64 < character[j].character->GetY() + 64
				&& bomb[i]->GetY() + 128 > character[j].character->GetY()
				&& bomb[i]->GetFrame() >= 20
				&& character[j].hp > 0
				&& character[j].bombhit == false)
			{
				if (character[j].chara == 5)
				{
					PlaySoundMem(shield_se, DX_PLAYTYPE_BACK, FALSE);
					character[j].hp_shield = 0;
				}
				else
				{
					PlaySoundMem(damage_se, DX_PLAYTYPE_BACK, FALSE);
					character[j].hp -= 25 * 3;
				}
				character[j].bombhit = true;
			}
		}
	}
}

// 毒瓶に関して
void CharacterManager::VenomProcess()
{
	// character_venomのときの毒ガス生成
	for (int i = 0; i != playernum; ++i)
	{
		if ((KeyData::Get(KEY_INPUT_G) == 1
			|| character[i].character->GetRBbutton() == 1)
			&& character[i].chara == 4)
		{
			venom.push_back(new Venom(character[i].x, character[i].y, character[i].direction));
			character[i].dropID = 12;
			Change(character, i + 1);
		}
	}

	// 毒ガス
	for (int i = 0, m = (int)venom.size(); i != m; ++i)
	{
		if (venom[i]->GetFrame() >= 600)		// 600 / 60 = 10秒
		{
			venom.erase(venom.begin() + i);
			break;
		}
		// P
		for (int j = 0; j != playernum; ++j)
		{
			if (venom[i]->GetX() - 64 < character[j].character->GetX() + 64
				&& venom[i]->GetX() + 128 > character[j].character->GetX()
				&& venom[i]->GetY() - 64 < character[j].character->GetY() + 64
				&& venom[i]->GetY() + 128 > character[j].character->GetY())
			{
				character[j].venomflag = true;
			}
		}
	}
	for (int i = 0; i != playernum; ++i)
	{
		if (character[i].venomflag == true
			&& character[i].hp > 0)
		{
			character[i].venomframe++;
			if (character[i].venomframe % 10 == 0 || character[i].venomframe == 1)
			{
				PlaySoundMem(damage_se, DX_PLAYTYPE_BACK, FALSE);
				character[i].hp -= 3;
			}
		}
		if (character[i].venomframe >= 100)
		{
			character[i].venomflag = false;
			character[i].venomframe = 0;
		}
	}
}

// 銃座に関して
void CharacterManager::GunSeatProcess()
{
	// character_gunseatのときに銃座の生成
	for (int i = 0; i != playernum; ++i)
	{
		if ((KeyData::Get(KEY_INPUT_G) == 1
			|| character[i].character->GetRBbutton() == 1)
			&& character[i].chara == 8)
		{
			gunseat.push_back(new Gun_Seat(character[i].x, character[i].y, character[i].direction));
			character[i].dropID = 12;
			Change(character, i + 1);
		}
	}

	// 銃座の動作
	for (int i = 0, m = (int)gunseat.size(); i != m; ++i)
	{
		if (gunseat[i]->hp > 0)
		{
			gunseat[i]->Do();
		}
		else
		{
			PlaySoundMem(gunseatend_se, DX_PLAYTYPE_BACK, TRUE);
			gunseat.erase(gunseat.begin() + i);
			break;
		}
	}
}

// 人形に関して
void CharacterManager::DollProcess()
{
	// 1P
	// character_dollのときに人形の生成
	if ((KeyData::Get(KEY_INPUT_G) == 1
		|| character[0].character->GetRBbutton() == 1)
		&& character[0].chara == 10)
	{
		if (playmode == 0)
		{
			doll.push_back(new Doll(character[0].x, character[0].y, character[0].direction, character[1].x, character[1].y, 2));		// 今は二人だからすぐに指定している、３人以上ならここをif文で位置が近い人を追いかけるようにして
		}
		else if (playmode == 1)
		{
			// 内積
			if ((((character[0].x - character[1].x) * (character[0].x - character[1].x)) + ((character[0].y - character[1].y) * (character[0].y - character[1].y)))
				>= (((character[0].x - character[2].x) * (character[0].x - character[2].x)) + ((character[0].y - character[2].y) * (character[0].y - character[2].y))))
			{
				// 3Pの内積が小さい
				doll.push_back(new Doll(character[0].x, character[0].y, character[0].direction, character[2].x, character[2].y, 3));
			}
			else
			{
				// 2Pの内積が小さい
				doll.push_back(new Doll(character[0].x, character[0].y, character[0].direction, character[1].x, character[1].y, 2));
			}
		}
		else if (playmode == 2)
		{
			if ((((character[0].x - character[1].x) * (character[0].x - character[1].x)) + ((character[0].y - character[1].y) * (character[0].y - character[1].y)))
				>= (((character[0].x - character[2].x) * (character[0].x - character[2].x)) + ((character[0].y - character[2].y) * (character[0].y - character[2].y))))
			{
				// 3Pの内積が小さい
				if ((((character[0].x - character[2].x) * (character[0].x - character[2].x)) + ((character[0].y - character[2].y) * (character[0].y - character[2].y)))
					>= (((character[0].x - character[3].x) * (character[0].x - character[3].x)) + ((character[0].y - character[3].y) * (character[0].y - character[3].y))))
				{
					// 4Pの内積が小さい
					doll.push_back(new Doll(character[0].x, character[0].y, character[0].direction, character[3].x, character[3].y, 4));
				}
				else
				{
					// 3Pの内積が小さい
					doll.push_back(new Doll(character[0].x, character[0].y, character[0].direction, character[2].x, character[2].y, 3));
				}
			}
			else
			{
				// 2Pの内積が小さい
				if ((((character[0].x - character[1].x) * (character[0].x - character[1].x)) + ((character[0].y - character[1].y) * (character[0].y - character[1].y)))
					>= (((character[0].x - character[3].x) * (character[0].x - character[3].x)) + ((character[0].y - character[3].y) * (character[0].y - character[3].y))))
				{
					// 4Pの内積が小さい
					doll.push_back(new Doll(character[0].x, character[0].y, character[0].direction, character[3].x, character[3].y, 4));
				}
				else
				{
					// 2Pの内積が小さい
					doll.push_back(new Doll(character[0].x, character[0].y, character[0].direction, character[1].x, character[1].y, 2));
				}
			}
		}
		character[0].dropID = 12;
		Change(character, 1);
	}

	// 2P
	// character_dollのときに人形の生成
	if ((KeyData::Get(KEY_INPUT_H) == 1
		|| character[1].character->GetRBbutton() == 1)
		&& character[1].chara == 10)
	{
		if (playmode == 0)
		{
			doll.push_back(new Doll(character[1].x, character[1].y, character[1].direction, character[0].x, character[0].y, 1));		// 今は二人だからすぐに指定している、３人以上ならここをif文で位置が近い人を追いかけるようにして
		}
		else if (playmode == 1)
		{
			// 内積
			if ((((character[1].x - character[0].x) * (character[1].x - character[0].x)) + ((character[1].y - character[0].y) * (character[1].y - character[0].y)))
				>= (((character[1].x - character[2].x) * (character[1].x - character[2].x)) + ((character[1].y - character[2].y) * (character[1].y - character[2].y))))
			{
				// 3Pの内積が小さい
				doll.push_back(new Doll(character[1].x, character[1].y, character[1].direction, character[2].x, character[2].y, 3));
			}
			else
			{
				// 1Pの内積が小さい
				doll.push_back(new Doll(character[1].x, character[1].y, character[1].direction, character[0].x, character[0].y, 1));
			}
		}
		else if (playmode == 2)
		{
			if ((((character[1].x - character[0].x) * (character[1].x - character[0].x)) + ((character[1].y - character[0].y) * (character[1].y - character[0].y)))
				>= (((character[1].x - character[2].x) * (character[1].x - character[2].x)) + ((character[1].y - character[2].y) * (character[1].y - character[2].y))))
			{
				// 3Pの内積が小さい
				if ((((character[1].x - character[2].x) * (character[1].x - character[2].x)) + ((character[1].y - character[2].y) * (character[1].y - character[2].y)))
					>= (((character[1].x - character[3].x) * (character[1].x - character[3].x)) + ((character[1].y - character[3].y) * (character[1].y - character[3].y))))
				{
					// 4Pの内積が小さい
					doll.push_back(new Doll(character[1].x, character[1].y, character[1].direction, character[3].x, character[3].y, 4));
				}
				else
				{
					// 3Pの内積が小さい
					doll.push_back(new Doll(character[1].x, character[1].y, character[1].direction, character[2].x, character[2].y, 3));
				}
			}
			else
			{
				// 1Pの内積が小さい
				if ((((character[1].x - character[0].x) * (character[1].x - character[0].x)) + ((character[1].y - character[0].y) * (character[1].y - character[0].y)))
					>= (((character[1].x - character[3].x) * (character[1].x - character[3].x)) + ((character[1].y - character[3].y) * (character[1].y - character[3].y))))
				{
					// 4Pの内積が小さい
					doll.push_back(new Doll(character[1].x, character[1].y, character[1].direction, character[3].x, character[3].y, 4));
				}
				else
				{
					// 1Pの内積が小さい
					doll.push_back(new Doll(character[1].x, character[1].y, character[1].direction, character[0].x, character[0].y, 1));
				}
			}
		}
		character[1].dropID = 12;
		Change(character, 2);
	}

	// 3P
	// character_dollのときに人形の生成
	if ((KeyData::Get(KEY_INPUT_J) == 1
		|| character[2].character->GetRBbutton() == 1)
		&& character[2].chara == 10
		&& playmode >= 1)
	{
		if (playmode == 1)
		{
			// 内積
			if ((((character[2].x - character[0].x) * (character[2].x - character[0].x)) + ((character[2].y - character[0].y) * (character[2].y - character[0].y)))
				>= (((character[2].x - character[1].x) * (character[2].x - character[1].x)) + ((character[2].y - character[1].y) * (character[2].y - character[1].y))))
			{
				// 2Pの内積が小さい
				doll.push_back(new Doll(character[2].x, character[2].y, character[2].direction, character[1].x, character[1].y, 2));
			}
			else
			{
				// 1Pの内積が小さい
				doll.push_back(new Doll(character[2].x, character[2].y, character[2].direction, character[0].x, character[0].y, 1));
			}
		}
		else if (playmode == 2)
		{
			if ((((character[2].x - character[0].x) * (character[2].x - character[0].x)) + ((character[2].y - character[0].y) * (character[2].y - character[0].y)))
				>= (((character[2].x - character[1].x) * (character[2].x - character[1].x)) + ((character[2].y - character[1].y) * (character[2].y - character[1].y))))
			{
				// 2Pの内積が小さい
				if ((((character[2].x - character[1].x) * (character[2].x - character[1].x)) + ((character[2].y - character[1].y) * (character[2].y - character[1].y)))
					>= (((character[2].x - character[3].x) * (character[2].x - character[3].x)) + ((character[2].y - character[3].y) * (character[2].y - character[3].y))))
				{
					// 4Pの内積が小さい
					doll.push_back(new Doll(character[2].x, character[2].y, character[2].direction, character[3].x, character[3].y, 4));
				}
				else
				{
					// 2Pの内積が小さい
					doll.push_back(new Doll(character[2].x, character[2].y, character[2].direction, character[1].x, character[1].y, 2));
				}
			}
			else
			{
				// 1Pの内積が小さい
				if ((((character[2].x - character[0].x) * (character[2].x - character[0].x)) + ((character[2].y - character[0].y) * (character[2].y - character[0].y)))
					>= (((character[2].x - character[3].x) * (character[2].x - character[3].x)) + ((character[2].y - character[3].y) * (character[2].y - character[3].y))))
				{
					// 4Pの内積が小さい
					doll.push_back(new Doll(character[2].x, character[2].y, character[2].direction, character[3].x, character[3].y, 4));
				}
				else
				{
					// 1Pの内積が小さい
					doll.push_back(new Doll(character[2].x, character[2].y, character[2].direction, character[0].x, character[0].y, 1));
				}
			}
		}
		character[2].dropID = 12;
		Change(character, 3);
	}

	// 4P
	// character_dollのときに人形の生成
	if ((KeyData::Get(KEY_INPUT_K) == 1
		|| character[3].character->GetRBbutton() == 1)
		&& character[3].chara == 10
		&& playmode == 2)
	{
		if ((((character[3].x - character[0].x) * (character[3].x - character[0].x)) + ((character[3].y - character[0].y) * (character[3].y - character[0].y)))
			>= (((character[3].x - character[1].x) * (character[3].x - character[1].x)) + ((character[3].y - character[1].y) * (character[3].y - character[1].y))))
		{
			// 2Pの内積が小さい
			if ((((character[3].x - character[1].x) * (character[3].x - character[1].x)) + ((character[3].y - character[1].y) * (character[3].y - character[1].y)))
				>= (((character[3].x - character[2].x) * (character[3].x - character[2].x)) + ((character[3].y - character[2].y) * (character[3].y - character[2].y))))
			{
				// 3Pの内積が小さい
				doll.push_back(new Doll(character[3].x, character[3].y, character[3].direction, character[2].x, character[2].y, 3));
			}
			else
			{
				// 2Pの内積が小さい
				doll.push_back(new Doll(character[3].x, character[3].y, character[3].direction, character[1].x, character[1].y, 2));
			}
		}
		else
		{
			// 1Pの内積が小さい
			if ((((character[3].x - character[0].x) * (character[3].x - character[0].x)) + ((character[3].y - character[0].y) * (character[3].y - character[0].y)))
				>= (((character[3].x - character[2].x) * (character[3].x - character[2].x)) + ((character[3].y - character[2].y) * (character[3].y - character[2].y))))
			{
				// 3Pの内積が小さい
				doll.push_back(new Doll(character[3].x, character[3].y, character[3].direction, character[2].x, character[2].y, 3));
			}
			else
			{
				// 1Pの内積が小さい
				doll.push_back(new Doll(character[3].x, character[3].y, character[3].direction, character[0].x, character[0].y, 1));
			}
		}
		character[3].dropID = 12;
		Change(character, 4);
	}

	// 人形の動き
	for (int i = 0, m = (int)doll.size(); i != m; ++i)
	{
		if (doll[i]->hp > 0)
		{
			doll[i]->Move();
			if (doll[i]->GetTargetP() == 1)
			{
				doll[i]->SetXY(character[0].x, character[0].y);
			}
			else if (doll[i]->GetTargetP() == 2)
			{
				doll[i]->SetXY(character[1].x, character[1].y);
			}
			else if (doll[i]->GetTargetP() == 3)
			{
				doll[i]->SetXY(character[2].x, character[2].y);
			}
			else if (doll[i]->GetTargetP() == 4)
			{
				doll[i]->SetXY(character[3].x, character[3].y);
			}
			PlaySoundMem(doll_se, DX_PLAYTYPE_LOOP, FALSE);
		}
		else
		{
			StopSoundMem(doll_se);
			doll.erase(doll.begin() + i);
			break;
		}
		if (doll[i]->GetLimit() < 0)
		{
			StopSoundMem(doll_se);
			doll.erase(doll.begin() + i);
			break;
		}
	}
	// 人形位置修正
	for (int i = 0, m = (int)doll.size(); i != m; ++i)
	{
		for (int j = 0, n = (int)obstacle.size(); j != n; ++j)
		{
			if (doll[i]->GetX() < obstacle[j]->GetX() + 64
				&& doll[i]->GetX() + 64 > obstacle[j]->GetX()
				&& doll[i]->GetY() < obstacle[j]->GetY() + 64
				&& doll[i]->GetY() + 64 > obstacle[j]->GetY()
				&& obstacle[j]->GetBrokenFlag() == false)
			{
				doll[i]->SetDire();
			}
		}
		// map
		for (int k = 0; k != 2; ++k)
		{
			for (int j = 0; j != 2; ++j)
			{
				if (map->GetMapData(doll[i]->GetX() + (k * (64 - 32)), doll[i]->GetY() + (j * (64 - 32))) == 10)
				{
					doll[i]->SetDire();
				}
			}
		}
	}
	// 人形の攻撃
	for (int i = 0, m = (int)doll.size(); i != m; ++i)
	{
		// 人
		for (int j = 0; j != playernum; ++j)
		{
			if (doll[i]->GetX() < character[j].character->GetX() + 64
				&& doll[i]->GetX() + 64 > character[j].character->GetX()
				&& doll[i]->GetY() < character[j].character->GetY() + 64
				&& doll[i]->GetY() + 64 > character[j].character->GetY()
				&& character[j].hp > 0)
			{
				doll[i]->hit = true;
				if (doll[i]->GetAttack() == true)
				{
					PlaySoundMem(damage_se, DX_PLAYTYPE_BACK, FALSE);
					character[j].hp -= 1 * 4;
				}
			}
		}
	}
}

// トラバサミに関して
void CharacterManager::TraversalProcess()
{
	// トラバサミの生成
	for (int i = 0; i != playernum; ++i)
	{
		if ((KeyData::Get(KEY_INPUT_G) == 1
			|| character[i].character->GetRBbutton() == 1)
			&& character[i].chara == 2)
		{
			traversal.push_back(new Traversal(character[i].x, character[i].y, character[i].direction));
			character[i].dropID = 12;
			Change(character, i + 1);
		}
	}

	// トラバサミの動作
	for (int i = 0, m = (int)traversal.size(); i != m; ++i)
	{
		// P
		for (int j = 0; j != playernum; ++j)
		{
			if (traversal[i]->GetX() < character[j].character->GetX() + 32
				&& traversal[i]->GetX() + 32 > character[j].character->GetX()
				&& traversal[i]->GetY() < character[j].character->GetY() + 32
				&& traversal[i]->GetY() + 32 > character[j].character->GetY()
				&& character[j].hp > 0
				&& traversal[i]->catchflag == false)
			{
				PlaySoundMem(damage_se, DX_PLAYTYPE_BACK, FALSE);
				character[j].hp -= 8 * 3;
				traversal[i]->nP = j + 1;
				traversal[i]->catchflag = true;
				character[j].traversalcatch = true;
			}
		}

		if (traversal[i]->GetFrame() > 300)
		{
			traversal.erase(traversal.begin() + i);
			break;
		}

		for (int j = 0; j != playernum; ++j)
		{
			if (character[j].traversalcatch == true
				&& traversal[i]->nP == j + 1)
			{
				if (traversal[i]->GetFrame() > 0
					&& traversal[i]->GetFrame() < 300)
				{
					character[j].character->MoveReset();
				}
				else if (traversal[i]->GetFrame() >= 300)
				{
					character[j].traversalcatch = false;
				}
			}
		}
	}
}

// 盾に関して
void CharacterManager::ShieldProcess()
{
	for (int i = 0; i != playernum; ++i)
	{
		if (character[i].chara == 5 && character[i].hp_shield <= 0)
		{
			character[i].dropID = 12;
			Change(character, i + 1);
		}
	}
}

bool CharacterManager::GetEnd()
{
	return endflag;
}

bool CharacterManager::GetToTitle()
{
	return endtotitle;
}