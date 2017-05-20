#pragma once
#include "GameObject.h"
class Character:public GameObject
{
public:
	float movementSpeed;
	float colliderRadius;
	int health;

	Character();
	~Character();
	void Draw();
	void Update(int time);

	void MoveRight();
	void MoveLeft();
	void MoveForward();
	void MoveBackward();
};

