#pragma once

#include <aether/aether.h>

#include "../core/entity.h"

class TheVaker2;

class MenuScreen : public aether::core::IScreen
{
public:
    MenuScreen(TheVaker2* game);

    void show() final;
    void hide() final;
    void render() final;
    void update(uint64_t delta) final;

private:
    TheVaker2* m_game;

};
