#pragma once

#include <aether/aether.h>

#include <string>

class Assets
{
public:

    void load()
    {
        barrels.load("assets/barrels.png");
        bg.load("assets/bg.png");
        building.load("assets/building.png");
        hand_shoot.load("assets/hand_shoot.png");
        hand_wait.load("assets/hand_wait.png");
        hand_reloading.load("assets/hand_reloading.png");
        rana_aiming.load("assets/rana_aiming.png");
        rana_cover.load("assets/rana_cover.png");
        rana_dead.load("assets/rana_dead.png");
        rana_shoot.load("assets/rana_shoot.png");
        rana_shoot_2.load("assets/rana_shoot_2.png");
        star.load("assets/star.png");

        pointsFont.load("assets/WEST____.TTF", 80);

        for( int i = 0; i < 7; i++ ) {
            std::string path = "assets/bullets_" + std::to_string(i) + ".png";
            bullets[i].load(path.c_str());
        }
    }

    void cleanup()
    {
        barrels.destroy();
        bg.destroy();
        building.destroy();
        hand_shoot.destroy();
        hand_wait.destroy();
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

    }

    aether::graphics::Texture barrels;
    aether::graphics::Texture bg;
    aether::graphics::Texture building;
    aether::graphics::Texture bullets[7];
    aether::graphics::Texture hand_shoot;
    aether::graphics::Texture hand_wait;
    aether::graphics::Texture hand_reloading;
    aether::graphics::Texture rana_aiming;
    aether::graphics::Texture rana_cover;
    aether::graphics::Texture rana_dead;
    aether::graphics::Texture rana_shoot;
    aether::graphics::Texture rana_shoot_2;
    aether::graphics::Texture star;

    aether::graphics::Font pointsFont;


};
