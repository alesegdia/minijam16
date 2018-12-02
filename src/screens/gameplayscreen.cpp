#include "gameplayscreen.h"

#include "../thevaker2.h"

#include <unordered_map>
#include <map>


GameplayScreen::GameplayScreen(TheVaker2 *game)
    : m_game(game)
{

}

void GameplayScreen::show()
{

}

void GameplayScreen::hide()
{

}

void GameplayScreen::render()
{
    aether::graphics::clear(1, 0, 0);
    m_game->assets.bg.draw(0,0);
    m_game->assets.building.draw(0,0);
    m_game->assets.barrels.draw(0,0);

    for( int i = 0; i < 3; i++ ) {
        const auto& rana = m_gameLogic.ranas()[i];
        if( rana != nullptr ) {
            drawRana(rana, i);
        }
    }

    drawHand();

    auto numBullets = m_gameLogic.player().numBullets();
    m_game->assets.bullets[numBullets].draw(0,0);

    m_game->assets.star.draw(0,0);

    static std::string points = std::to_string(m_gameLogic.playerPoints());

    float x = 75;
    if( points.size() == 2 ) {
        x = 60;
    }
    m_game->assets.pointsFont.print(points.c_str(), x, 350);
}


void GameplayScreen::update(uint64_t delta)
{
    m_gameLogic.update(delta);

    if( aether::core::is_key_just_pressed(aether::core::KeyCode::Q) ) {
        m_gameLogic.shootHappened(0);
    }
    if( aether::core::is_key_just_pressed(aether::core::KeyCode::W) ) {
        m_gameLogic.shootHappened(1);
    }
    if( aether::core::is_key_just_pressed(aether::core::KeyCode::E) ) {
        m_gameLogic.shootHappened(2);
    }

    if( aether::core::is_key_just_pressed(aether::core::KeyCode::R) ) {
        m_gameLogic.reload();
    }
}

void GameplayScreen::drawHand()
{
    if( m_gameLogic.player().state() != State::Dead ) {
        aether::graphics::Texture player_tex;
        switch(m_gameLogic.player().state()) {
        case State::OnGuard: {
            player_tex = m_game->assets.hand_wait;
        } break;
        case State::Shooting: {
            player_tex = m_game->assets.hand_shoot;
        } break;
        case State::Reloading: {
            player_tex = m_game->assets.hand_reloading;
        } break;
        default: {
            assert(false && "State not recognised");
        } break;
        }
        auto player_x = m_gameLogic.player().x();
        player_tex.draw(player_x, 50);
    }
}

void GameplayScreen::drawRana(const std::unique_ptr<Rana>& rana, int i)
{
    if( rana == nullptr ) {
        return;
    }

    aether::graphics::Texture rana_tex;

    static std::map<State, aether::graphics::Texture> rana_render_map {
        { State::OnGuard,   m_game->assets.rana_cover },
        { State::Dead,      m_game->assets.rana_dead },
        { State::Shooting,  m_game->assets.rana_shoot },
        { State::Aiming,    m_game->assets.rana_aiming },
    };

    rana_render_map[rana->state()].draw(-225 + rana->x() + i * 200, rana->y() - 20);
}
