#include "common.h"

extern int func_L01_00592EB8(void *, int, int, int, int, int, float, float, float);

/* Invoke the same helper for selectors 19, 18 and 17, rereading byte 0x28A each time. */
void func_L01_004955E0(void *a)
{
    unsigned char *p = *(unsigned char **)((char *)a + 0xAC);

    func_L01_00592EB8(a, 19, 2049, 0, 1, 0, 0.5f, p[0x28A], 1.0f);
    func_L01_00592EB8(a, 18, 2049, 0, 1, 0, 0.5f, p[0x28A], 1.0f);
    func_L01_00592EB8(a, 17, 2049, 0, 1, 0, 0.5f, p[0x28A], 1.0f);
}
