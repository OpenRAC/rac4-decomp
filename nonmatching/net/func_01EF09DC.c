/* Not matching yet: BYTES 5/124 (tools/try_func.py func_01EF09DC --diff). Not part of the build. */
/* cflags: @ee296 -O2 -G0 -fno-gcse -mno-split-addresses */
extern void func_01F0C090(char *arg0, s32 arg1);
extern char D_0019C588[];
char *func_01EF09DC(char *arg0)
{
    s32 n; s32 v; s32 i;
    n = *(s32 *)(arg0 + 0x2020);
    if (n <= 0) {
        func_01F0C090(D_0019C588, 0x97);
        n = *(s32 *)(arg0 + 0x2020);
    }
    v = n << 8;
    v += n;
    v += (s32)arg0;
    if (*(s8 *)(v - 0x101) == 0)
        func_01F0C090(D_0019C588, 0x98);
    n = *(s32 *)(arg0 + 0x2020);
    v = n << 8;
    i = v + n;
    return arg0 + i - 0x101;
}
