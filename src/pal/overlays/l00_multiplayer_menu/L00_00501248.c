/* cflags: @ee29 -O2 -G0 -fno-strict-aliasing */
#include "common.h"

typedef struct Type1 Type1;
typedef struct Type2 Type2;
typedef struct Type3 Type3;
typedef struct Type4 Type4;

struct Type2 {
    u8 pad[0xA0];
    Type3 *fA0;
};

struct Type1 {
    u8 pad[0x84];
    Type3 *f84;
    u8 pad88[0x54];
    Type2 *fDC;
};

extern Type3 *func_L00_004FF728(void);
extern void func_L00_004FF798(Type3 *);
extern void func_L00_004F89C8(s32, s32, s32, const char *, s32);
extern s32 func_L00_005013B8(Type3 *, Type4 *);
extern s32 func_L00_00528B70(Type3 *, Type4 *);

// Installs the first input in the object's private container, replacing a shared container.
s32 func_L00_00501248(Type1 *arg0, Type4 *arg1)
{
    Type3 *current;
    Type3 *replacement;

    if (arg1 == NULL) {
        func_L00_004F89C8(0x14, 0xC7, 0x23, NULL, 0);
        return 0;
    }

    current = arg0->f84;
    if (current == NULL || current == arg0->fDC->fA0) {
        replacement = func_L00_004FF728();
        if (replacement == NULL) {
            func_L00_004F89C8(0x14, 0xC7, 0x21, NULL, 0);
            return 0;
        }
        if (arg0->f84 != NULL) {
            func_L00_004FF798(arg0->f84);
        }
        arg0->f84 = replacement;
        current = replacement;
    }

    return func_L00_005013B8(current, arg1);
}

// Installs the second input in the object's private container, replacing a shared container.
s32 func_L00_00501300(Type1 *arg0, Type4 *arg1)
{
    Type3 *current;
    Type3 *replacement;

    if (arg1 == NULL) {
        func_L00_004F89C8(0x14, 0xCA, 0x23, NULL, 0);
        return 0;
    }

    current = arg0->f84;
    if (current == NULL || current == arg0->fDC->fA0) {
        replacement = func_L00_004FF728();
        if (replacement == NULL) {
            func_L00_004F89C8(0x14, 0xCA, 0x21, NULL, 0);
            return 0;
        }
        if (arg0->f84 != NULL) {
            func_L00_004FF798(arg0->f84);
        }
        arg0->f84 = replacement;
        current = replacement;
    }

    return func_L00_00528B70(current, arg1);
}
