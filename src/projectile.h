#pragma once

#include "raylib.h"
#include <stddef.h>

typedef struct {
  bool active;
  Vector2 position;
} Projectile;

void projectile_spawn(Projectile *projectiles, Vector2 position);
void projectiles_update(Projectile *projectiles, float dt);
void projectiles_draw(Projectile *projectiles, Texture2D *projectile_texture);
