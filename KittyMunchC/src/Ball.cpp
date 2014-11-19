// Copyright (c) 1984, 2014 Wayne Beaton
// All rights reserved, distributed under the terms of the Eclipse Public License 1.0.

#include "Ball.h"
#include <math.h>

Ball::Ball(short x, short y) : GameObject(x, y) {
	dx = 0;
	dy = 0;

	left = 0;
	top = 0;
	right = 100;
	bottom = 100;
}

void Ball::setVelocity(short x, short y) {
	dx = x;
	dy = y;
}

void Ball::setBounds(short left, short top, short right, short bottom) {
	this->left = left;
	this->top = top;
	this->right = right;
	this->bottom = bottom;
}

void Ball::tick() {
	x += dx;
	y += dy;

	if (x < left) {x = left; dx *= -1;}
	if (x > right) {x = right; dx *= -1;}
	if (y < top) {y = top; dy *= -1;}
	if (y > bottom) {y = bottom; dy *= -1;}
}

void Ball::draw(cairo_t *cr) {
	  cairo_set_line_width(cr, 9);
	  cairo_set_source_rgb(cr, 0.69, 0.19, 0);

	//  cairo_translate(cr, x, y);
	  cairo_arc(cr, x, y, 10, 0, 2 * M_PI);
	  cairo_stroke_preserve(cr);

	  cairo_set_source_rgb(cr, 0.3, 0.4, 0.6);
	  cairo_fill(cr);
}
