#include "endscreen.h"

#include "../thevaker2.h"


EndScreen::EndScreen(TheVaker2 *game)
{
    m_game = game;
}

void EndScreen::show()
{

}

void EndScreen::hide()
{

}

void EndScreen::render()
{
    aether::graphics::clear(1, 0, 0);
}


void EndScreen::update(uint64_t delta)
{
    if( aether::core::is_key_just_pressed(aether::core::KeyCode::Enter) )
    {
        m_game->setScreen(&m_game->menuScreen);
    }
}
