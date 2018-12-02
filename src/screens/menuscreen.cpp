#include "menuscreen.h"

#include "../thevaker2.h"


MenuScreen::MenuScreen(TheVaker2 *game)
{
    m_game = game;
}

void MenuScreen::show()
{

}

void MenuScreen::hide()
{

}

void MenuScreen::render()
{
    aether::graphics::clear(0, 0, 0);
}


void MenuScreen::update(uint64_t delta)
{
    if( aether::core::is_key_just_pressed(aether::core::KeyCode::Enter) )
    {
        m_game->setScreen(&m_game->gameplayScreen);
    }
}
