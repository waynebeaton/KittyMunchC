// Copyright (c) 1984, 2014 Wayne Beaton
// All rights reserved, distributed under the terms of the Eclipse Public License 1.0.

#include "GameObject.h"
#include <math.h>

GameObject::GameObject(short x, short y) : x(x), y(y), active(TRUE) {
}

GameObject::~GameObject() {

}

void GameObject::tick() {
}

void GameObject::draw(cairo_t *cr) {
}

bool GameObject::touches(short x, short y) {
	return FALSE;
}

void GameObject::destroy() {
	active = FALSE;
}

bool GameObject::isActive() {
	return active;
}
