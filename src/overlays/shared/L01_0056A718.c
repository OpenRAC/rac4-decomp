#include "common.h"

extern s32 func_L00_005C8CF0(s16);
extern void *func_L00_005DEBD0(s32, s32, s32);

// Counts the entries of arg0's list at +0x1B0 whose callback result matches the flag at +0x1B8.
s32 func_L01_0056A718(u8 *arg0, s32 arg1) {
    u8 *list;
    void *(**cb)(void *);
    void *(*fn)(void *);
    void *res;
    s32 n;
    s32 i;

    if (arg0 == 0) {
        return 0;
    }
    list = *(u8 **)(arg0 + 0x1B0);
    if (list == 0) {
        return 0;
    }
    i = 0;
    n = 0;
    if (*(s32 *)(list + 0x110) > 0) {
        do {
            u8 **slot = (u8 **)(list + 0xD0) + i;
            if (*slot != 0) {
                if (arg1 == -1 || func_L00_005C8CF0(*(s16 *)(*slot + 0xBC)) == arg1) {
                    cb = func_L00_005DEBD0(func_L00_005C8CF0(*(s16 *)(*slot + 0xBC)), 0xE, 0x1C);
                    if (cb != 0) {
                        fn = *cb;
                        if (fn != 0) {
                            res = fn(*slot);
                            if (res != 0) {
                                s32 m = n + 1;
                                if (((*(s16 *)((u8 *)res + 0x4E)) ^ *(s32 *)(arg0 + 0x1B8)) == 0) {
                                    n = m;
                                }
                            }
                        }
                    }
                }
            }
            i++;
        } while (i < *(s32 *)(list + 0x110));
    }
    return n;
}
