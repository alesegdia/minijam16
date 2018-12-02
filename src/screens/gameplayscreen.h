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

    void resetGameLogic();

    TheVaker2* m_game;

    std::unique_ptr<GameLogic> m_gameLogic;

};
