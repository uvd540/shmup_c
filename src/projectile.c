#include "projectile.h"
#include "config.h"
#include "raymath.h"

void projectile_spawn(Projectile *projectiles, Vector2 position) {
  for (int i = 0; i < MAX_PROJECTILES; i++) {
    if (!projectiles[i].active) {
      projectiles[i].active = true;
      projectiles[i].position = position;
      break;
    }
  }
}

void projectiles_update(Projectile *projectiles, float dt) {
  for (int i = 0; i < MAX_PROJECTILES; i++) {
    if (projectiles[i].active) {
      projectiles[i].position = Vector2Add(
          projectiles[i].position, Vector2Scale(PROJECTILE_VELOCITY, dt));
    }
    if (projectiles[i].position.y < -16.0f) {
      projectiles[i].active = false;
    }
  }
}

void projectiles_draw(Projectile *projectiles, Texture2D *projectile_texture) {
  for (int i = 0; i < MAX_PROJECTILES; i++) {
    if (projectiles[i].active) {
      DrawTextureEx(*projectile_texture, projectiles[i].position, 0.0f, 3.0f,
                    WHITE);
    }
  }
}

