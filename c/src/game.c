#include "gamevar.h"
#include "game.h"

void gameInit(GameVar* gameVar) {
    SetConfigFlags(FLAG_VSYNC_HINT);
    int width = 800, height = 600;

    #ifndef __APPLE__
    int mWidth = GetMonitorWidth(GetCurrentMonitor());
    Vector2 dpiScale = GetWindowScaleDPI();
    if (mWidth / (float)dpiScale.x > 1280) {    
        width *= dpiScale.x; height *= dpiScale.y;
        SetConfigFlags(FLAG_WINDOW_HIGHDPI);
    }
    #endif
    
    InitWindow(width, height, "Puzzle Game");
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
