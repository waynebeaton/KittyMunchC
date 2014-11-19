// Copyright (c) 1984, 2014 Wayne Beaton
// All rights reserved, distributed under the terms of the Eclipse Public License 1.0.

#include "Arm.h"
#include <cstdlib>
#include <cmath>
#include <algorithm>

Arm::Arm(short homeX, short homeY, short size) : GameObject(homeX, homeY-size), homeX(homeX), homeY(homeY), size(size) {
	shoulderX = homeX;
	shoulderY = homeY;
	elbowX = 0;
	elbowY = 0;
	x = shoulderX;
	y = shoulderY - size;
	computeElbow();
}

Arm::~Arm() {
	// TODO Auto-generated destructor stub
}

void Arm::tick() {
//	x += rand() % 21 - 10;
//	y += rand() % 11 - 5;
//	computeElbow();
}

void Arm::draw(cairo_t *cr) {
	cairo_set_line_width(cr, 9);
	cairo_set_source_rgb(cr, 0.69, 0.19, 0);
	cairo_move_to(cr, shoulderX, shoulderY);
	cairo_line_to(cr, elbowX, elbowY);
	cairo_line_to(cr, x, y);

	short finger = size / 5;
	cairo_line_to(cr, x, y-finger);
	cairo_move_to(cr, x, y);
	cairo_line_to(cr, x-(finger/2), y-finger);
	cairo_move_to(cr, x, y);
	cairo_line_to(cr, x+(finger/2), y-finger);
	cairo_stroke(cr);
}

void Arm::computeElbow() {
	if (y > (homeY-size)) shoulderY = y + size;
	else shoulderY = homeY;

	double h = sqrt(pow(x-homeX, 2) + pow(homeY-y, 2));
	double max = size * 32 / 17;
	if (homeY - y > max) y = homeY - max;

	if (h > max)
		shoulderX = x + (x < homeX ? 1 : -1) * sqrt(pow(max,2)-pow(y-shoulderY,2));
	else shoulderX = homeX;

	double a2 = pow(x-shoulderX, 2) + pow(shoulderY-y, 2);
	double a = std::min(sqrt(a2),2.0*size);

	double A = acos(a / (2 * size));
	double cosB = x == shoulderX ? 0 : (a2+pow(x-shoulderX,2)-pow(y-shoulderY,2))/(2*a*(x-shoulderX));
	double B = acos(cosB);
	double C = B - A;

	elbowX = shoulderX + (size * cos(C));
	elbowY = shoulderY - (size * sin(C));
}

void Arm::moveTo(short x, short y) {
	this->x = x;
	this->y = y;

	computeElbow();
}
