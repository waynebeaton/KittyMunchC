// Copyright (c) 1984, 2014 Wayne Beaton
// All rights reserved, distributed under the terms of the Eclipse Public License 1.0.

#ifndef KITTYMUNCHC_SRC_ARM_H_
#define KITTYMUNCHC_SRC_ARM_H_

#include <cairo.h>
#include <gtk/gtk.h>

#include "GameObject.h"

class Arm : public GameObject {
	short homeX, homeY;
	short shoulderX, shoulderY;
	short elbowX, elbowY;
	short size;
public:
	Arm(short homeX, short homeY, short size);
	virtual ~Arm();
	void tick();
	void draw(cairo_t *cr);
	void moveTo(short x, short y);
private:
	void computeElbow();
};

#endif /* KITTYMUNCHC_SRC_ARM_H_ */
