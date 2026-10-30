/* Not matching yet: BYTES 7/76 (tools/try_func.py func_0048A9A8 --diff). Not part of the build. */
extern u8 D_355DC0[];
u16 D_0021F35C = 0;
/* Stamps the record at a1 with the serial counter and its index in D_355DC0 (80-byte records), then advances the counter modulo 65534. */
void func_0048A9A8(s32 unused, u8 *a1) {
    u16 serial;
    u32 idx;

    idx = (u32)(a1 - D_355DC0) / 0x50U;
    serial = D_0021F35C;
    *(u16 *)(a1 + 0x10) = serial;
    *(u32 *)(a1 + 0x18) = idx | ((u32)serial << 16);
    D_0021F35C = (((u32)D_0021F35C + 1) & 0xFFFF) % 0xFFFE;
}
