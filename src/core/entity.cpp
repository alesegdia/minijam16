
#include "entity.h"


Entity::~Entity() {

}

State Entity::state() const
{
    return m_state;
}

float Entity::x() const
{
    return m_x;
}

float Entity::y() const
{
    return m_y;
}

Player::Player() {
    m_state = State::OnGuard;
}

void Player::update(double delta)
{
    auto timerExpired = updateTimer(delta);

    if( timerExpired && m_state == State::Reloading ) {
        m_state = State::OnGuard;
    } else if( timerExpired && m_state == State::Shooting ) {
        m_state = State::OnGuard;
    }
}

void Player::shoot()
{
    if( (m_state == State::OnGuard || m_state == State::Shooting) && m_bullets > 0 ) {
        if( m_bullets == 0 ) {
            m_state = State::OnGuard; // State::Puffed;
        } else {
            m_bullets--;
            m_state = State::Shooting;
            m_timer = Config::TimeShooting;
        }
    }
}

void Player::reload()
{
    if( m_state == State::OnGuard ) {
        m_state = State::Reloading;
        m_timer = Config::TimeReloading;
        m_bullets = 6;
    }
}

int Player::numBullets() const
{
    return m_bullets;
}

GameLogic::GameLogic()
{
    m_nextRanaSpawn = Config::FirstRanaSpawnTimer;
}

void GameLogic::update(uint64_t delta)
{
    m_player.update(delta);
    for( int i = 0; i < 3; i++ ) {
        if( m_ranas[i] != nullptr )  {
            m_ranas[i]->update(delta);
            if( m_ranas[i]->state() == State::Shooting ) {
                m_player.died();
            }
            if( m_ranas[i]->shouldRemove() ) {
                m_ranas[i] = nullptr;
            }
        }
    }

    if( m_nextRanaSpawn > 0 ) {
        m_nextRanaSpawn -= delta;
        if( m_nextRanaSpawn <= 0 ) {
            spawnRana();
            refreshRanaSpawnTimer();
        }
    }
}

const class Player &GameLogic::player()
{
    return m_player;
}

const std::unique_ptr<Rana>* GameLogic::ranas()
{
    return m_ranas;
}

void GameLogic::spawnRana()
{
    std::vector<size_t> freeGaps;
    for( size_t i = 0; i < 3; i++ ) {
        if( m_ranas[i] == nullptr ) {
            freeGaps.push_back(i);
        }
    }
    if( freeGaps.size() <= 0 ) {
        return;
    }
    auto rnd = size_t(aether::math::randi(0, int(freeGaps.size())));
    m_ranas[freeGaps[rnd]] = std::make_unique<Rana>(
                aether::math::randi(
                    int(Config::MinRanaShootTimer),
                    int(Config::MaxRanaShootTimer)));
}

void GameLogic::shootHappened(int shootPosition)
{
    if( shootPosition == 0 ) {
        m_player.x(-230);
    } else if( shootPosition == 1 ) {
        m_player.x(-30);
    } else if( shootPosition == 2 ) {
        m_player.x(150);
    }
    if( m_player.numBullets() == 0 ) {
        //m_player.puffed();
    } else {
        m_player.shoot();
        if( m_ranas[shootPosition] == nullptr ) {

        } else if( m_ranas[shootPosition]->state() == State::Aiming ) {
            m_playerPoints++;
            m_playerLuck++;
            if( m_playerLuck > 10 ) {
                m_playerLuck = 10;
            }
            m_ranas[shootPosition]->died();
        } else if( m_ranas[shootPosition]->state() == State::OnGuard ) {
            m_playerLuck--;
            if( m_playerLuck < 0 ) {
                m_playerLuck = 0;
            }
        }
    }
}

void GameLogic::refreshRanaSpawnTimer() {
    m_nextRanaSpawn = aether::math::randi(
                int(Config::MinSpawnTimer),
                int(Config::MaxSpawnTimer));
}

void GameLogic::reload()
{
    m_player.reload();
}

Rana::Rana(double timeToShoot)
{
    m_timer = timeToShoot;
    m_state = State::OnGuard;
}

void Rana::update(double delta)
{
    bool timerExpired = updateTimer(delta);

    if( timerExpired && m_state == State::OnGuard ) {
        m_state = State::Aiming;
        m_timer = Config::RanaAimingTime;
    } else if( timerExpired && m_state == State::Aiming ) {
        m_state = State::Shooting;
    }
}

void Entity::died()
{
    m_state = State::Dead;
    m_timer = Config::DyingTime;
}


bool Entity::updateTimer(double delta)
{
    bool timerExpired = false;
    if( m_timer > 0 ) {
        m_timer -= delta;
        if( m_timer <= 0 ) {
            timerExpired = true;
        }
    }
    return timerExpired;
}
