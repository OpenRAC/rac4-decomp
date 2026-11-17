#include "common.h"

extern void func_L00_005DD4A0(void *);
extern void *func_L00_005DEBD0(s32, s32, s32);
extern s32 D_222694;
extern s32 D_2226E0;
extern s32 D_288A20[];

// Walk the object's two halfword lists from its slot table, re-linking matched entries and calling func_L00_005DD4A0 for the rest.
void func_L08_004D1E78(u8 *obj) {
    u8 *s3;
    u8 *s2;
    u8 *s0;
    u8 *q;
    u8 *cb;
    u16 *a2;
    u16 *s1;
    u16 *t1;
    u8 *r0;

    obj[0x30] = 0xFF;
    s3 = *(u8 **)(obj + 0xAC);
    for (a2 = (u16 *)D_288A20[*(s32 *)s3];
         (*(s32 *)s3 & 0xFF) != 0xFF && D_2226E0 >= *(s32 *)s3 && a2 != NULL &&
         ((s16)a2[-1] >= 0 || a2 == (u16 *)D_288A20[*(s32 *)s3]);
         a2++) {
        s2 = (u8 *)(D_222694 + ((*a2 & 0x7FFF) << 8));
        if (s2 == NULL) return;
        q = *(u8 **)(*(u8 **)(s2 + 0xAC) + 0x2E0);
        if (q != NULL && *(s32 *)(q + 0x2B8) != 0) {
            for (s1 = (u16 *)D_288A20[*(s32 *)s3];
                 (*(s32 *)s3 & 0xFF) != 0xFF && D_2226E0 >= *(s32 *)s3 && s1 != NULL &&
                 ((s16)s1[-1] >= 0 || s1 == (u16 *)D_288A20[*(s32 *)s3]);
                 s1++) {
                s0 = (u8 *)(D_222694 + ((*s1 & 0x7FFF) << 8));
                if (s0 == NULL) break;
                if (s0 != s2) {
                    if (*(u8 *)(*(u8 **)(s0 + 0xAC) + 0x2F0) != 0) {
                        cb = (u8 *)func_L00_005DEBD0(*(s16 *)(s0 + 0xBC), 0, 0x48);
                        ((void (*)(u8 *, s32))*(void **)(cb + 0x44))(s0, 0);
                    }
                    *(u8 *)(*(u8 **)(s0 + 0xAC) + 0x8B) = 1;
                }
            }
            for (t1 = (u16 *)D_288A20[*(s32 *)(s3 + 4)];
                 (*(s32 *)(s3 + 4) & 0xFF) != 0xFF && D_2226E0 >= *(s32 *)(s3 + 4) && t1 != NULL &&
                 ((s16)t1[-1] >= 0 || t1 == (u16 *)D_288A20[*(s32 *)(s3 + 4)]);
                 t1++) {
                r0 = (u8 *)(D_222694 + ((*t1 & 0x7FFF) << 8));
                if (r0 == NULL) break;
                **(s32 **)(r0 + 0xAC) = (s2 - (u8 *)D_222694) >> 8;
            }
            func_L00_005DD4A0(obj);
        }
    }
}
