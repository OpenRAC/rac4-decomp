#include "common.h"
extern int D_0021DE3C;
extern int func_0045CFA8(char *, int *, int *), func_0047FEB0(s32, s32, s32, s32, u8 *);
extern void func_0045D0C0(char *);
int func_0045D188(char *p)
{
    if (*(int *)(p + 0x60)) {
        int a = 0, b = 0, status = 0, mode;
        *(unsigned char *)(p + 0x64) = 0;
        *(unsigned char *)(p + 0x6C) = 1;
        func_0045CFA8(p, &a, &b);
        mode = (((u32)D_0021DE3C - 1) <= 1) ? 2 : 1;
        *(int *)(p + 0x68) = mode;
        if (b == 0)
            status = func_0047FEB0(1, mode, 0, a, 0);
        else if (b == 1)
            status = func_0047FEB0(2, mode, a, 0, 0);
        if (status < 0)
            func_0045D0C0(p);
        return status == 0;
    }
    return 0;
}
