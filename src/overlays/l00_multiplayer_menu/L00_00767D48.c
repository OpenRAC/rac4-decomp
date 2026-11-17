#include "common.h"

extern void func_0011A518(void *, s32, s32);
extern void func_0011A9EC(void *, void *);
extern void func_0015B568(void);
extern void func_005C17B0(void *, void *, s32);
extern void func_L00_00767CE0(s32 dest, s32 values);
extern char D_002217F0[];
extern s32 D_002233A4;
extern char D_172160[];

// Copies the record at arg0 into the object at D_002233A4 and resets the table at D_172160 when arg0 + 0x18 is set.
void func_L00_00767D48(u8 *arg0) {
    u8 buf[16];
    s32 v1;
    s32 *s2;
    u8 *s4;

    v1 = *(s32 *)(arg0 + 0x18);
    s4 = *(u8 **)((u8 *)D_002233A4 + 0x3C);
    s2 = *(s32 **)((u8 *)D_002233A4 + 0x34);
    *(s32 *)(s4 + 0x5C) = v1;
    if (v1 != 0) {
        u8 *tbl = (u8 *)D_172160;
        *(s32 *)(tbl + 0xD8) = -1;
        *(s32 *)s4 = -1;
        func_0011A9EC(s4 + 4, D_002217F0);
        func_0011A9EC(tbl + 0xDC, D_002217F0);
        s4[0x30] = 0;
        tbl[0xFD] = 0;
        s4[0x31] = 0;
        func_0011A518(s4 + 0x24, 0, 0xC);
        *(s32 *)(s4 + 0x34) = -1;
        s4[0x38] = (u8)D_002217F0[0];
        *(s32 *)(tbl + 0x184) = -1;
        tbl[0x144] = 0;
        tbl[0x181] = 0;
        func_0015B568();
    } else {
        u8 *tbl = (u8 *)D_172160;
        v1 = *(s32 *)(arg0 + 0x1C);
        *(s32 *)(tbl + 0xD8) = v1;
        *(s32 *)s4 = v1;
        func_005C17B0(buf, arg0 + 0x24, 0x10);
        func_0011A9EC(s4 + 4, buf);
        func_0011A9EC(tbl + 0xDC, buf);
        if (*(s32 *)(arg0 + 0x44) == *s2) {
            s4[0x30] = 1;
            tbl[0xFD] = 1;
        } else {
            s4[0x30] = 0;
            tbl[0xFD] = 0;
        }
        func_L00_00767CE0((s32)(arg0 + 0x68), (s32)(s4 + 0x24));
        *(s32 *)(s4 + 0x34) = *(s32 *)(arg0 + 0x44);
        func_0011A9EC(s4 + 0x38, arg0 + 0x48);
    }
    s4[0x58] = 0;
}
