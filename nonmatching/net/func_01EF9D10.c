/* Not matching yet: BYTES 88/200 (tools/try_func.py func_01EF9D10 --diff) (tools/try_func.py func_01EF9D10 --diff). Not part of the build. */
/* cflags: -fno-schedule-insns -fno-schedule-insns2 */
extern void func_0011A518(void *, s32, s32);
extern void func_01EF9E18(void *);
extern void func_01F0C090(const char *, s32);
extern u8 D_0019D240[];

void func_01EF9D10(void *arg0) {
    s32 i;

    func_0011A518(*(void **)((u8 *)arg0 + 0xB4), 0, *(s32 *)((u8 *)arg0 + 0xB8));
    if (*(u32 *)((u8 *)arg0 + 0x118) == 0) {
        func_01F0C090((const char *)D_0019D240, 0x1D2);
    }
    i = 0;
    if ((*(s32 *)((u8 *)arg0 + 0xBC) + 1) > 0) {
        do {
            if (i == 0) {
                *(s16 *)(*(u8 **)((u8 *)arg0 + 0x118)) = 0;
            } else {
                *(s16 *)(*(u8 **)((u8 *)arg0 + 0x118) + i * 0xC) = -1;
            }
            *(s32 *)(*(u8 **)((u8 *)arg0 + 0x118) + i * 0xC + 8) =
                *(s32 *)((u8 *)arg0 + 0x12C);
            *(s16 *)(*(u8 **)((u8 *)arg0 + 0x118) + i * 0xC + 4) = i;
            *(s16 *)(*(u8 **)((u8 *)arg0 + 0x118) + i * 0xC + 2) = 0;
            i += 1;
        } while (i < (*(s32 *)((u8 *)arg0 + 0xBC) + 1));
    }
    func_01EF9E18(arg0);
}
