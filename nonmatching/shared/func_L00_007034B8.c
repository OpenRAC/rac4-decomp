/* Not matching yet: BYTES 18/136 (tools/try_func.py func_L00_007034B8 --diff). Not part of the build. */
extern void func_L00_005BCBF0(void *dst, void *src, s32 n);
extern void func_L00_006BD738(u8 *player, u8 *input);
extern u8 *D_00343E78[];

s32 func_L00_007034B8(s32 unused0, s32 unused1, s32 unused2, void *data) {
    u8 buffer[0x10];
    u8 *obj;
    s64 a1;
    u32 v0;
    u8 *tmp;

    func_L00_005BCBF0(buffer, data, 0x10);
    obj = D_00343E78[buffer[0xD] & 0xF];
    a1 = 0;
    if (obj != NULL) {
        if (*(s32 *)(obj + 0x25CC) != 0x9B) {
            tmp = *(u8 **)(obj + 0x2F28);
            if (tmp != NULL) {
                a1 = *(u32 *)(tmp + 4) != 0;
            }
        }
    }
    v0 = a1 & 0xFF;
    if (v0 != 0) {
        func_L00_006BD738(obj, buffer);
    }
    return 0x10;
}
