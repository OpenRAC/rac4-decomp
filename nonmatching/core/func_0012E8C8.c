/* Not matching yet: SIZE ours 68 / retail 76 (tools/try_func.py func_0012E8C8 --diff). Not part of the build. */
extern u8 D_1ACA00[];
extern void *D_1ACE00;

/* Point every 0x10-byte slot at the next one, then clear the last. */
void func_0012E8C8(void) {
    u8 *base = D_1ACA00;
    s32 *entry = (s32 *)(D_1ACA00 + 0x3F0);
    u8 *next = D_1ACA00 + 0x400;
    s32 i;

    D_1ACE00 = base;
    for (i = 0x3F; i >= 0; i--) {
        *entry = (s32)next;
        entry = (s32 *)((u8 *)entry - 0x10);
        next -= 0x10;
    }
    (*(s32 *)(D_1ACA00 + 0x3F0)) = 0;
}
