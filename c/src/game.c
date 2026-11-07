#include "gamevar.h"
#include "game.h"

void gameInit(GameVar* gameVar) {
    float aspRatio = 0.75;
    SetConfigFlags(FLAG_VSYNC_HINT);
    int width = 800, height = 600;
    InitWindow(width, height, "Puzzle Game");
    int mWidth = GetMonitorWidth(0); int mHeight = GetMonitorHeight(0);
    if (mWidth * aspRatio > height) {
        height = (int)(mHeight * 0.8); width = (int)(height / aspRatio);
    } else {
        width = (int)(mWidth * 0.8); height = (int)(width * aspRatio);
    }
    SetWindowSize(width, height);
    SetWindowPosition((mWidth - width) / 2, (mHeight - height) / 2);

    SetExitKey(KEY_NULL);

    Camera2D tempCamera = {0}; gameVar->camera = tempCamera;
    gameVar->running = 1;
}

void gameLoop(GameVar* gameVar) {
    gameVar->camera.zoom = GetRenderWidth() / 800.0f;
    if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT)) {
        Vector2 pos = GetMousePosition();
        pos = Vector2Scale(pos, 1 / gameVar->camera.zoom);
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
