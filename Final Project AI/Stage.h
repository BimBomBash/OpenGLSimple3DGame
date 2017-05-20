#pragma once
#include "GameObject.h"
class Stage:public GameObject
{
public:
	float radius;

	Stage();
	~Stage();
	void Draw();
	void Update(int time);
};

