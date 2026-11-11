/* Not matching yet: BYTES 20/120; GCC hoists D_0019DA58 into $s4, retail recomputes per iteration (tools/try_func.py func_01EFEB30 --diff). Not part of the build. */
/* cflags: @ee296 -O2 -G0 -mno-split-addresses -falign-loops=1 */
#include "common.h"

extern void func_0011A518(void *, s32, s32);
extern void func_0011A9EC(void *, void *);
extern char D_0019DA58[];

/* Clear the 0x184-stride block of 64 records: fill one 0x100 area, copy the name
   template over the second and zero the 0x464 word; return the last record. */
char *func_01EFEB30(char *base)
{
    s32 n = 0x3F;
    s32 off = 0;
    char *p;

    for (; n >= 0; n--) {
        p = (char *)((u32)off + (u32)base);
        off += 0x184;
        func_0011A518(p + 0x2E4, 0, 0x100);
        func_0011A9EC(p + 0x3E4, D_0019DA58);
        *(s32 *)(p + 0x464) = 0;
    }
    return p;
}
