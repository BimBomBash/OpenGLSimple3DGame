// Final Project AI.cpp : Defines the entry point for the console application.
//
#define PI 3.14159265359
#include "stdafx.h"
#include <GL\glew.h>
#include <SDL.h>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <fstream>
#include <time.h>
#include "GameObject.h"
#include "Character.h"
#include "Bullet.h"
#include "Stage.h"
#include "HealthBar.h"
#include "Window.h"
#include "MainGame.h"

float rTri = 0.1;
float rQuad = 0.1;


int main(int argc, char ** argv)
{
	Window *window;
	window = new Window("Final Project AI", 900, 450);
	SDL_Event sdlEvent;
	MainGame *mainGame;
	int cube;
	time_t start = clock();

	if (window->initiated) {
		glEnable(GL_LIGHTING);
		glEnable(GL_LIGHT0);
		float col[] = { 1.0,1.0,1.0,1.0 };
		glLightfv(GL_LIGHT0, GL_DIFFUSE, col);
		mainGame = new MainGame(window);
		mainGame->Start();
		while (true) {
			int time = (int)difftime(clock(),start);
			mainGame->Update(time);
		}
	}
    return 0;
}

