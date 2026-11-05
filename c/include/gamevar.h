#ifndef GAMEVAR_H
#define GAMEVAR_H

#include "includes.h"

struct GameVar {
    Vector2 scale; int scaled;
    int running;
};

extern GameVar gameVar;

#endif
