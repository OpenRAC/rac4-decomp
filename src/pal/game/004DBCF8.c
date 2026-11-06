#include "common.h"
extern s32 func_00499120(s32);
extern void func_004DBAB0(void);
extern void func_004DBBC0(void);
extern void func_004DBC50(s32);
extern void func_004DBDA8(void);
extern void func_004DC070(s32);

void func_004DBCF8(void)
{
    s32 enabled = 0;
    switch (func_00499120(6)) {
    case 1:
        func_004DBAB0();
        break;
    case 2:
        func_004DBBC0();
        break;
    case 5:
        enabled = 1;
    case 6:
        func_004DBC50(enabled);
        break;
    case 13:
        func_004DBDA8();
        break;
    case 9:
        func_004DC070(0);
        break;
    case 11:
        func_004DC070(1);
        break;
    }
}
