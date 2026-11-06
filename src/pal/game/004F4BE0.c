/* cflags: -O2 -G8 -Wuninitialized */
#include "common.h"
/* Unknown record spans preserve the observed field offsets. */
typedef struct {
    unsigned char f00[0x18];
    short f18;
    unsigned char f1a[0x1aa];
    int f1c4;
    int f1c8;
    int f1cc;
    int f1d0[5];
    int f1e4;
} Type1;
typedef struct {
    unsigned char f00[7];
    unsigned char f07;
} Type2;
typedef struct {
    int f00[0x24];
    int f90[132];
} Type3;
typedef struct {
    int f00[4];
    unsigned int f10;
} Type4;
extern Type1 D_001719C8[];
extern Type2 D_002069D0[];
extern Type3 D_001D2280[];
extern Type4 D_00239840[];
extern unsigned char D_0023A980[];
extern int D_0021EE54, D_0021DE3C, D_0022140C, D_002213E0, D_0021DE98;
void func_00453E20(void *, int, int);
void func_0047FEB0(int, int, int, int, int);
void func_0047F8D8(void);
void func_0046F9B0(void);
void func_00126E20(int);
void func_00159608(int, int, int, int, int);
void func_00159138(void);
int func_00157FA8(void);
void func_004E3300(void);
void func_00489E20(void);
void func_001585A8(int);
void func_00158578(void);
void func_00466B58(void);
void func_004653A0(void);
void func_00466640(int);
int func_0048A6E0(int);
void func_00161D00(void);
void func_0015ADC8(void);
void func_00449B28(int, int);
void func_00463E08(void);
void func_00163550(int);
void func_004E9020(void);
/* Drains pending resources and waits for active operations before teardown. */
void func_004F4BE0(void) {
    int i;
    func_00453E20(D_0023A980, -1, 128);
    if (D_0021EE54 == 1) {
        func_0047FEB0(6, 2, 0, 0, 0);
        func_0047F8D8();
    } else
        D_0021DE3C = 6;
    D_00239840[0].f10 |= 0x80000000;
    if (D_0021EE54 == 0)
        func_0046F9B0();
    func_00126E20(0);
    func_00159608(2, 0, 0, 0, 0);
    func_00159138();
    func_00157FA8();
    func_004E3300();
    func_00489E20();
    D_002069D0[0].f07 = 1;
    for (i = 0; i < 132; i++) {
        if (D_001D2280[0].f90[i]) {
            func_001585A8(D_001D2280[0].f90[i]);
            func_00158578();
            D_0022140C = 0;
            D_001D2280[0].f90[i] = 0;
        }
    }
    while (D_001719C8[0].f1c4 >= 3 || D_001719C8[0].f1cc >= 0) {
        func_00466B58();
        func_004653A0();
    }
    if (D_001719C8[0].f1e4)
        D_001719C8[0].f1e4 = 0;
    if (D_001719C8[0].f18 >= 0)
        D_001719C8[0].f18 = -1;
    func_00466640(0);
    D_002069D0[0].f07 = 0;
    func_0048A6E0(1);
    while (func_00157FA8()) {
        if (D_0021EE54 == 1) {
            func_00161D00();
            func_0015ADC8();
        }
    }
    D_002069D0[0].f07 = 1;
    func_00449B28(5, 0);
    D_0021DE98 = D_002213E0;
    func_00463E08();
    func_00163550(1);
    D_002069D0[0].f07 = 0;
    func_004E9020();
}
