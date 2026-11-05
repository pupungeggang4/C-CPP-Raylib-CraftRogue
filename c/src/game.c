#include "gamevar.h"
#include "game.h"

void gameInit(GameVar* gameVar) {
    SetConfigFlags(FLAG_VSYNC_HINT);
    InitWindow(800, 600, "Puzzle Game");

    #ifndef __APPLE__
    int mWidth = GetMonitorWidth(0);
    gameVar->scale = GetWindowScaleDPI();
    if (mWidth / (float) gameVar->scale.x > 1280) {
        gameVar->scaled = 1;
        SetWindowSize(800 * gameVar->scale.x, 600 * gameVar->scale.y);
    }
    #endif

    SetExitKey(KEY_NULL);

    gameVar->running = 1;
}

void gameLoop(GameVar* gameVar) {
    if (WindowShouldClose()) gameVar->running = 0;

    if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT)) {
        Vector2 pos = GetMousePosition();
        if (gameVar->scaled) pos = Vector2Scale(pos, gameVar->scale.x);
        printf("(%.0f, %.0f)\n", pos.x, pos.y);
    }

    BeginDrawing();
    ClearBackground(RAYWHITE);
    EndDrawing();
}

void gameEnd(GameVar* gameVar) {
}
