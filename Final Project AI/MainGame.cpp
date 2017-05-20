#include "stdafx.h"
#include <GL\glew.h>
#include <SDL.h>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <fstream>
#include <time.h>
#include "Window.h"
#include "Character.h"
#include "Bullet.h"
#include "Stage.h"
#include "HealthBar.h"
#include "MainGame.h"


MainGame::MainGame(Window * _window)
{
	character = new Character();
	enemy = new Character();
	stage = new Stage();
	window = _window;
}

MainGame::~MainGame()
{
}

void MainGame::Start()
{
	character->health = maxHealth;
	enemy->health = maxHealth;
	stage->transform->position = new Vector3(0, -1, 0);
	character->movementSpeed = 0.2f;
	enemy->movementSpeed = 0.2f;
	stage->radius = 12;
	bulletSpeed = 0.05f;
	bulletLifeSpan = 5;
	bullerColliderRadius = 0.3f;
	characterColliderRadius = 0.5f;
	healthBar = new HealthBar();
}

float DistanceFromStageCenter(float x, float z) {
	return (sqrtf((x * x)+(z * z)));
}

void MainGame::ProcessInput()
{
	SDL_Event event;

	const Uint8 *state = SDL_GetKeyboardState(NULL);

	//continuous-response keys
	if (state[SDL_SCANCODE_UP] || state[SDL_SCANCODE_W]) {
		std::cout << stage->radius <<" | " << DistanceFromStageCenter(character->transform->position->z - character->movementSpeed, character->transform->position->x)<<std::endl;
		if (DistanceFromStageCenter(character->transform->position->z - character->movementSpeed, character->transform->position->x)
			<= stage->radius) 
			character->MoveForward();
	}
	if (state[SDL_SCANCODE_DOWN]||state[SDL_SCANCODE_S]) {
		std::cout << stage->radius << " | " << DistanceFromStageCenter(character->transform->position->z + character->movementSpeed, character->transform->position->x) << std::endl;
		if (DistanceFromStageCenter(character->transform->position->z + character->movementSpeed, character->transform->position->x)
			<= stage->radius)
		character->MoveBackward();
	}
	if (state[SDL_SCANCODE_LEFT] || state[SDL_SCANCODE_A]) {
		if (DistanceFromStageCenter(character->transform->position->z , character->transform->position->x - character->movementSpeed)
			<= stage->radius)
		character->MoveLeft();
	}
	if (state[SDL_SCANCODE_RIGHT] || state[SDL_SCANCODE_D]) {
		if (DistanceFromStageCenter(character->transform->position->z, character->transform->position->x + character->movementSpeed)
			<= stage->radius)
		character->MoveRight();
	}
	if (state[SDL_SCANCODE_SPACE]) {
		bullet.push_back (new Bullet(character->transform->position, bulletSpeed, yPlayerRotation, elapsedTime,enemy));
	}

	while (SDL_PollEvent(&event)) {
		switch (event.type) {
		case SDL_QUIT:
			window->Close();
			break;
		case SDL_MOUSEMOTION:
			xNewMousePosition = (float)(event.motion.x - window->windowWidth / 2) / (float)(window->windowWidth / 2);
			if (xNewMousePosition - xOldMousePosition > 0) {
				yPlayerRotation+=4;
			}
			else if (xNewMousePosition-xOldMousePosition<0){
				yPlayerRotation-=4;
			}
			xOldMousePosition = xNewMousePosition;
			break;
		/*case SDL_MOUSEBUTTONDOWN:
			AddCircle();
			break;*/
		case SDL_KEYDOWN:
			break;
		}
	}
}

void MainGame::Update(int time)
{
	elapsedTime = time;
	ProcessInput();
	window->ClearWindow(); 
	healthBar->playerHealthFloat = (float)character->health / (float)maxHealth;
	healthBar->enemyHealthFloat = (float)enemy->health / (float)maxHealth;
	healthBar->Update();
	
	glLoadIdentity();
	glTranslatef(0, 5, -30);
	glRotatef(45, 1, 0, 0);

	for (int i = 0; i < bullet.size(); i++) { 
		if ((bullet[i]->transform->position->DistanceXZto(bullet[i]->target->transform->position) <= bullerColliderRadius + characterColliderRadius)) {
			bullet[i]->target->health -= 2;
			bullet.erase(bullet.begin() + i);
		}
		else if (bullet[i]->elapsedTime/CLOCKS_PER_SEC > bulletLifeSpan) bullet.erase(bullet.begin()+i);
		else bullet[i]->Update(time);
	}

	glPushMatrix();
	glTranslatef(character->transform->position->x, character->transform->position->y, character->transform->position->z);
	glRotatef(yPlayerRotation, 0, 1, 0);
	character->Update(time);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(enemy->transform->position->x, enemy->transform->position->y, enemy->transform->position->z);
	glRotatef(yEnemyRotation, 0, 1, 0);
	enemy->Update(time);
	glPopMatrix();

	glTranslatef(stage->transform->position->x, stage->transform->position->y, stage->transform->position->z);
	stage->Update(time);
	window->SwapWindow();
}

