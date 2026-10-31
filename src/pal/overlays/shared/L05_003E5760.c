/* cflags: -O2 -G8 -Wuninitialized */
#include "common.h"

void func_00474368(void *, int, int);

/* Initialize the nested record and call the selected level function. */
void func_L05_003E5760(void *arg0)
{
    void *record = *(void **)((u8 *)arg0 + 0xAC);
    *(s8 *)((u8 *)record + 0xC) = 1;
    *(s32 *)((u8 *)record + 8) = 0;
    func_00474368(arg0, 1, -1);
}
