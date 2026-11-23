/* Not matching yet: BYTES 33/124 with @ee296 -O2 -G0 -fno-schedule-insns (tools/try_func.py func_01ED5428 --diff) (tools/try_func.py func_01ED5428 --diff). Not part of the build. */
/* cflags: @ee296 -O2 -G0 -fno-schedule-insns */
extern s32 D_00169CD0;
extern s32 D_00169CD4;
extern s32 D_1BC9C4;
extern s32 D_1BCBBC;
extern s32 func_01ED5DD0(s32, s32, s32, void *);

s32 func_01ED5428(u8 *obj, s32 arg1, s32 arg2)
{
    obj[0x14] = 0;
    if (D_00169CD0 != 1)
        return -15;
    if (D_00169CD4 == 0)
        return -16;
    D_1BCBBC = arg1;
    D_1BC9C4 = arg2;
    if (*(u32 *)(obj + 0x1C) >= 0x64)
        *(s32 *)(obj + 0x1C) = 0;
    return func_01ED5DD0(1, 0xD4, 0x24, obj) == 0 ? 0 : -5;
}
