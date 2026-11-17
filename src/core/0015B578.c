#include "common.h"

extern void func_0011A518(void *, s32, s32);
extern void func_0015B548(s32 val);
extern s32 func_0015B558(void);
extern s32 func_00161128(void);
extern s32 func_01ED5D30(s8 *arg0);
extern s32 func_01ED7530();
extern s8 D_00172160[];

typedef struct {
    s32 w[13];
} Type1;

/* Starts a request: clears a buffer, copies the caller's 52-byte record into it and queues it. */
s32 func_0015B578(s32 arg0, void *arg1) {
    s8 buf[0x118];
    s32 t;
    s32 r;
    s32 ret;

    t = func_00161128();
    if (t < 0) {
        ret = 0;
    } else {
        D_00172160[0x480] = 0;
        *(s32 *)(D_00172160 + 0x484) = arg0;
        func_0011A518(buf, 0, 0x118);
        func_01ED5D30(buf);
        *(s32 *)(buf + 0x14) = t;
        *(Type1 *)(buf + 0x18) = *(Type1 *)arg1;
        r = func_01ED7530(buf);
        func_0015B548(r);
        ret = func_0015B558() == 0;
    }
    return ret;
}
