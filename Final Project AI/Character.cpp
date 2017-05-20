#include "stdafx.h"
#include <GL\glew.h>
#include <SDL.h>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <fstream>
#include "Character.h"


Character::Character()
{
	object = LoadObject("Character.obj");
	transform = new Transform();
}


Character::~Character()
{
}

void Character::Draw()
{  
	glCallList(object);
}

void Character::Update(int time)
{
	Draw();
}

void Character::MoveRight()
{
	transform->position->x += movementSpeed;
}

void Character::MoveLeft()
{
	transform->position->x -= movementSpeed;
}

void Character::MoveForward()
{
	transform->position->z -= movementSpeed;
}

void Character::MoveBackward()
{
	transform->position->z += movementSpeed;
}
