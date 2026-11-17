/* Not matching yet: BYTES 52/168 (tools/try_func.py func_L00_00703320 --diff). Not part of the build. */
extern void func_L00_005BCBF0(void *, void *, s32);
extern void func_L00_006CB978(u8 *, u8, s32, s16, s32, void *);

extern u8 *D_00343E78[];

s32 func_L00_00703320(s32 unused0, s32 unused1, s32 unused2, u8 *arg3) {
    u8 buffer[0x28];
    u8 *entry;
    u8 *ptr;
    s32 valid;

    func_L00_005BCBF0(buffer, arg3, 0x28);
    entry = D_00343E78[buffer[2] & 0xF];
    valid = 0;
    if (entry != 0) {
        if (*(s32 *)(entry + 0x25CC) != 0x9B) {
            ptr = *(u8 **)(entry + 0x2F28);
            if (ptr != 0) {
                valid = *(u32 *)(ptr + 4) != 0;
            }
        }
    }
    if (valid != 0) {
        func_L00_006CB978(D_00343E78[buffer[2] & 0xF], buffer[3],
                          *(s32 *)(buffer + 8), *(s16 *)(buffer + 0), 0,
                          buffer);
    }
    return 0x28;
}
