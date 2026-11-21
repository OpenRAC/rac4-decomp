/* cflags: @ee296 -O2 -G0 */
#include "common.h"

extern void *func_0011A518(void *, s32, s32);
extern void func_01EA76E8(void *arg0);
extern s32 func_01EA7830(s32, u64, s32, void *, s32, void *);
extern s32 func_01EAB270();
extern void func_01EAB2A0();
extern s32 D_1B1E38[];

typedef struct {
    u64 v;
} __attribute__((packed)) U64Pk;

/* Counts the record at +0x21C up to 0x3C, then resets the buffer and calls the callback at +0x220 */
s32 func_01EA8270(u8 *arg0) {
    u32 sp0;
    s32 sp4 = 0;

    if (*(void **)(arg0 + 0x220) != NULL) {
        func_01EAB2A0(arg0 + 4, &sp0);
        if (sp0 >= 0x1F5) {
            func_01EA7830(*(s32 *)arg0, ((U64Pk *)(arg0 + 0xC))->v, 0x35, arg0 + 0x14, *(s32 *)(arg0 + 0x214), &sp4);
            func_01EAB270(arg0 + 4);
            *(s32 *)(arg0 + 0x21C) = *(s32 *)(arg0 + 0x21C) + 1;
        }
        if (*(s32 *)(arg0 + 0x21C) == 0x3C) {
            func_0011A518(D_1B1E38, 0, 0x88);
            D_1B1E38[33] = 0xC358;
            ((void (*)(void *))*(void **)(arg0 + 0x220))(D_1B1E38);
            func_01EA76E8(*(void **)arg0);
            func_0011A518(arg0, 0, 0x224);
        }
    }
    return 0;
}
