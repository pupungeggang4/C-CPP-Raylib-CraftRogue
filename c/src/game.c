#include "gamevar.h"
#include "game.h"

void gameInit(GameVar* gameVar) {
    SetConfigFlags(FLAG_VSYNC_HINT);
    SetConfigFlags(FLAG_WINDOW_HIGHDPI);
    InitWindow(800, 600, "Puzzle Game");
    #ifndef __APPLE__
    int mWidth = GetMonitorWidth(0); int mHeight = GetMonitorHeight(0);
    Camera2D tempCamera = {0}; gameVar->camera = tempCamera;
    Vector2 scale = GetWindowScaleDPI();
    if (mWidth / scale.x < 800 || mHeight / scale.y < 600) {
        int width = mWidth / scale.x * 0.8; int height = width * 0.75;
        SetWindowSize(width, height);
        SetWindowPosition(
            GetMonitorWidth(0) / 2.0f - GetRenderWidth() / 2.0f,
            GetMonitorHeight(0) / 2.0f - GetRenderHeight() / 2.0f
        );
    }
    #endif

    SetExitKey(KEY_NULL);

    gameVar->running = 1;
}

void gameLoop(GameVar* gameVar) {
    gameVar->camera.zoom = GetRenderWidth() / 800.0f;
    if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT)) {
        Vector2 pos = GetMousePosition();
        //pos = Vector2Scale(pos, 1 / gameVar->camera.zoom);
        printf("(%.0f, %.0f)\n", pos.x, pos.y);
    }

    BeginDrawing();
    BeginMode2D(gameVar->camera);
    ClearBackground(RAYWHITE);
    DrawRectangle(0, 0, 80, 80, PINK);
    EndMode2D();
    EndDrawing();

    if (WindowShouldClose()) gameVar->running = 0;
}

void gameEnd(GameVar* gameVar) {
    CloseWindow();
}
