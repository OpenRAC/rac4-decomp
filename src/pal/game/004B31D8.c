#include "common.h"

typedef struct {
    u32 state;
    u8 pad4[0x78];
    s32 timer;
} Flow;

extern u8 *D_003367B8[10];
extern s32 *D_0021DE2C;
extern Flow D_003097A8;
extern void func_00439550(s32, s32);
extern u8 *func_00511CC0(s32);
extern void func_00498090(s32, s32, s32);
extern void func_004B5210(void);
extern void func_004B33E8(void);
extern void func_004B34D8(void);
extern void func_004B35B8(void);
extern void func_004B38A0(void);
extern void func_004B39A0(void);
extern void func_004B3B48(void);
extern void func_004B3CD0(void);
extern void func_004B4DC0(void);
extern void func_004B3DB8(void);
extern void func_004B3E20(void);
extern void func_004B4098(void);
extern void func_004B4588(void);
extern void func_004B4A70(void);
extern void func_004B4CA8(void);
extern void func_00502520(u8 *);
extern void func_004B5930(void);

// Calls func_00439550 for each present player of D_003367B8 and func_00498090 for each
// entry counted by *D_0021DE2C; then, unless D_003097A8's countdown (+0x7C) is running, runs
// the step for its state (+0) and finally func_004B5930.
void func_004B31D8(u8 *arg) {
    s32 i;
    u8 *p;

    for (i = 0, p = D_003367B8[0]; i < 10; p = D_003367B8[++i]) {
        if (p != NULL) {
            func_00439550(i, *(s32 *)(p + 0x2F00));
        }
    }
    for (i = 0; i < *D_0021DE2C; i++) {
        *(s16 *)(func_00511CC0(i) + 0x3BA) = 5;
        func_00498090(i, 5, 2);
    }
    if (D_003097A8.timer != 0) {
        D_003097A8.timer--;
    } else {
        switch (D_003097A8.state) {
        case 0:
            func_004B5210();
            D_003097A8.state = 1;
            break;
        case 1:
            func_004B33E8();
            break;
        case 2:
            func_004B34D8();
            break;
        case 3:
            func_004B35B8();
            break;
        case 4:
            func_004B38A0();
            break;
        case 5:
            func_004B39A0();
            break;
        case 6:
            func_004B3B48();
            break;
        case 7:
            func_004B3CD0();
            break;
        case 8:
            func_004B4DC0();
            D_003097A8.state = 9;
            break;
        case 9:
            func_004B3DB8();
            break;
        case 10:
            func_004B3E20();
            break;
        case 11:
            func_004B4098();
            break;
        case 12:
            func_004B4588();
            break;
        case 13:
            func_004B4A70();
            break;
        case 15:
            func_004B4CA8();
            break;
        case 16:
            func_00502520(arg);
            break;
        }
    }
    func_004B5930();
}
