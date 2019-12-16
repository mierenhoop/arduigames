#pragma once

#include "game.h"
#include "util.h"

class Snake : public Game {
private:
    Direction dir;

    Vec2<float> head;
    Vec2<int> *tail;

    int tail_len;

    Vec2<int> candy;

    void new_candy();


public:
    Snake(int start_len);

    void update(float delta);
};