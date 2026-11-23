#include "common.h"

#include "pal/mask_state.h"

/* Apply the current mask state to the eight observed halfword fields. */
void func_L00_006F2158(void *arg0) {
    s32 temp_v0;
    void *temp_a0;
    void *temp_v1;
    u16 *mask;

    if (*(s8 *)((u8 *)D_0021E078 + 0x20) != 0) {
        *(s16 *)((s8 *)*(void **)((s8 *)arg0 + 0x26E4) + 0xABA) = 1;
        *(s16 *)((s8 *)*(void **)((s8 *)arg0 + 0x26E4) + 0xAFE) = 1;
        *(s16 *)((s8 *)*(void **)((s8 *)arg0 + 0x26E4) + 0xB42) = 1;
        *(s16 *)((s8 *)*(void **)((s8 *)arg0 + 0x26E4) + 0xB86) = 1;
        *(s16 *)((s8 *)*(void **)((s8 *)arg0 + 0x26E4) + 0xBCA) = 1;
        *(s16 *)((s8 *)*(void **)((s8 *)arg0 + 0x26E4) + 0xC0E) = 1;
        *(s16 *)((s8 *)*(void **)((s8 *)arg0 + 0x26E4) + 0xC52) = 1;
        *(s16 *)((s8 *)*(void **)((s8 *)arg0 + 0x26E4) + 0xE2E) = 1;
    } else {
        temp_a0 = *(void **)((s8 *)arg0 + 0x26E4);
        temp_v1 = *(void **)((s8 *)*(void **)((s8 *)arg0 + 0x2F28) + 4);
        mask = (u16 *)((s8 *)temp_v1 + 0xB8);
        if (*mask & 4) {
            *(s16 *)((s8 *)temp_a0 + 0xABA) = 1;
        } else {
            *(s16 *)((s8 *)temp_a0 + 0xABA) = 0;
        }
        if (*mask & 8) {
            *(s16 *)((s8 *)temp_a0 + 0xAFE) = 1;
        } else {
            *(s16 *)((s8 *)temp_a0 + 0xAFE) = 0;
        }
        if (*mask & 0x10) {
            *(s16 *)((s8 *)temp_a0 + 0xB42) = 1;
        } else {
            *(s16 *)((s8 *)temp_a0 + 0xB42) = 0;
        }
        if (*mask & 0x20) {
            *(s16 *)((s8 *)temp_a0 + 0xB86) = 1;
        } else {
            *(s16 *)((s8 *)temp_a0 + 0xB86) = 0;
        }
        if (*mask & 0x40) {
            *(s16 *)((s8 *)temp_a0 + 0xBCA) = 1;
        } else {
            *(s16 *)((s8 *)temp_a0 + 0xBCA) = 0;
        }
        if (*mask & 0x80) {
            *(s16 *)((s8 *)temp_a0 + 0xC0E) = 1;
        } else {
            *(s16 *)((s8 *)temp_a0 + 0xC0E) = 0;
        }
        if (*mask & 0x100) {
            *(s16 *)((s8 *)temp_a0 + 0xC52) = 1;
        } else {
            *(s16 *)((s8 *)temp_a0 + 0xC52) = 0;
        }
        if (*mask & 0x8000) {
            *(s16 *)((s8 *)temp_a0 + 0xE2E) = 1;
        } else {
            *(s16 *)((s8 *)temp_a0 + 0xE2E) = 0;
        }
    }
    temp_v0 = *(s32 *)((s8 *)*(void **)((s8 *)*(void **)((s8 *)arg0 + 0x2F28) + 4) + 0x48);
    if (temp_v0 != *(s32 *)((s8 *)arg0 + 0x2318)) {
        *(s32 *)((s8 *)arg0 + 0x2674) = temp_v0;
    }
}
