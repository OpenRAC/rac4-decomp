/* Not matching yet: SIZE ours 212 / retail 200 (tools/try_func.py func_L01_003CEBA0 --diff) (tools/try_func.py func_L01_003CEBA0 --diff). Not part of the build. */
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

typedef void (*ActFn)(u8, s32, Inner *, f32, f32, f32);

typedef struct {
    ActFn unk0;
} Callback;

extern Outer *D_0055A000;
extern u8 D_0055A100;
extern s32 D_0021DE10;

extern Callback *func_L00_005DEBD0(s32, s32, s32);

void func_L01_003CEBA0(s32 arg0, f32 f0, f32 f1) {
    Outer *obj;
    Callback *cb;
    Callback *cb2;
    Inner *in;
    u8 t;

    cb = func_L00_005DEBD0(0x2620, 0, 8);
    if (cb == NULL) {
        return;
    }
    obj = D_0055A000;
    if (obj == NULL) {
        return;
    }
    in = obj->unkAC;
    cb->unk0(in->unk9, arg0, in, (f32)in->unkA, f0, f1);
    if (D_0021DE10 != 0xB) {
        return;
    }
    t = D_0055A100 ^ 1;
    D_0055A100 = t;
    if (t == 0) {
        return;
    }
    cb2 = func_L00_005DEBD0(0x26EE, 0, 4);
    if (cb2 == NULL) {
        return;
    }
    ((void (*)(void))cb2->unk0)();
}
