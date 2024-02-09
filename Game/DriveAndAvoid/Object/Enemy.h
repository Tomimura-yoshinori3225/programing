#pragma once

#include "../Utility/Vector2D.h"

class Enemy
{
private:
	int type;
	int image;
	float speed;
	Vector2D location;
	Vector2D box_size;

public:
	Enemy(int type, int handle);
	~Enemy();

	void Initialize();
	void Update(float speed);
	void Draw() const;
	void Finalize();

	int GetType() const;
	Vector2D GetLocation() const;
	Vector2D GetBoxSize() const;
};
