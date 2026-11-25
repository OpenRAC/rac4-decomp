#include "common.h"

extern s32 *D_002233A4;
extern s32 D_00172284[];

extern char *func_0011A9EC(char *, char *);
extern void func_0015B370(void);
extern void func_0015B548(s32 val);
extern s32 func_0015B558(void);
extern void func_00161118(s32 val);
extern void func_00161330(u8 val);
extern s32 func_01ED6258(u8 *arg0);

s32 func_L00_0076F280(void) {
    u8 buf[0x20];
    s32 *p;
    s32 saved;
    s32 result = 1;

    p = D_002233A4;
    saved = p[25];
    func_0015B370();
    func_00161330(0);
    func_00161118(-1);
    D_00172284[0] = -1;
    func_0011A9EC((char *)buf, (char *)saved);
    *(s32 *)(buf + 0x14) = 2;
    func_0015B548(func_01ED6258(buf));
    if (func_0015B558() != 0) {
        p[4] = 4;
        if (p[5] == 0) {
            p[5] = 4;
        }
        result = 0;
    }
    *(s32 *)(buf + 0x14) = 1;
    func_0015B548(func_01ED6258(buf));
    if (func_0015B558() != 0) {
        p[4] = 4;
        if (p[5] == 0) {
            p[5] = 4;
        }
        result = 0;
    }
    return result;
}
