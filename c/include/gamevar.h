#ifndef GAMEVAR_H
#define GAMEVAR_H

#include "includes.h"

struct GameVar {
    Camera2D camera;
    int running;
};

extern GameVar gameVar;

#endif
