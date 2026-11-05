#include "gamevar.h"
#include "game.h"

void gameInit(GameVar* gameVar) {
    SetConfigFlags(FLAG_VSYNC_HINT);
    InitWindow(800, 600, "Puzzle Game");
    #if !defined(__APPLE__)
    int width = GetMonitorWidth(GetCurrentMonitor());
    Vector2 dpiScale = GetWindowScaleDPI();
    if (width / (float)dpiScale.x > 1280) {
        SetConfigFlags(FLAG_WINDOW_HIGHDPI);
        SetWindowSize(800 * dpiScale.x, 600 * dpiScale.y);
    }
    #endif
    SetExitKey(KEY_NULL);

    gameVar->running = 1;
}

void gameLoop(GameVar* gameVar) {
    if (WindowShouldClose()) gameVar->running = 0;

    if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT)) {
        Vector2 pos = GetMousePosition();
        printf("(%.0f, %.0f)\n", pos.x, pos.y);
    }

    BeginDrawing();
    ClearBackground(RAYWHITE);
    EndDrawing();
}

void gameEnd(GameVar* gameVar) {
}
