#include "common.h"

typedef struct { s32 w[7]; } Type2;
extern s32 func_0011AB04(u8 *);
extern char *func_0011AFC8(char *, char *, s32);
extern s32 func_L00_0076BE58();
extern Type2 *func_L00_0076C410(void *, s32, u8 *);
extern char D_002217F0[];

/* Look up an entry by name, copy it out and select it. */
s32 func_L00_0076BE90(s32 *arg0, u8 *arg1, Type2 *arg2) {
    s32 dflt = 0;
    Type2 *e;

    if (arg1 == 0 || func_0011AB04(arg1) == 0) {
        dflt = 1;
    }
    e = func_L00_0076C410(arg0, *arg0, arg1);
    if (arg2 != 0) {
        *arg2 = *e;
    }
    if ((e != 0 && e->w[6] == 0) || dflt) {
        if (dflt) {
            func_0011AFC8((char *)arg0 + 0x2C, D_002217F0, 4);
        } else {
            func_0011AFC8((char *)arg0 + 0x2C, (char *)arg1, 4);
        }
        return func_L00_0076BE58(arg0, (char *)arg0 + 0x24);
    }
    return 0;
}
