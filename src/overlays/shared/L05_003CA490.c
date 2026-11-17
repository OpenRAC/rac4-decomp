#include "common.h"

extern s32 func_L00_005E6058(void *, s32, s32);
extern void func_L01_0056FE70(s32, s32, s32);
extern s32 D_0021DA70;
extern u8 D_1F76C8[];
extern u8 *D_363038[];

// Walks the entries of D_363038; for each live one that func_L00_005E6058 accepts, calls func_L01_0056FE70 when the time window at D_1F76C8 is clear.
void func_L05_003CA490(void *arg0) {
    s32 *link = *(s32 **)((u8 *)arg0 + 0xAC);

    if (link != NULL && *link != -1) {
        s32 i;
        u8 **p = D_363038;
        u8 *e = *p;
        for (i = 0; i < 10; i++) {
            if (e != NULL && func_L00_005E6058(e + 0xA0, *link, 0) != 0) {
                u8 *w = D_1F76C8;
                if (*(u16 *)(w + 0x24) == 0 || (u32)(D_0021DA70 - *(s32 *)(w + 0x28)) > 0x34BC0U) {
                    func_L01_0056FE70(0x2F9C, 0x672, 2);
                }
            }
            p++;
            e = *p;
        }
    }
}
