#include "common.h"

extern void func_00453608(void *p, s32 v, s32 n);
extern s32 *D_0021DDA4;
extern u8 D_3098F0[];

/* Clears the 0x7E0 bytes at D_3098F0, then zeroes the first four words of each 0x1F8-byte record up to the count at D_0021DDA4. */
void func_004B5F78(void) {
    u8 *p;
    s32 i;

    func_00453608(D_3098F0, 0, 0x7E0);
    i = 0;
    if (*D_0021DDA4 > 0) {
        p = D_3098F0;
        do {
            *(s32 *)(p + 0) = 0;
            i++;
            *(s32 *)(p + 4) = 0;
            *(s32 *)(p + 8) = 0;
            *(s32 *)(p + 0xC) = 0;
            p += 0x1F8;
        } while (i < *D_0021DDA4);
    }
}
