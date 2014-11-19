// Copyright (c) 1984, 2014 Wayne Beaton
// All rights reserved, distributed under the terms of the Eclipse Public License 1.0.

#ifndef KITTYMUNCHC_SRC_BALL_H_
#define KITTYMUNCHC_SRC_BALL_H_

#include <cairo.h>
#include <gtk/gtk.h>

#include "GameObject.h"

class Ball : public GameObject {
	short dx, dy;
	short left, top, right, bottom;
public:
	Ball(short x, short y);
	void setVelocity(short dx, short dy);
	void setBounds(short left, short top, short right, short bottom);

	using GameObject::tick;
	virtual void tick();

	using GameObject::draw;
	virtual void draw(cairo_t *cr);
};

#endif /* KITTYMUNCHC_SRC_BALL_H_ */
