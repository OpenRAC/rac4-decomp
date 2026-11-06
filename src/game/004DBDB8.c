#include "common.h"

extern s32 func_004983E8(s32 mode);
extern void func_004DC570(s32 next);
extern void func_004DC9A8(s32 direction);
extern void func_004DBE78(void);
extern void func_004DBE98(void);

void func_004DBDB8(void)
{
    s32 next = 0;

    switch (func_004983E8(6)) {
    case 7:
        next = 1;
    case 8:
        func_004DC570(next);
        break;
    case 5:
        func_004DC9A8(2);
        break;
    case 6:
        func_004DC9A8(1);
        break;
    case 1:
        func_004DC9A8(3);
        break;
    case 3:
        func_004DC9A8(4);
        break;
    case 2:
        func_004DBE78();
        break;
    case 13:
        func_004DBE98();
        break;
    }
}
