/* cflags: -O2 -G8 -Wuninitialized */
#include "common.h"

extern f32 func_00474558(f32);

void func_L05_003E2AD0(void *arg0) {
    void *temp_16;
    temp_16 = *(void **)((u8 *)arg0 + 0xAC);
    *(f32 *)((u8 *)arg0 + 0xF4) = (f32)(
        func_00474558(*(f32 *)((u8 *)temp_16 + 4)) *
        *(f32 *)((u8 *)temp_16 + 8)
    );
}
