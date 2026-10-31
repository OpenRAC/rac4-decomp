/* Not matching yet: BYTES 10/92 (tools/try_func.py func_0012E918 --diff). Not part of the build. */
/* cflags: -O2 */
extern s32 D_1ACE00_[];
#define D_1ACE00 (D_1ACE00_[0])

// Calls the method at +0x8 of arg3 with a tag built from arg0 and arg3; if that returns 0, links arg3 at the head of D_1ACE00 and returns -1.
s32 func_0012E918(s32 arg0, s32 a1, s32 a2, s32 *arg3) {
    s32 r;
    s32 tmp;

    r = ((s32 (*)(s32, s32, s32, s32))arg3[2])((((u32)arg3 << 4) | (arg0 & 0xFE) | 1), a1, a2, arg3[3]);
    if (r != 0) {
        return r;
    }
    r = -1;
    tmp = D_1ACE00;
    D_1ACE00 = (s32)arg3;
    arg3[0] = tmp;
    arg3[1] = 0;
    return r;
}
