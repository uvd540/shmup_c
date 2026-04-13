#include "ship.h"
#include "raylib.h"
#include "raymath.h"

void ship_init(Ship *ship) {
  ship->texture = LoadTexture("resources/ship.png");
  Vector2 starting_position = {300.0f, 400.0f};
  ship->src_rect = (Rectangle){0.0f, 16.0f, 16.0f, 16.0f};
  ship->dst_rect =
      (Rectangle){starting_position.x, starting_position.y, 48.0f, 48.0f};
  ship->position = starting_position;
  ship->speed = 500.0f;
}

void ship_update(Ship *ship, float dt) {
  Vector2 movement_direction = {0};
  if (IsKeyDown(KEY_LEFT)) {
    movement_direction.x--;
  }
  if (IsKeyDown(KEY_RIGHT)) {
    movement_direction.x++;
  }
  if (IsKeyDown(KEY_UP)) {
    movement_direction.y--;
  }
  if (IsKeyDown(KEY_DOWN)) {
    movement_direction.y++;
  }
  movement_direction = Vector2Normalize(movement_direction);
  ship->position = Vector2Add(
      ship->position, Vector2Scale(movement_direction, ship->speed * dt));
  if (movement_direction.x < -0.5) {
    ship->src_rect.x = 0.0f;
  } else if (movement_direction.x > 0.5) {
    ship->src_rect.x = 32.0f;
  } else {
    ship->src_rect.x = 16.0f;
  }
  ship->position = Vector2Clamp(ship->position, (Vector2){0.0f, 0.0f},
                                (Vector2){600.0f - 48.0f, 800.0f - 48.0f});
  ship->dst_rect.x = ship->position.x;
  ship->dst_rect.y = ship->position.y;
}

void ship_draw(Ship *ship) {
  // DrawRectanglePro(ship->dst_rect, (Vector2){0.0f, 0.0f}, 0.0f, WHITE);
  // DrawTexture(ship->texture, ship->position.x, ship->position.y, WHITE);
  // DrawTextureRec(ship->texture, ship->src_rect, ship->position, WHITE);
  DrawTexturePro(ship->texture, ship->src_rect, ship->dst_rect,
                 (Vector2){0.0f, 0.0f}, 0.0f, WHITE);
}

void ship_destroy(Ship *ship) { UnloadTexture(ship->texture); }
