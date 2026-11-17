#include "common.h"

extern void func_00744BC8(void *, s32);
extern s16 func_L00_00764420(int arg0);
extern s32 func_L00_007644A8(s32 arg0);
typedef s32 (*Get1)(void *);
typedef void (*Set2)(void *, s32);
typedef void (*Set3)(void *, s32, s32);

/* Refreshes the slot indicators at 0xC8 and 0x138 from the state the object at 0xBC reports. */
void func_L00_00744A90(u8 *arg0) {
    s32 s0;
    func_00744BC8(arg0, func_L00_00764420((*(Get1 *)((u8 *)*(void **)((u8 *)*(void **)(arg0 + 0xBC) + 0x58) + 0xA8))(*(void **)(arg0 + 0xBC))));
    s0 = (*(Get1 *)((u8 *)*(void **)((u8 *)*(void **)(arg0 + 0xBC) + 0x58) + 0xA8))(*(void **)(arg0 + 0xBC));
    if (s0 == func_L00_007644A8(0x29) || (s0 = (*(Get1 *)((u8 *)*(void **)((u8 *)*(void **)(arg0 + 0xBC) + 0x58) + 0xA8))(*(void **)(arg0 + 0xBC)), s0 == func_L00_007644A8(0x30))) {
        (*(Set2 *)((u8 *)*(void **)((u8 *)*(void **)(arg0 + 0xC8) + 0x58) + 0xA4))(*(void **)(arg0 + 0xC8), 0);
        (*(Set3 *)((u8 *)*(void **)((u8 *)*(void **)(arg0 + 0xC8) + 0x58) + 0x20))(*(void **)(arg0 + 0xC8), 3, 0);
        (*(Set3 *)((u8 *)*(void **)((u8 *)*(void **)(arg0 + 0x138) + 0x58) + 0x20))(*(void **)(arg0 + 0x138), 3, 0);
    } else {
        (*(Set3 *)((u8 *)*(void **)((u8 *)*(void **)(arg0 + 0xC8) + 0x58) + 0x20))(*(void **)(arg0 + 0xC8), 0, 0);
        (*(Set2 *)((u8 *)*(void **)((u8 *)*(void **)(arg0 + 0xC8) + 0x58) + 0xA4))(*(void **)(arg0 + 0xC8), arg0[0x2B8] != 0);
        (*(Set3 *)((u8 *)*(void **)((u8 *)*(void **)(arg0 + 0x138) + 0x58) + 0x20))(*(void **)(arg0 + 0x138), arg0[0x2B8] != 0 ? 4 : 3, 0);
    }
}
