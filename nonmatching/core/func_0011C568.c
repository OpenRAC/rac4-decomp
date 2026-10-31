/* Not matching yet: BYTES 8/116 (tools/try_func.py func_0011C568 --diff). Not part of the build. */
/* cflags: -fno-opt-stack */
extern void *func_00124F98(s32, u32);
extern void func_0011A518(void *, s32, s32);
// allocates a 0x58-byte record slot for n, links its data area and clears its header
void *func_0011C568(s32 d, s32 n) {
    s32 size;
    s32 *p;
    u8 *data;

    size = n * 0x58;
    p = func_00124F98(d, size + 0xC);
    if (p == 0) {
        return 0;
    }
    data = (u8 *)p + 0xC;
    p[1] = n;
    p[0] = 0;
    p[2] = (s32)data;
    func_0011A518(data, 0, size);
    return p;
}
