/* Not matching yet: BYTES 76/128 (tools/try_func.py func_L02_00405428 --diff). Not part of the build. */
/* cflags: @ee296 -O2 -G8 */
extern u8 D_0039D730[];
extern u8 D_0039D748[];
extern u8 D_0039D760[];

extern s32 D_0039D17C;
extern s32 D_0039D180;
extern s32 D_0039D184;

extern void func_L01_00513E78();

void func_L02_00405428(u8 *arg0) {
    u8 *obj = *(u8 **)(arg0 + 0xAC);

    if (*(u8 *)(arg0 + 0x20) == 0) {
        *(u8 *)(arg0 + 0x20) = 1;
        *(u32 *)(obj + 0x14) = (u32)D_0039D730;
        *(u32 *)(obj + 0x10) = (u32)D_0039D748;
        *(u32 *)(obj + 0xC) = 0;
        *(s32 *)(obj + 0x4) = D_0039D17C;
        *(s32 *)(obj + 0x18) = D_0039D180;
        *(u32 *)(obj + 0x8) = (u32)D_0039D760;
        *(s32 *)(obj + 0x1C) = D_0039D184;
        *(u32 *)(obj + 0x0) = 0;
        *(s32 *)(obj + 0x20) = D_0039D180;
    }
    func_L01_00513E78(arg0, obj, arg0);
}
