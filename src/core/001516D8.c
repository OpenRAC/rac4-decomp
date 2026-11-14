/* cflags: -fno-opt-stack */
#include "common.h"

extern s32 func_00150DC8(u32 **arg0, u32 **arg1, u32 **arg2);
extern void (*D_0016F744[])(s32);
extern u16 D_0016F748[];

/* Checks three linked objects, releases their sub-pointers and clears them; returns a status code. */
s32 func_001516D8(void **arg0, void **arg1, void **arg2) {
    u8 *s0;
    u8 *s1;
    u8 *s2;
    u8 *v1;
    u8 *v0;
    void *p;
    s64 t0;
    s64 a3;
    u8 t1;

    if (arg0 == NULL || arg1 == NULL || arg2 == NULL) {
        return 0x181A;
    }
    v1 = *arg0;
    if (v1 == NULL) {
        return 0x17D4;
    }
    t0 = *(s64 *)v1;
    if (t0 != 0xFACE) {
        return 0x17D4;
    }
    t1 = v1[0x18];
    if (t1 != 0xB) {
        return 0x17E3;
    }
    v0 = *arg1;
    if (v0 == NULL) {
        return 0x17D4;
    }
    a3 = *(s64 *)v0;
    if (a3 != t0) {
        return 0x17D4;
    }
    v1 = *arg2;
    if (v1[0x18] != t1) {
        return 0x17E3;
    }
    if (v1 == NULL) {
        return 0x17D4;
    }
    if (*(s64 *)v1 != a3) {
        return 0x17D4;
    }
    D_0016F748[0] -= 1;
    s0 = *arg0;
    s1 = *arg1;
    s2 = *arg2;
    *(s64 *)s0 = 0;
    *(s64 *)s1 = 0;
    *(s64 *)s2 = 0;
    func_00150DC8((u32 **)(s0 + 0x1C), (u32 **)(s1 + 0x1C), (u32 **)(s2 + 0x1C));
    p = *(void **)(s0 + 0x30);
    if (p != NULL) {
        D_0016F744[0]((s32)p);
        *(void **)(s0 + 0x30) = NULL;
    }
    p = *(void **)(s0 + 0x34);
    if (p != NULL) {
        D_0016F744[0]((s32)p);
        *(void **)(s0 + 0x34) = NULL;
    }
    p = *(void **)(s1 + 0x30);
    if (p != NULL) {
        D_0016F744[0]((s32)p);
        *(void **)(s1 + 0x30) = NULL;
    }
    p = *(void **)(s1 + 0x34);
    if (p != NULL) {
        D_0016F744[0]((s32)p);
        *(void **)(s1 + 0x34) = NULL;
    }
    p = *(void **)(s2 + 0x30);
    if (p != NULL) {
        D_0016F744[0]((s32)p);
        *(void **)(s2 + 0x30) = NULL;
    }
    p = *(void **)(s2 + 0x34);
    if (p != NULL) {
        D_0016F744[0]((s32)p);
        *(void **)(s2 + 0x34) = NULL;
    }
    if (s0 != NULL) {
        D_0016F744[0]((s32)s0);
    }
    if (s1 != NULL) {
        D_0016F744[0]((s32)s1);
    }
    if (s2 != NULL) {
        D_0016F744[0]((s32)s2);
    }
    return 0;
}
