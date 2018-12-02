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
    Assets::instance->rana_shoot_2.draw(-30,-50);
    Assets::instance->pointsFont.print("The Raner", 200, 50, aether::graphics::Color(255, 255, 0));
    Assets::instance->textFont.print("Press Q/W/E keys to shoot at Left/Center/Right", 6, 170, aether::graphics::Color(255, 255, 255));
    Assets::instance->textFont.print("Press R to reload", 230, 230, aether::graphics::Color(255, 255, 255));
    Assets::instance->textFont.print("Shoot when Rana's are prepared or you'll puff", 20, 290, aether::graphics::Color(255, 255, 255));
    Assets::instance->textFont.print("Press ENTER to START!", 170, 380, aether::graphics::Color(255, 0, 0));
}


void MenuScreen::update(uint64_t delta)
{
    if( aether::core::is_key_just_pressed(aether::core::KeyCode::Enter) )
    {
        m_game->setScreen(&m_game->gameplayScreen);
    }
}
