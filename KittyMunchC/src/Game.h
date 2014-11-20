// Copyright (c) 1984, 2014 Wayne Beaton
// All rights reserved, distributed under the terms of the Eclipse Public License 1.0.

#ifndef KITTYMUNCHC_SRC_GAME_H_
#define KITTYMUNCHC_SRC_GAME_H_

#include <cairo.h>
#include <gtk/gtk.h>

#include <iostream>
#include <list>
#include <memory>

#include "GameObject.h"
#include "Arm.h"

typedef std::list<GameObject*> GameObjectList;

class Game {
	short width, height;
	GameObjectList *objects;
	Arm *arm;
public:
	Game(short width, short height);
	virtual ~Game();
	void tick();
	void draw(cairo_t *cr);
	bool isRunning();
	void mouseMoved(short x, short y);
	void buttonClicked();
};

#endif /* KITTYMUNCHC_SRC_GAME_H_ */
