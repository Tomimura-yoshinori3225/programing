#include "ResultScene.h"
#include "../Object/RankingData.h"
#include "../Utility/InputControl.h"
#include "DxLib.h"

ResultScene::ResultScene() :back_ground(NULL), score(0)
{
	for (int i = 0; i < 3; i++)
	{
		enemy_image[i] = NULL;
		enemy_count[i] = NULL;
	}
}

ResultScene::~ResultScene()
{

}

//����������
viod ResultScene::Initialize()
{
	//�摜�̓ǂݍ���
	back_ground = LoadGraph("Resource/images/back.bmp");
	int result = LoadDivGraph("Resource/images/car.bmp", 3, 3, 1, 63, 120,
		enemy_image);

	//�G���[�`�F�b�N
	if (back_ground == -1)
	{
		throw("Resource/images/back.bmp������܂���`n");
	}
	if (result == -1)
	{
		throw("Resource/images/car.bmp������܂���`n");
	}

	//�Q�[�����ʂ̓ǂݍ���
	ReadResultData();
}

//�X�V����
eSceneType ResultScene::Update()
{
	//B�{�^���Ń����L���O�ɑJ�ڂ���
	if (InputControl::GetButtonDown(XINPUT_BUTTON_B))
	{
		return eSceneType::E_RANKING_INPUT;
	}
	return GetNowScene();
}

//�`�揈��
void ResultScene::Draw() const
{
	//�w�i�摜��`��
	DrawGraph(0, 0, back_ground, TRUE);

	//�X�R�A���\���̈�
	DrawBox(150, 150, 490, 330, GetColor(0, 153, 0), TRUE);
	DrawBox(150, 150, 490, 330, GetColor(0, 0, 0), FALSE);

	DrawBox(500,0, 640, 480, GetColor(0, 153, 0), TRUE);

	SetFontSize(20);
	DrawString(220, 170, "�Q�[���I�[�o�[", GetColor(204, 0, 0));
	SetFontSize(16);
	DrawString(180, 200, "���s����    ",GetColor(0, 0, 0));
}
