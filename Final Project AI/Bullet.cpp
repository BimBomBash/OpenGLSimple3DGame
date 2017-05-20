#define PI 3.14159265359

#include "stdafx.h"
#include <GL\glew.h>
#include <SDL.h>
#include <iostream>
#include <string.h>
#include <math.h>
#include <time.h>
#include "Character.h"
#include "Bullet.h"

Bullet::Bullet(Vector3 * _position, float _speed, float _rotation, int _spawnTime, Character * _target)
{

	transform = new Transform();
	transform->position->x = _position->x;
	transform->position->y = _position->y;
	transform->position->z = _position->z;

	speed = _speed;
	rotation = _rotation;
	while (rotation >= 360) rotation -= 360;
	while (rotation <= 0) rotation += 360;
	spawnTime = _spawnTime;
	target = _target;
	elapsedTime = 0;
	object = LoadObject("Bullet.obj");
}

void Bullet::Update(int time)
{
	elapsedTime = time-spawnTime;
	transform->position->x += sin(rotation* 3.14159265359 / 180)*speed;
	transform->position->z += cos(rotation*3.14159265359 / 180)*speed;
	Draw();
}


void Bullet::Draw()
{
	glPushMatrix();
	glTranslatef(transform->position->x, transform->position->y, transform->position->z);
	glRotatef(rotation, 0, 1, 0);
	glCallList(object);
	glPopMatrix();
}
