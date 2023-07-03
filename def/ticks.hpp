#ifndef TICKS
#define TICKS

#include "log.hpp"

namespace ticks
{
    float fps, step, accumulator, frame, current, previous, interpolation,
        factor;
    uint32 frames;

    void  init ();
    void  update (bool paused = false);
    float dt ();

    float interpolate (float pos, float prev);
};

#endif
