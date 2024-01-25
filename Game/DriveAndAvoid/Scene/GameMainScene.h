#pragma once

#include "SceneBase.h"
#include "../object/Player.h"
#include "../Object/Enemy.h"

class GameMainScene:public SceneBase
{
private:
	int high_score;       //�n�C�X�R�A
	int back_ground;      //�w�i�摜
	int barrier_image;    //�o���A�摜
	int mikeage;          //���s����
	int enemy_image[3];   //�G�摜
	int enemy_count[3];   //�ʂ�߂����G�J�E���g
	player* player;       //�v���C���[
	Enemy** enemy;        //�G

public:
	GameMainScene();
	virtual ~GameMainScene();
	virtual eSceneType Update() override;
	virtual void Draw() const override;
	virtual void Finalize() override;

	virtual eSceneType GetNowScene() const override;

private:
	//�n�C�X�R�A�ǂݍ���
	void ReadHighScene();
	//�����蔻��
	bool IsHitCheck(Player* p, Enemy* e);

};

