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
		for(int i =0;)
	}
}