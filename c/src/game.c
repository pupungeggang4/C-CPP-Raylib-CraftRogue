#include "gamevar.h"
#include "game.h"

void gameInit(GameVar* gameVar) {
    SetConfigFlags(FLAG_WINDOW_HIGHDPI);
    SetConfigFlags(FLAG_VSYNC_HINT);
    int width = 800, height = 600;
    InitWindow(width, height, "Puzzle Game");
    int mWidth = GetMonitorWidth(0);
    Vector2 dpiScale = GetWindowScaleDPI();

    #ifndef __APPLE__
    if (mWidth / (float)dpiScale.x > 1280) {
        SetWindowSize(800 * dpiScale.x, 600 * dpiScale.y);
    } else {
        ClearWindowState(FLAG_WINDOW_HIGHDPI);
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
