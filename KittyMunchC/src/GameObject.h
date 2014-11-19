// Copyright (c) 1984, 2014 Wayne Beaton
// All rights reserved, distributed under the terms of the Eclipse Public License 1.0.

#ifndef KITTYMUNCHC_SRC_GAMEOBJECT_H_
#define KITTYMUNCHC_SRC_GAMEOBJECT_H_

#include <cairo.h>
#include <gtk/gtk.h>

class GameObject {
protected:
	short x, y;
public:
	GameObject(short x, short y);
	virtual ~GameObject();
	virtual void tick();
	virtual void draw(cairo_t *cr);
};

#endif /* KITTYMUNCHC_SRC_GAMEOBJECT_H_ */
