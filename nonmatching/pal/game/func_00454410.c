/* Not matching yet: PAL WIP; main .text 0x00454410, 56B. Not part of the build. */
/*
 * All4normalgraphs fold pi+pi to40C90FDBmaterialization andomitnative runtimeADD.S f1,f14,f14.
 * Trials1/2/3emit64B,trial4commonpredicateresult76B; native56B. Also
 * differresultregister/controlschedule. h01duplicatesoldactual64Btext. No primaryexact, no
 * helper/global/data/relocation.
 * No match, masked-score, source-ABI or binding approval is implied.
 * Retained source SHA256: 39b9a066a06cd2ef066f81b644113e6ebd2879924199851cc75865d616877e38
 * Reproduce when separately authorized: python3 tools/check_func.py --version pal
 *   func_00454410 nonmatching/pal/game/func_00454410.c --diff
 */
#include "common.h"
f32 func_00454410(f32 a, f32 b)
{
    f32 magnitude = __builtin_fabsf(a - b);
    f32 bound = 3.1415927f;
    if (!(magnitude < bound)) {
        f32 period = bound + bound;
        magnitude = period - magnitude;
    }
    return magnitude;
}
