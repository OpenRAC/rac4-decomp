#include "common.h"

typedef struct { s32 x0; u8 *x4; s32 x8; s32 xC; } Type1;
extern void *func_005005E8(s32, s32);
extern void *func_005010E0(void);
extern s32 func_00503FA8(s32, void *, f32);
extern s32 D_00220B50;
extern Type1 D_222038;

static inline void *func_00503EE0_cast(void *h) {
    if (h != 0 && ((s32 (*)(void *, s32))(*(s32 *)(*(u8 **)((u8 *)h + 8) + 0x14)))(h, D_00220B50) != 0) return h;
    return 0;
}

// Look up the current entry of the D_222038 list, fetch its object for arg1 and apply func_00503FA8 when it supports D_00220B50.
s32 func_00503EE0(s32 arg0, s32 arg1, f32 arg2) {
    s32 result = 0;
    Type1 *base;
    u8 *list;
    s32 key;
    void *obj;
    if (D_222038.x4 != 0) base = &D_222038;
    else base = func_005010E0();
    list = base->x4;
    key = 0;
    if (list != 0) key = *(s32 *)((u32)list + (*(s32 *)(list + 0x14) << 2));
    obj = func_00503EE0_cast(func_005005E8(key, arg1));
    if (obj != 0) result = func_00503FA8(arg0, obj, arg2);
    return result;
}
