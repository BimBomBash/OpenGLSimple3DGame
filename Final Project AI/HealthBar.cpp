#include "stdafx.h"
#include <GL\glew.h>
#include <SDL.h>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <fstream>
#include "HealthBar.h"


HealthBar::HealthBar()
{
}


HealthBar::~HealthBar()
{
}

void HealthBar::Draw()
{
	glPushMatrix();
	glLoadIdentity();
	glColor4f(1, 0, 0, 1);
	glTranslatef(-1.7f, -0.82, -2.1f);
	glBegin(GL_QUADS);
	glVertex2f(0, 0);
	glVertex2f(playerHealthFloat*width, 0);
	glVertex2f(playerHealthFloat*width, 0.1f);
	glVertex2f(0, 0.1f);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glLoadIdentity();
	glColor4f(1, 0, 0, 1);
	glTranslatef(1.7f, 0.82, -2.1f);
	glRotatef(180, 0, 0, 1);
	glBegin(GL_QUADS);
	glVertex2f(0, 0);
	glVertex2f(enemyHealthFloat*width, 0);
	glVertex2f(enemyHealthFloat*width, 0.1f);
	glVertex2f(0, 0.1f);
	glEnd();
	glPopMatrix();
}

void HealthBar::Update()
{
	Draw();
}
