#include "common.h"

extern int func_L01_00597190(void *, int, int, int, int, int, float, float, float);

/* Invoke the same helper for selectors 19, 18 and 17, rereading byte 0x28A each time. */
void func_L01_00496DD8(void *a)
{
    unsigned char *p = *(unsigned char **)((char *)a + 0xAC);

    func_L01_00597190(a, 19, 2049, 0, 1, 0, 0.5f, p[0x28A], 1.0f);
    func_L01_00597190(a, 18, 2049, 0, 1, 0, 0.5f, p[0x28A], 1.0f);
    func_L01_00597190(a, 17, 2049, 0, 1, 0, 0.5f, p[0x28A], 1.0f);
}
