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

//����������
void GameMainScene::Initialize()
{
	//�����_�l��ǂݍ���
	ReadHIghScore();

	//�摜�ǂݍ���
	back_ground = LoadGraph("Resource/images/back.dmp");
	barrier_image = LoadGraph("Reasource/images/barrier.png");
	int result = LoadDivGraph("Reasource/images/car.dmp", 3, 3, 1, 63, 120,
		enemy_image);

	//�G���[�`�F�b�N
	if (back_Ground == -1)
	{
		throw("Resource/image/back.dmp������܂���`n");
	}
	if (result == -1)
	{
		throw("Resource/image/car.dmp������܂���`n");
	}
	if (barrier_image == -1)
	{
		throw("Resource/image/barrier.pig������܂���`n");
	}
	//�I�u�W�F�N�g�̐���
	Player = new Player;
	enemy = new Enemy * [10];

	//�I�u�W�F�N�g�̏�����
	Player->Initialize();

	for (int i = 0; i < 10; i++)
	{
		enemy[i] = nullptr;
	}
}

//�X�V����
eSceneType GameMainScene::Update()
{
	//�v���C���[�̍X�V
	Player->Update();

	//�ړ������̍X�V
	mileage += (int)player->GetSpeed
	() + 5;

	//�G��������
	if (mileage / 20 % 100 == 0)
	{
		for(int i =0;)
	}
}