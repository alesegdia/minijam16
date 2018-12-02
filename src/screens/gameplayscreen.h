#pragma once

#include <aether/aether.h>

#include "../core/entity.h"

class TheVaker2;

class GameplayScreen : public aether::core::IScreen
{
public:
    GameplayScreen(TheVaker2* game);

    void show() final;
    void hide() final;
    void render() final;
    void update(uint64_t delta) final;

private:

    void drawHand();
    void drawRana(const std::unique_ptr<Rana>&   entity, int i);

    TheVaker2* m_game;

    GameLogic m_gameLogic;

};
