
#include "thevaker2.h"


TheVaker2::TheVaker2(int w, int h)
    : aether::core::Application(w, h),
      menuScreen(this),
      gameplayScreen(this),
      endScreen(this)
{

}

int TheVaker2::ready(int argc, char **argv)
{
    assets.load();

	setScreen(&gameplayScreen);

    //assets.theme.playmode(aether::audio::PlayMode::Loop);
    //assets.theme.play();
    return 0;
}

void TheVaker2::update(uint64_t delta)
{
    aether::core::Application::update(delta);
    if( aether::core::is_key_down(aether::core::KeyCode::Escape) )
    {
        close();
    }
}

void TheVaker2::dispose()
{
    assets.cleanup();
}
