#include "common.h"

extern void func_0015CB10(s32 a, s32 b);
extern void func_0070A5F0();
extern void func_L00_00709290(void);
extern s32 func_L00_0070C368(void *);
extern void func_L00_0070C3E0(int *arg0, int arg1);
extern void func_L00_0070CEB8(void *);
extern void func_L00_0070D418(void);
extern void func_L00_007744B0(void *object);

typedef struct { s32 f0[0x58 / 4]; void **f58; } Obj1;
void *D_002233A4 = 0;
Obj1 *D_00220D14 = 0;

/* tears down the menu object and returns the old one */
Obj1 *func_L00_00718480(void) {
    char buf[0x470];
    Obj1 *o;
    func_L00_0070C368(buf);
    func_L00_0070CEB8(buf);
    func_L00_0070D418();
    func_0070A5F0();
    func_L00_00709290();
    func_0015CB10(0, 0);
    func_L00_007744B0(D_002233A4);
    ((void (*)(Obj1 *, s32))D_00220D14->f58[2])(D_00220D14, 2);
    o = D_00220D14;
    D_00220D14 = 0;
    func_L00_0070C3E0((int *)buf, 2);
    return o;
}
