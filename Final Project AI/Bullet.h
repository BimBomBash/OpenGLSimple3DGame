#pragma once
#include "GameObject.h"

class Bullet:public GameObject
{
public:
	int spawnTime;
	float colliderRadius;
	float elapsedTime;
	float speed, rotation, duration;
	Character *target;
	Bullet(Vector3 * _position, float _speed, float _rotation, int _spawnTime, Character * _target);
	void Update(int time);
	void Draw();
};

