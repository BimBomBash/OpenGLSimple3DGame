#include "stdafx.h"
#include <GL\glew.h>
#include <SDL.h>
#include <iostream>
#include <string.h>
#include "Window.h"
#include "Stage.h"


Stage::Stage()
{
	object = LoadObject("Stage.obj");
	transform = new Transform();
}


Stage::~Stage()
{
}

void Stage::Draw()
{
	glCallList(object);
}

void Stage::Update(int time)
{
	Draw();
}
