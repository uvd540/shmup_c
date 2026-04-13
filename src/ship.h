#pragma once

#include "raylib.h"

typedef struct {
  // rendering
  Texture2D texture;
  Rectangle src_rect;
  Rectangle dst_rect;
  // movement
  Vector2 position;
  float speed;
  // collisions
  // Rectangle hitbox;
} Ship;

void ship_init(Ship *ship);
void ship_update(Ship *ship, float dt);
void ship_draw(Ship *ship);
void ship_destroy(Ship *ship);
