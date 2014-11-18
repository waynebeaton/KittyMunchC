// Copyright (c) 1984, 2014 Wayne Beaton
// All rights reserved, distributed under the terms of the Eclipse Public License 1.0.

#ifndef KITTYMUNCHC_SRC_GAMEOBJECT_H_
#define KITTYMUNCHC_SRC_GAMEOBJECT_H_

#include <cairo.h>
#include <gtk/gtk.h>

class GameObject {
	short x, y;
	short dx, dy;
	short left, top, bottom, right;
public:
	GameObject(short x, short y);
	virtual ~GameObject();
	void setVelocity(short dx, short dy);
	void setBounds(short left, short top, short right, short bottom);
	void tick();
	void draw(cairo_t *cr);
};

#endif /* KITTYMUNCHC_SRC_GAMEOBJECT_H_ */
