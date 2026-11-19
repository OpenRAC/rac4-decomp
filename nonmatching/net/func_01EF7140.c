/* Not matching yet: BYTES 16/160 (tools/try_func.py func_01EF7140 --diff). Not part of the build. */
/* cflags: @ee296 -O2 -G0 -fno-gcse -mno-split-addresses */
typedef struct {
    char name[0xE];
} Entry;

extern s32 func_0011A8A0(const char *, const char *);
extern s32 func_01EE3A18(s32, void *);
extern Entry D_0019CCF8[];
extern s32 D_0019CE58[];

s32 func_01EF7140(s32 arg0, s32 arg1, s32 arg2, s32 *arg3)
{
    s32 i;
    char *p;
    s32 r;

    r = func_01EE3A18(arg1, (void *)arg2);
    if (r != 0) {
        for (i = 0; i < 0x19; i++) {
            p = D_0019CCF8[i].name;
            if (func_0011A8A0((const char *)r, p) == 0) {
                *arg3 = D_0019CE58[i];
                return 1;
            }
        }
    }
    return 0;
}
