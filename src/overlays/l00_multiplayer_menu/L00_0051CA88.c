#include "common.h"

extern s32 func_L00_004F8BE0(void *self, s32 *key);
extern void **func_L00_0051CB60(void **a0, void *a1, s32 a2, s32 a3, void *a4);
extern void func_L00_0051CB18(void);
extern void *D_004A1888[];
extern u8 D_004A16F0[];

/* Returns the id at +8 of arg0, or of the record the table lookup finds for it. */
s32 func_L00_0051CA88(void *arg0) {
    s32 key[2];
    void *sp10 = arg0;
    void *p = arg0;
    s32 *r;
    void **found;

    if (p == NULL) {
        return 0;
    }
    if (*(s32 *)((u8 *)p + 8) == 0) {
        if (D_004A1888[0] != NULL) {
            key[1] = (s32)p;
            key[0] = 0;
            r = (s32 *)func_L00_004F8BE0(D_004A1888[0], key);
            if (r != NULL) {
                p = (void *)r[1];
                goto tail;
            }
        }
        found = func_L00_0051CB60(&sp10, D_004A16F0, 0x65, 4, (u8 *)func_L00_0051CB18 + 8);
        if (found == NULL) {
            return 0;
        }
        p = *found;
    }
tail:
    return *(s32 *)((u8 *)p + 8);
}
