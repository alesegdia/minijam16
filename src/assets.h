#pragma once

#include <aether/aether.h>

#include <string>

class Assets
{
public:

    static Assets* instance;

    void load()
    {
        barrels.load("assets/barrels.png");
        bg.load("assets/bg.png");
        building.load("assets/building.png");
        hand_shoot.load("assets/hand_shoot.png");
        hand_wait.load("assets/hand_wait.png");
        hand_reloading.load("assets/hand_reloading.png");
        hand_dead.load("assets/hand_dead.png");
        hand_explosion.load("assets/hand_explosion.png");
        hand_explosion_2.load("assets/hand_explosion_2.png");
        rana_aiming.load("assets/rana_aiming.png");
        rana_cover.load("assets/rana_cover.png");
        rana_dead.load("assets/rana_dead.png");
        rana_shoot.load("assets/rana_shoot.png");
        rana_shoot_2.load("assets/rana_shoot_2.png");
        star.load("assets/star.png");

        pointsFont.load("assets/WEST____.TTF", 80);
        textFont.load("assets/WEST____.TTF", 40);

        for( int i = 0; i < 7; i++ ) {
            std::string path = "assets/bullets_" + std::to_string(i) + ".png";
            bullets[i].load(path.c_str());
        }

        theme.load("assets/bso.ogg");

        shoot.load("assets/shoot.wav");
        reload.load("assets/reload.wav");
        explosion.load("assets/explosion.wav");
    }

    void cleanup()
    {
        barrels.destroy();
        bg.destroy();
        building.destroy();
        hand_shoot.destroy();
        hand_wait.destroy();
        hand_reloading.destroy();
        hand_dead.destroy();
        hand_explosion.destroy();
        hand_explosion_2.destroy();
        rana_aiming.destroy();
        rana_cover.destroy();
        rana_dead.destroy();
        rana_shoot.destroy();
        rana_shoot_2.destroy();
        star.destroy();

        for( int i = 0; i < 7; i++ ) {
            bullets[i].destroy();
        }

        pointsFont.destroy();
        textFont.destroy();

        shoot.destroy();
        reload.destroy();
        explosion.destroy();

    }

    aether::graphics::Texture barrels;
    aether::graphics::Texture bg;
    aether::graphics::Texture building;
    aether::graphics::Texture bullets[7];
    aether::graphics::Texture hand_shoot;
    aether::graphics::Texture hand_wait;
    aether::graphics::Texture hand_reloading;
    aether::graphics::Texture hand_dead;
    aether::graphics::Texture hand_explosion;
    aether::graphics::Texture hand_explosion_2;
    aether::graphics::Texture rana_aiming;
    aether::graphics::Texture rana_cover;
    aether::graphics::Texture rana_dead;
    aether::graphics::Texture rana_shoot;
    aether::graphics::Texture rana_shoot_2;
    aether::graphics::Texture star;

    aether::graphics::Font pointsFont;
    aether::graphics::Font textFont;

    aether::audio::Stream theme;

    aether::audio::Sample shoot;
    aether::audio::Sample reload;
    aether::audio::Sample explosion;

};
