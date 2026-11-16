/* Not matching yet: SIZE ours 56 / retail 64 (tools/try_func.py func_0012D4E8 --diff) (tools/try_func.py func_0012D4E8 --diff). Not part of the build. */
/* cflags: @ee29 -O2 -G0 */
int func_0012D4E8(u32 *dst, u32 *src, u32 n) {
    u32 count = n >> 2;
    u32 i;
    for (i = 0; i < count; i++)
        *dst++ = *src++;
    return 0;
}
