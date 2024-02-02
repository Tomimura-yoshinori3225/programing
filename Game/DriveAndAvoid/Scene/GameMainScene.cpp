#include "GameMainScene.h"
#include "../Object/RankingData.h"
#include "DxLib.h"
#include <math.h>

GameMainScene::GameMainScene() :high_score(0), back_ground(NULL),
barrier_image(NULL),mileage(0), player(nullptr),

enemy(nullptr)
{
	for (int i = 0; i < 3; i++)
	{
		ememy_image[i] = NULL;
		enemy_const[i] = NULL;
	}
}

//初期化処理
void GameMainScene::Initialize()
{
	//高得点値を読み込む
	ReadHIghScore();

	//画像読み込み
	back_ground = LoadGraph("Resource/images/back.dmp");
	barrier_image = LoadGraph("Reasource/images/barrier.png");
	int result = LoadDivGraph("Reasource/images/car.dmp", 3, 3, 1, 63, 120,
		enemy_image);

	//エラーチェック
	if (back_Ground == -1)
	{
		throw("Resource/image/back.dmpがありません`n");
	}
	if (result == -1)
	{
		throw("Resource/image/car.dmpがありません`n");
	}
	if (barrier_image == -1)
	{
		throw("Resource/image/barrier.pigがありません`n");
	}
	//オブジェクトの生成
	Player = new Player;
	enemy = new Enemy * [10];

	//オブジェクトの初期化
	Player->Initialize();

	for (int i = 0; i < 10; i++)
	{
		enemy[i] = nullptr;
	}
}

//更新処理
eSceneType GameMainScene::Update()
{
	//プレイヤーの更新
	Player->Update();

	//移動距離の更新
	mileage += (int)player->GetSpeed
	() + 5;

	//敵生成処理
	if (mileage / 20 % 100 == 0)
	{
		for (int i = 0; i < 10; i++)
		{
			if (enemy[i] == nullptr)
			{
				int type = GetRand(3) % 3;
				enemy[i] = new Enemy(type, enemy_image[type]);
				enemy[i]->Initialize();
				break;
			}
		}
	}
	//敵の更新と当たり判定チェック
	for (int i = 0; i < 10; i++)
	{
		if (enemy[i] != nullptr)
		{
			enemy[i]->Update(player->GetSpeed());

			//画面外に行ったら、敵を削除してスコア加算
			if (enemy[i]->GetLocation().y >= 640.0f)
			{
				enemy_count[enemy[i]->GetType()]++;
				enemy[i]->Finalize();
				delete enemy[i];
				enemy[i] = nullptr;
			}

			//当たり判定の確認
			if (IsHitCheck(player, enemy[i]))
			{
				player->SetActive(false);
				player->DecreaseHp(-50.0f);
				enemy[i]->Finalize();
				delete enemy[i];
				enemy[i] = nullptr;
			}
		}
	}

	//プレイヤーの燃料か体力が０未満なら、リザルトに遷移する
	if (player->GetFuel() < 0.0f || player->GetHp() < 0.0f)
	{
		return eSceneType::E_RESULT;
	}
	return GetNowScene();
}

//描画処理
void GameMainScene::Draw()const
{
	//背景画像の描画
	DrawGraph(0, mileage % 480 - 480, back_ground, TRUE);
	DrawGraph(0, mileage % 480, back_ground, TRUE);

	//敵の描画
	for (int i = 0; i < 10; i++)
	{
		if (enemy[i] != nullptr)
		{
			enemy[i]->Draw();
		}
	}

	//プレイヤーの描画
	player->Draw();

	//UIの描画
	DrawBox(500, 0, 640, 480, GetColor(0, 153, 0), TRUE);
	SetFotSize(16);
	DrawFormatString(510, 20, GetColor(0, 0, 0), "ハイスコア");
	DrawFormatString(560, 40, GetColor(255,255,255),"%08d",high_score);
	DrawFormatString(560, 80, GetColor(0,0,0),"避けた数");
	for (int i = 0; i < 3; i++)
	{
		DrawRotaGraph(523 + (i * 50), 120, 0.3, 0, enemy_image[i], TRUE, FALSE);
		DrawRotaGraph(510 + (i * 50), 140, GetColor(255,255,255),
			"%03d",enemy_image[i]);

	}
	DrawFormatString(510, 200, GetColor(0, 0, 0), "走行距離");
	DrawFormatString(555, 200, GetColor(255, 255, 255), "%08d", mileage / 10);
	DrawFormatString(510, 240, GetColor(0, 0, 0), "スピード");
	DrawFormatString(555, 200, GetColor(255, 255, 255), "%08.1f"
	player->GetSpeed();

	//バリア枚数の描画
}
