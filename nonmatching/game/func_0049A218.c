/* Not matching yet: BYTES 20/136 (tools/try_func.py func_0049A218 --diff). Not part of the build. */
/* cflags: -malign-loops=4 */
#include "common.h"

typedef struct Entry {
    s32 f0;
    void (*on8)(s32);
    void (*onC)(s32);
} Entry;

extern void func_00453608(void *p, s32 v, s32 n);
extern void func_0049A1A8(void);
extern Entry D_003D8DE0[];
extern s32 D_221578[];
extern s32 D_306D20[];

void func_0049A218(void)
{
    s32 base;
    s32 p;
    s32 end;
    void (*fn)(void);

    func_00453608(D_306D20, 0, 0x40);
    func_00453608(D_221578, 0, 0xC);
    base = (s32)D_003D8DE0; end = base + 0x84; p = base;
    do {
        fn = *(void (**)(void))p;
        if (fn != NULL) {
            fn();
        }
        p += 0xC;
    } while (p < end);
    func_0049A1A8();
}
