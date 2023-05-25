#ifndef TICKS
#define TICKS

#include "log.hpp"

namespace ticks
{
    float fps, step, accumulator, frame, current, previous, interpolation,
        factor;
    uint32 frames;

    void init ()
    {
        step   = 0.01;
        factor = 1.0f;
        frames = 1;

        accumulator = frame = current = 0;

        previous      = (get_ticks () / 1000.f);
        interpolation = 0;
    }

    void update (bool paused = false)
    {
        current  = (get_ticks () / 1000.f);
        frame    = current - previous;
        previous = current;

        if (frame > 0.25)
            frame = 0.25;

        accumulator += frame;

        fps = frames / (get_ticks () / 1000.f);
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

#endif
