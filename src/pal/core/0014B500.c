#include "common.h"

f32 func_0014B500(f32 first, f32 second, f32 third, f32 fourth) {
    f32 selected;
    f32 selected_weight;

    if ((second <= first * 1.25f) && (first * 0.8f <= second)) {
        selected = (first + second) * 0.5f;
    } else {
        if (fourth < third) {
            selected_weight = third;
            selected = first;
        } else {
            selected_weight = fourth;
            selected = second;
        }
        if ((selected < 30.0f) && ((selected_weight * selected * 0.5f) < 1.0f)) {
            selected = first < second ? second : first;
        }
    }
    return selected;
}
