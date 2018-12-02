#include <aether/aether.h>

#include "screens/menuscreen.h"
#include "screens/gameplayscreen.h"
#include "screens/endscreen.h"
#include "assets.h"

class TheVaker2 : public aether::core::Application
{
public:
    TheVaker2(int w, int h);

    int ready(int argc, char **argv) override;

    void update(uint64_t delta) override;

    void dispose() override;

    MenuScreen menuScreen;
    GameplayScreen gameplayScreen;
    EndScreen endScreen;

    Assets assets;

};

