#ifndef GAMEVAR_H
#define GAMEVAR_H

#include "includes.h"

struct GameVar {
    Vector2 scale;
    Camera2D camera;
    int running;
};

extern GameVar gameVar;

#endif
