#include "common.h"

typedef struct { u8 pad0[0xC4]; char name[0x568]; u8 unk62C; u8 pad62D[3]; s32 unk630; } Net;
typedef struct { u8 pad0[0x28]; s32 unk28; s32 unk2C; u8 unk30; u8 pad31[3]; } Info;
extern Net D_00172160;
extern s32 D_0021DA64;
extern s32 D_0021DA68;
extern u8 D_0021DA6C;
extern u8 D_0021DA6C__lui;
extern u16 D_0021DFB0[];
extern void func_0015BED0();
extern s32 func_0011A518(void *, s32, s32);
extern char *func_0011A9EC(char *, char *);
extern u64 func_0012E370(void);
extern s64 func_0012FEB0(s64, s64);
extern s32 func_01ED6998(u8 *, s32, s32);
extern void func_0015B548(s32);
extern s32 func_0015B558(void);
extern void func_0015A028(void);
extern void func_0015A050(void);
// Fills a 0x126-byte packet (two-byte header, the name at +0xC4 of D_00172160), stamps the
// 0x34-byte block at info with a bitwise CRC-32 of its first 0x28 bytes (xored with
// 0x1725DFAD, then with the D_0021DA64 key words), copies it in at +0x26 and sends it
// with func_0015BED0 as callback. With wait, polls until the +0x62C flag clears: 0 on a
// func_0015B558 error, a 5000-tick timeout or a set +0x630 field, else 1.
s32 func_0015BC70(u8 *info, s32 wait) {
    u8 buf[0x126];
    u8 *p;
    s32 crc;
    s32 i;
    s32 start;
    s32 ok;
    s32 z;
    s32 poly;

    D_0021DA6C = D_0021DA6C__lui;
    func_0011A518(buf, 0, 0x126);
    *(u16 *)buf = D_0021DFB0[0];
    func_0011A9EC((char *)buf + 0x15, D_00172160.name);
    D_00172160.unk62C = 1;
    crc = -1;
    poly = 0xEDB88320;
    for (p = info; p < info + 0x28; p++) {
        crc ^= *p;
        for (i = 7; i >= 0; i--) {
            if (crc & 1) {
                crc = (crc >> 1) ^ poly;
            } else {
                crc >>= 1;
            }
        }
    }
    crc ^= 0x1725DFAD;
    *(s32 *)(info + 0x28) = D_0021DA64 ^ (crc & 0xFFFF);
    *(s32 *)(info + 0x2C) = D_0021DA68 ^ ((u32)crc >> 16);
    z = D_0021DA6C == 0;
    info[0x30] = crc ^ z;
    memcpy(buf + 0x26, info, 0x34);
    start = func_0012FEB0(func_0012E370(), 0x24000);
    func_0015B548(func_01ED6998(buf, (s32)func_0015BED0, 0));
    if (wait == 0) {
        return 1;
    }
    func_0015A028();
    ok = 1;
    while (D_00172160.unk62C != 0) {
        if (func_0015B558() != 0) {
            ok = 0;
            break;
        }
        func_0015A050();
        if ((s32)func_0012FEB0(func_0012E370(), 0x24000) - start >= 0x1389) {
            ok = 0;
            break;
        }
    }
    D_00172160.unk62C = 0;
    if (ok != 0 && D_00172160.unk630 != 0) {
        ok = 0;
    }
    return ok;
}
