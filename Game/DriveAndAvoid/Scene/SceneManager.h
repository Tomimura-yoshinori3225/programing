#pragma once
#include "SceneBase.h"

//�Œ艻����t���[�����[�g�l
#define DELTA_SECOND   (60)

//�P�t���[��������̎���(�}�C�N���b�j
#define DELTA_SECOND         (1000000/TARGET_FREAM_RATE)

//�V�[���}�l�[�W���[�N���X
class SceneManager
{
private:
	SceneBase* current_scene;         //���݃V�[�����

public:
	SceneManager();
	~SceneManager();

	void Initialize();                //����������
	void Update();                    //�X�V����
	void Finalize();                  //�I��������

privare: 
	void  Draw() const;             //�`�揈��

};

