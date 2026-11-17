#include "common.h"

extern void func_0011A518(void *, s32, s32);
extern void func_0011A5D0(u8 *, u8 *);
extern s32 func_0011A8A0(void *, const u8 *);
extern s32 func_0011AB04(u8 *);
extern s32 func_0011AE00(char *, char *, s32);
extern char D_00221968[];

// Clears the 0x2EE0-byte buffer at +0x2FBC and appends each listed entry's name that passes the checks and fits.
u8 *func_L00_0077CE08(u8 *object) {
    u8 *prev = 0;
    s32 i = 0;
    s32 count;
    u8 *list;
    u8 *entry;
    u8 *name;
    u8 *buf;

    func_0011A518(object + 0x2FBC, 0, 0x2EE0);
    list = object + (*(s32 *)(object + 0x2F94) * 0xC + 0x2F9C);
    count = *(s32 *)(list + 4);
    if (count > 0) {
        do {
            entry = ((u8 **)*(u8 **)(list + 8))[i];
            if (prev == 0 || func_0011A8A0(prev + 0x20, entry + 0x20) != 0) {
                name = entry + 0x20;
                if (func_0011AE00((char *)name, D_00221968, 5) != 0) {
                    buf = object + 0x2FBC;
                    if ((u32)(func_0011AB04(buf) + func_0011AB04(name)) < 0x2EE0) {
                        func_0011A5D0(buf, name);
                    }
                }
                prev = entry;
            }
            i++;
        } while (i < count);
    }
    return object + 0x2FBC;
}
