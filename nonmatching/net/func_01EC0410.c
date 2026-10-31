/* Not matching yet: BYTES 16/128 (tools/try_func.py func_01EC0410 --diff). Not part of the build. */
extern void func_01EB6428(s32, s32);

// Frees each nonzero 8-byte entry of the table at a1, then clears its count fields.
void func_01EC0410(s32 a0, u8 *a1) {
    s32 i;
    s32 n;
    u8 *p;

    n = *(s32 *)(a1 + 0x44);
    i = 0;
    if (n > 0) {
        p = a1;
        do {
            if (*(s32 *)p != 0) {
                func_01EB6428(a0, *(s32 *)p);
                *(s32 *)p = 0;
                n = *(s32 *)(a1 + 0x44);
            }
            i += 1;
            p += 8;
        } while (i < n);
    }
    *(s32 *)(a1 + 0x44) = 0;
    *(s32 *)(a1 + 0x40) = 0;
}
