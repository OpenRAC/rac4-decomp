#include "common.h"

/* Preserve native word wrapping and reloads across aliased node writes. */

void func_00160FE8(void *object) {
    s32 remaining;
    s32 now;
    void *node;
    void *current;
    void *next;

    node = (*(void **)((s8 *)(object) + (0xAAC)));
    (*(s8 *)((s8 *)(object) + (0xA99))) = 0;
    if (node != NULL) {
        (*(s8 *)((s8 *)(node) + (0xA0))) = 0;
        remaining = (s32)((u32)(*(s32 *)((s8 *)(object) + (0xAA0))) - 1U);
        (*(void **)((s8 *)(object) + (0xAAC))) = (void *) (*(void **)((s8 *)((*(void **)((s8 *)(object) + (0xAAC)))) + (0x98)));
        (*(s32 *)((s8 *)(object) + (0xAA0))) = remaining;
        if (remaining >= 4) {
            now = *(s32 *)0x21DE40;
            if (((s32)((u32)now - (u32)(*(s32 *)((s8 *)(object) + (0xAA4))))) >= 0x385) {
                (*(s32 *)((s8 *)(object) + (0xAA4))) = (s32)((u32)now - 0x258U);
                if ((*(s8 *)((s8 *)(object) + (0xAA9))) <= 0) {
                    (*(s8 *)((s8 *)(object) + (0xAA9))) = 1;
                }
            }
        }
        next = (*(void **)((s8 *)(object) + (0xAAC)));
        if (next != NULL) {
            if ((*(u8 *)((s8 *)(object) + (0xAA8))) != 0) {
                (*(s8 *)((s8 *)(next) + (0xA0))) = 0;
                (*(void **)((s8 *)(object) + (0xAAC))) = (void *) (*(void **)((s8 *)((*(void **)((s8 *)(object) + (0xAAC)))) + (0x98)));
                (*(s32 *)((s8 *)(object) + (0xAA0))) = (s32) ((s32)((u32)(*(s32 *)((s8 *)(object) + (0xAA0))) - 1U));
                goto block_8;
            }
        } else {
block_8:
            if ((*(u8 *)((s8 *)(object) + (0xAA8))) != 0) {
                if ((*(s32 *)((s8 *)(object) + (0xAA0))) < ((s32) ((f32) (*(s8 *)((s8 *)(object) + (0xAA9))) * 0.25f) + 3)) {
                    (*(u8 *)((s8 *)(object) + (0xAA8))) = 0U;
                }
            }
        }
        if (((s32) ((f32) (*(s8 *)((s8 *)(object) + (0xAA9))) * 0.25f) + 4) < (*(s32 *)((s8 *)(object) + (0xAA0)))) {
            (*(u8 *)((s8 *)(object) + (0xAA8))) = 1U;
        }
        current = (*(void **)((s8 *)(object) + (0xAAC)));
        if (current != NULL) {
            (*(s32 *)((s8 *)(current) + (0x9C))) = 0;
            (*(s8 *)((s8 *)(object) + (0xA98))) = 0;
            (*(s32 *)((s8 *)(object) + (0xA9C))) = (s32) (*(u8 *)((s8 *)((*(void **)((s8 *)(object) + (0xAAC)))) + (0x16)));
        } else {
            (*(s32 *)((s8 *)(object) + (0xAB0))) = 0;
        }
    }
}
