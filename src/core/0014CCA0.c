#include "common.h"
f32 func_0014CCA0(f32 level, f32 value, f32 minimum, f32 speed, f32 target)
{
    if (level <= 0.01f)
        value = 0.0f;
    if (level >= 0.45f) {
        level -= 0.45f;
        if (level * (speed * 0.5f) < 1.0f)
            level += 0.0714285746216774f;
        if (value < level)
            value = level;
    }
    if (value < minimum && minimum >= 0.0714285746216774f) {
        if (speed < target * 1.25f && speed > target * 0.8f)
            value = value * 0.7f + minimum * 0.3f;
        if (value < 0.0714285746216774f)
            value += 0.0714285746216774f;
    }
    return value;
}
