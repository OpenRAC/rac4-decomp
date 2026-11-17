/* cflags: -O2 -G8 -Wuninitialized */
#include "common.h"
typedef f32 (*Callback)(void *);
#include "pal/l01_0046DD08.h"
f32 func_L01_004DB7F8(void *arg0) {
    Callback *entry;
    if (arg0 != 0) {
        entry = func_0046DD08(*(s16 *)((u8 *)arg0 + 0xBC), 20, 8);
        if (entry != 0) return (*entry)(arg0);
    }
    return -1.0f;
}
