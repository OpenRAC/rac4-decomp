/* cflags: @ee29 -O2 -G0 */
#include "common.h"

typedef union {
    s32 i;
    void *p;
} Type3;
extern s32 func_L00_0051A258(Type3 *);
extern Type3 *func_L00_0051A350(void);
extern void func_L00_0051A628(Type3 *);
typedef struct {
    s32 pad[8];
    s32 (*f20)(void);
} Type2;
typedef struct {
    void *f0;
    Type2 *f4;
    s32 pad[5];
    Type3 *f1C;
} Type1;
s32 func_L00_005184C8(Type1 *arg0) {
    s32 value;
    if (arg0->f1C != 0) {
        func_L00_0051A628(arg0->f1C);
        arg0->f1C = 0;
    }
    arg0->f1C = func_L00_0051A350();
    if (arg0->f1C == 0) return 0x2715;
    value = arg0->f4->f20();
    arg0->f1C->i = value;
    if (value == 0) return 0x2711;
    return func_L00_0051A258(arg0->f1C) != 0 ? 0 : 0x2711;
}
