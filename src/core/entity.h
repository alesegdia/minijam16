#pragma once

#include <iostream>
#include <memory>

#include <aether/aether.h>

#include "../assets.h"


class Config {
public:
    static constexpr double PlayerAttackingTime = 0.5e6;
    static constexpr double TimeReloading = 0.5e6;
    static constexpr double TimeShooting = 0.2e6;
    static constexpr double NumBullets = 6;
    static constexpr double MinRanaShootTimer = 2e6;
    static constexpr double MaxRanaShootTimer = 4e6;
    static constexpr double FirstRanaSpawnTimer = 3e6;
    static constexpr double MinSpawnTimer = 1.5e6;
    static constexpr double MaxSpawnTimer = 3e6;
    static constexpr double RanaAimingTime = 1e6;
    static constexpr double DyingTime = 1e6;
};

enum class State : size_t {
    OnGuard = 0,
    Aiming,
    Dead,
    Shooting,
    Puffed,
    Reloading,
    Num
};

enum Faction {
    Player,
    Enemy
};


class Entity {
public:
    virtual ~Entity();
    virtual void update(double delta) = 0 ;
    void render();
    State state() const;

    float x() const;
    float y() const;
    void x(float px) { m_x = px; }
    void y(float py) { m_y = py; }

    void died();


protected:

    bool updateTimer(double delta);

    State m_state;
    Faction m_faction;
    float m_x{0};
    float m_y{0};
    double m_timer{0};

};




class Player : public Entity {
public:
    Player();
    void update(double delta) override;
    void shoot();
    void reload();

    int numBullets() const;

private:
    uint8_t m_bullets = 6;

};

class Rana : public Entity {
public:
    Rana(double timeToShoot);

    void update(double delta) override;


    bool shouldRemove()
    {
        return m_state == State::Dead && m_timer <= 0;
    }
};

class GameLogic
{
public:
    GameLogic();
    void update(uint64_t delta);

    const class Player& player();

    const std::unique_ptr<Rana>* ranas();

    void spawnRana();

    void shootHappened(int shootPosition);

    void refreshRanaSpawnTimer();

    void reload();

    int playerPoints()
    {
        return m_playerPoints;
    }

    int playerLuck()
    {
        return m_playerLuck;
    }

private:
    class Player m_player;
    int m_playerPoints{0};
    int m_playerLuck{5};
    std::unique_ptr<Rana> m_ranas[3]{ nullptr, nullptr, nullptr };
    double m_nextRanaSpawn;

};
