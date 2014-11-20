// Copyright (c) 1984, 2014 Wayne Beaton
// All rights reserved, distributed under the terms of the Eclipse Public License 1.0.

#include "Game.h"
//#include "GameObject.h"
#include "Ball.h"

#include <iostream>
#include <list>
#include <cstdlib>

Game::Game(short width, short height) : width(width), height(height) {
	objects = new GameObjectList();
	for(int count=0;count<50;count++) {
		Ball *object = new Ball(rand() % width, rand() % height);
		object->setVelocity(rand() % 20 - 10, rand() % 20 - 10);
		object->setBounds(0, 0, width, height);
		objects->push_back(object);
	}
	arm = new Arm(500, 550, 150);
}

Game::~Game() {
	delete objects;
	delete arm;
}

void Game::tick() {
	 for (GameObjectList::iterator object = objects->begin(); object != objects->end(); ++object)
		 (*object)->tick();
	 arm->tick();
}

void Game::draw(cairo_t *cr) {
	 for (GameObjectList::iterator object = objects->begin(); object != objects->end(); ++object)
		 if ((*object)->isActive()) (*object)->draw(cr);
	 arm->draw(cr);
}

bool Game::isRunning() {
	return TRUE;
}

void Game::mouseMoved(short x, short y) {
	arm->moveTo(x, y);
}

void Game::buttonClicked() {
	 for (GameObjectList::iterator object = objects->begin(); object != objects->end(); ++object)
		 if ((*object)->touches(arm->x, arm->y)) (*object)->destroy();
}
