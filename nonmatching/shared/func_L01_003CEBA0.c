/* Not matching yet: BYTES 44/200 (tools/try_func.py func_L01_003CEBA0 --diff) (tools/try_func.py func_L01_003CEBA0 --diff). Not part of the build. */
/* cflags: @ee296 -O2 -G8 -mno-split-addresses */
#include "common.h"

typedef struct {
    u8 pad[9];
    u8 unk9;
    s16 unkA;
} Inner;

typedef struct {
    u8 pad[0xAC];
    Inner *unkAC;
} Outer;

typedef s32 (*ActionCallback)(u8, s32, Inner *, f32, f32, f32);

extern Outer *D_0055A000;
extern u8 D_0055A100;
extern s32 D_0021DE10[];

extern ActionCallback *func_L00_005DEBD0(s32, s32, s32);

void func_L01_003CEBA0(s32 arg0, f32 f0, f32 f1) {
    ActionCallback *cb;
    Outer *obj;
    u8 t;

    cb = func_L00_005DEBD0(0x2620, 0, 8);
    if (cb == NULL) {
        return;
    }
    obj = D_0055A000;
    if (obj == NULL) {
        return;
    }
    (*cb)(obj->unkAC->unk9, arg0, obj->unkAC, (f32)obj->unkAC->unkA, f0, f1);
    if (D_0021DE10[0] != 0xB) {
        return;
    }
    t = D_0055A100 ^ 1;
    D_0055A100 = t;
    if (t == 0) {
        return;
    }
    cb = func_L00_005DEBD0(0x26EE, 0, 4);
    if (cb == NULL) {
        return;
    }
    ((void (*)(void))(*cb))();
}
