/* cflags: @ee296 -O2 -G0 */
#include "common.h"

typedef struct { s32 f0; s32 f4; s32 f8; s32 fC; s32 f10; } Stream;
extern u8 D_0016A080[];
extern void *func_0011A518(void *, s32, u32);
extern void func_01EAA0D0(Stream *, u8 *, u8 *);
extern s32 func_01EAA130(s32, Stream *, void *, s32);
extern s32 func_01EAA3B8(s32, Stream *, void *);
s32 func_01EDD538(s32 a, s32 b, s32 c, u8 *buf) {
    Stream st;
    func_0011A518(D_0016A080, 0, 0x95);
    func_01EAA0D0(&st, buf, buf + 0x200);
    func_01EAA130(2, &st, D_0016A080, 0x15);
    func_01EAA3B8(2, &st, D_0016A080 + 0x15);
    if (st.f10 != 0) {
        return -1;
    }
    return st.f8 - st.f0;
}
