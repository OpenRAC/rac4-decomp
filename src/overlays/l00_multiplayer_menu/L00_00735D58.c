#include "common.h"

extern s16 func_L00_00764420(int arg0);

#define OBJ_PTR(p, off) (*(void **)((u8 *)(p) + (off)))
#define OBJ_U8(p, off) (*(u8 *)((u8 *)(p) + (off)))
#define OBJ_S32(p, off) (*(s32 *)((u8 *)(p) + (off)))
#define CALL_M(o, m, a1) ((*(void (**)(void *, s32))((u8 *)OBJ_PTR(o, 0x58) + (m)))((o), (a1)))

// Updates the five sub-objects at 0xC0, 0xC4, 0xC8, 0xCC and 0xD0 from their flag and state fields.
void func_L00_00735D58(void *arg0) {
    void *s0;
    s32 v;

    if (OBJ_U8(arg0, 0x3B4) != 0) {
        v = OBJ_S32(arg0, 0x3BC);
        if (v == 0) {
            CALL_M(OBJ_PTR(arg0, 0xC0), 0xA4, 1);
        } else if (v == 3) {
            CALL_M(OBJ_PTR(arg0, 0xC0), 0xA4, 2);
        } else if (v == 4) {
            CALL_M(OBJ_PTR(arg0, 0xC0), 0xA4, 3);
        } else if (v == 1) {
            CALL_M(OBJ_PTR(arg0, 0xC0), 0xA4, 4);
        } else if (v == 2) {
            CALL_M(OBJ_PTR(arg0, 0xC0), 0xA4, 5);
        }
    } else {
        CALL_M(OBJ_PTR(arg0, 0xC0), 0xA4, 0);
    }

    if (OBJ_U8(arg0, 0x39C) != 0) {
        s0 = OBJ_PTR(OBJ_PTR(arg0, 0xC4), 0x58);
        v = func_L00_00764420(OBJ_S32(arg0, 0x3A4));
        (*(void (**)(void *, s32))((u8 *)s0 + 0xA4))(OBJ_PTR(arg0, 0xC4), v);
    } else {
        CALL_M(OBJ_PTR(arg0, 0xC4), 0xA4, 0);
    }

    if (OBJ_U8(arg0, 0x570) != 0) {
        if (OBJ_S32(arg0, 0x578) == 0) {
            CALL_M(OBJ_PTR(arg0, 0xC8), 0xA4, 1);
        } else {
            CALL_M(OBJ_PTR(arg0, 0xC8), 0xA4, 2);
        }
    } else {
        CALL_M(OBJ_PTR(arg0, 0xC8), 0xA4, 0);
    }

    if (OBJ_U8(arg0, 0x3A8) != 0) {
        CALL_M(OBJ_PTR(arg0, 0xCC), 0xD4, OBJ_S32(arg0, 0x3B0));
    } else {
        CALL_M(OBJ_PTR(arg0, 0xCC), 0xD4, 0);
    }

    if (OBJ_U8(arg0, 0x6A8) != 0) {
        if (OBJ_S32(arg0, 0x6B0) == 0) {
            CALL_M(OBJ_PTR(arg0, 0xD0), 0xA4, 0);
        } else {
            CALL_M(OBJ_PTR(arg0, 0xD0), 0xA4, 1);
        }
    } else {
        CALL_M(OBJ_PTR(arg0, 0xD0), 0xA4, 0);
    }
}
