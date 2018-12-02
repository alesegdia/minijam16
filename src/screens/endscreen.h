#pragma once

#include <aether/aether.h>

class TheVaker2;

class EndScreen : public aether::core::IScreen
{
public:
    EndScreen(TheVaker2 *game);

    void show() final;
    void hide() final;
    void render() final;
    void update(uint64_t delta) final;

private:
    TheVaker2* m_game;

};
