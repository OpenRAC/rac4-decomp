#include "common.h"

extern void func_L00_005DD4A0(void *);
extern s32 D_222614;
extern s32 D_222660;
extern s32 D_288A20[];

// Run the callbacks of the object's link table, then the callbacks of the table entries it names.
void func_L06_004C4460(u8 *obj) {
    s32 *tbl;
    s32 *p;
    s32 n;
    s32 *row;
    s32 *r;
    s32 off;
    s32 off2;
    s32 i;
    s32 j;
    s32 a;
    u8 *e;
    s32 m;

    tbl = *(s32 **)(obj + 0xAC);
    p = tbl;
    n = 2;
    do {
        if (*p != -1) {
            func_L00_005DD4A0((void *)(D_222614 + (*p << 8)));
        }
        n--;
        p++;
    } while (n >= 0);

    row = tbl + 3;
    i = 0;
    do {
        r = tbl + 3;
        off = i << 2;
        off2 = off;
        j = i + 1;
        a = *(s32 *)((u8 *)r + off);
        if (a != -1) {
            e = (u8 *)D_288A20[a];
            if ((a & 0xFF) != 0xFF && D_222660 >= a && e != NULL) {
                do {
                    if (*(s16 *)(e - 2) < 0 && e != (u8 *)D_288A20[*(s32 *)((u8 *)r + off)]) {
                        break;
                    }
                    m = D_222614 + ((*(u16 *)e & 0x7FFF) << 8);
                    if (m == 0) {
                        break;
                    }
                    e += 2;
                    func_L00_005DD4A0((void *)m);
                    off = off2;
                    r = row;
                    a = *(s32 *)((u8 *)r + off);
                    if ((a & 0xFF) == 0xFF || D_222660 < a) {
                        break;
                    }
                } while (e != NULL);
            }
        }
        i = j;
    } while (i <= 0);
    func_L00_005DD4A0(obj);
}
