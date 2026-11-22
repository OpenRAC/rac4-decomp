#include "common.h"

typedef struct T2 { char _p0[0x28C]; u8 f28C; char _p28D[0x32C - 0x28D]; u16 f32C; char _p32E[0x5F0 - 0x32E]; void *f5F0; } T2;
typedef struct T1 { char _p0[0xAC]; T2 *fAC; } T1;

extern int func_L01_00592EB8(f32, f32, f32, void *, int, int, int, int, int);

void func_L01_0045BB30(T1 *arg0) {
    T2 *p = arg0->fAC;
    func_L01_00592EB8(0.5f, (f32)p->f28C, 1.0f, p->f5F0, 5, (p->f32C & 0x1000) ? 0x800 : 1, 0, 1, 0);
    func_L01_00592EB8(0.5f, (f32)p->f28C, 1.0f, p->f5F0, 0, (p->f32C & 0x1000) ? 0x800 : 1, 0, 1, 0);
}
