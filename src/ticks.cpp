#include "../def/ticks.hpp"

namespace ticks
{
    void init ()
    {
        step   = 0.01;
        factor = 1.0f;
        frames = 1;

        accumulator = frame = current = 0;

        previous      = (api::getTicks () / 1000.f);
        interpolation = 0;
    }

    void update (bool paused)
    {
        current  = (api::getTicks () / 1000.f);
        frame    = current - previous;
        previous = current;

        if (frame > 0.25)
            frame = 0.25;

        accumulator += frame;

        fps = frames / (api::getTicks () / 1000.f);
        frames++;
    }

    float dt ()
    {
        return step * factor;
    }

    float interpolate (float pos, float prev)
    {
        return pos * interpolation + prev * (1.0f - interpolation);
    }
};
