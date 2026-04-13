#include "raylib.h"

#include "config.h"
#include "ship.h"
// #include "timer.h"
#include "projectile.h"

#if defined(PLATFORM_WEB)
#include <emscripten/emscripten.h>
#endif

int screenWidth = 600;
int screenHeight = 800;
Ship ship = {0};
// Timer beam_timer;

Projectile projectiles[MAX_PROJECTILES];
Texture2D projectile_texture;
Vector2 projectile_velocity;

void UpdateDrawFrame(void);
int main() {
  InitWindow(screenWidth, screenHeight, "shmup");
  ship_init(&ship);
  // beam_timer = (Timer) {
  //   .repeating = true,
  //   .duration = 1.0f,
  //   .time_of_last_trigger = GetTime(),
  // };
  projectile_texture = LoadTexture("resources/beam.png");
#if defined(PLATFORM_WEB)
  emscripten_set_main_loop(UpdateDrawFrame, 0, 1);
#else
  SetTargetFPS(60);
  while (!WindowShouldClose()) {
    UpdateDrawFrame();
  }
#endif

  ship_destroy(&ship);
  UnloadTexture(projectile_texture);
  CloseWindow();
  return 0;
}

void UpdateDrawFrame(void) {
  float dt = GetFrameTime();
  double current_time = GetTime();
  ship_update(&ship, dt);
  // timer_update(&beam_timer, current_time);
  projectiles_update(projectiles, dt);
  if (IsKeyPressed(KEY_SPACE)) {
    projectile_spawn(projectiles, ship.position);
  }

  BeginDrawing();

  ClearBackground(BLACK);
  ship_draw(&ship);
  projectiles_draw(projectiles, &projectile_texture);

  EndDrawing();
}
