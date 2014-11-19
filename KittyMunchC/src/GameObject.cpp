// Copyright (c) 1984, 2014 Wayne Beaton
// All rights reserved, distributed under the terms of the Eclipse Public License 1.0.

#include "GameObject.h"
#include <math.h>

GameObject::GameObject(short x, short y) : x(x), y(y) {
}

GameObject::~GameObject() {

}

void GameObject::tick() {
}

void GameObject::draw(cairo_t *cr) {
}
