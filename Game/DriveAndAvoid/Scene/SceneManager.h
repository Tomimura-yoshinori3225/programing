#pragma once
#include "SceneBase.h"

//固定化するフレームレート値
#define DELTA_SECOND   (60)

//１フレーム当たりの時間(マイクロ秒）
#define DELTA_SECOND         (1000000/TARGET_FREAM_RATE)

//シーンマネージャークラス
class SceneManager
{
private:
	SceneBase* current_scene;         //現在シーン情報

public:
	SceneManager();
	~SceneManager();

	void Initialize();                //初期化処理
	void Update();                    //更新処理
	void Finalize();                  //終了時処理

privare: 
	void  Draw() const;             //描画処理

};

