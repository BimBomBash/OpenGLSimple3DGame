#include "stdafx.h"
#include <GL\glew.h>
#include <SDL.h>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <fstream>
#include "GameObject.h"

int GameObject::LoadObject(const char* _filename) {
	std::vector <std::string*> coord;
	std::vector <Coordinate*> vertex;
	std::vector <Face*> faces;
	std::vector <Coordinate*> normals;

	std::ifstream in(_filename);
	if (!in.is_open()) {
		std::cout << "CANT OPEN FILE";
		return -1;
	}

	char buf[256];
	while (!in.eof()) {
		in.getline(buf, 256);
		coord.push_back(new std::string(buf));
	}

	for (int i = 0; i < coord.size(); i++) {
		if ((*coord[i])[0] == '#') continue;
		else if ((*coord[i])[0] == 'v' && (*coord[i])[1] == ' ') {
			float tempx, tempy, tempz;
			sscanf_s(coord[i]->c_str(), "v %f %f %f", &tempx, &tempy, &tempz);
			vertex.push_back(new Coordinate(tempx, tempy, tempz));
		}
		else if ((*coord[i])[0] == 'v' && (*coord[i])[1] == 'n') {
			float tempx, tempy, tempz;
			sscanf_s(coord[i]->c_str(), "vn %f %f %f", &tempx, &tempy, &tempz);
			normals.push_back(new Coordinate(tempx, tempy, tempz));
		}
		else if ((*coord[i])[0] == 'f') {
			int a, b, c, d, e;
			if (std::count(coord[i]->begin(), coord[i]->end(), ' ') == 4) {
				sscanf_s(coord[i]->c_str(), "f %d//%d %d//%d %d//%d %d//%d", &a, &b, &c, &b, &d, &b, &e, &b);
				faces.push_back(new Face(b, a, c, d, e));
			}
			else {
				sscanf_s(coord[i]->c_str(), "f %d//%d %d//%d %d//%d", &a, &b, &c, &b, &d, &b);
				faces.push_back(new Face(b, a, c, d));
			}
		}
	}

	//draw
	int num;
	num = glGenLists(1);
	glNewList(num, GL_COMPILE);
	for (int i = 0; i < faces.size(); i++) {
		if (faces[i]->four) {
			glBegin(GL_QUADS);
			glNormal3f(normals[faces[i]->faceNum - 1]->x, normals[faces[i]->faceNum - 1]->y, normals[faces[i]->faceNum - 1]->z);
			glVertex3f(vertex[faces[i]->faces[0] - 1]->x, vertex[faces[i]->faces[0] - 1]->y, vertex[faces[i]->faces[0] - 1]->z);
			glVertex3f(vertex[faces[i]->faces[1] - 1]->x, vertex[faces[i]->faces[1] - 1]->y, vertex[faces[i]->faces[1] - 1]->z);
			glVertex3f(vertex[faces[i]->faces[2] - 1]->x, vertex[faces[i]->faces[2] - 1]->y, vertex[faces[i]->faces[2] - 1]->z);
			glVertex3f(vertex[faces[i]->faces[3] - 1]->x, vertex[faces[i]->faces[3] - 1]->y, vertex[faces[i]->faces[3] - 1]->z);
			glEnd();
		}
		else {
			glBegin(GL_TRIANGLES);
			glNormal3f(normals[faces[i]->faceNum - 1]->x, normals[faces[i]->faceNum - 1]->y, normals[faces[i]->faceNum - 1]->z);
			glVertex3f(vertex[faces[i]->faces[0] - 1]->x, vertex[faces[i]->faces[0] - 1]->y, vertex[faces[i]->faces[0] - 1]->z);
			glVertex3f(vertex[faces[i]->faces[1] - 1]->x, vertex[faces[i]->faces[1] - 1]->y, vertex[faces[i]->faces[1] - 1]->z);
			glVertex3f(vertex[faces[i]->faces[2] - 1]->x, vertex[faces[i]->faces[2] - 1]->y, vertex[faces[i]->faces[2] - 1]->z);
			glEnd();
		}
	}
	glEndList();

	for (int i = 0; i < coord.size(); i++) {
		delete (coord[i]);
	}
	for (int i = 0; i < faces.size(); i++) {
		delete (faces[i]);
	}
	for (int i = 0; i < normals.size(); i++) {
		delete (normals[i]);
	}
	for (int i = 0; i < vertex.size(); i++) {
		delete (vertex[i]);
	}

	return num;
}

void GameObject::Draw()
{
}

void GameObject::Update()
{
}

GameObject::GameObject()
{
}


GameObject::~GameObject()
{
}
