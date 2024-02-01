#include "GameMainScene.h"
#include "../Object/RankingData.h"
#include "DxLib.h"
#include <math.h>

GameMainScene::GameMainScene() :high_score(0),back_ground(NULL),
barrier_image(NULL),
                                     mileage(0),player(nullptr),
