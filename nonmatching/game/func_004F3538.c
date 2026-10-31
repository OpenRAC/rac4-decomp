/* Not matching yet: BYTES 16/116 (tools/try_func.py func_004F3538 --diff). Not part of the build. */
/* Frees each live entry of the 0x1F0 pointer table in D_237000 (count at 0x84) and clears its slot. */
extern void func_0046BDD0(s32);
extern u8 D_237000[];

void func_004F3538(void) {
    u8 *base;
    s32 i;
    s32 *slot;
    s32 obj;

    i = 0;
    base = D_237000;
    if (*(s16 *)(base + 0x84) > 0) {
        slot = (s32 *)(base + 0x1F0);
        do {
            obj = *slot;
            if (obj != 0) {
                *(s32 *)(obj + 0xAC) = 0;
                func_0046BDD0(obj);
                *slot = 0;
            }
            i++;
            slot++;
        } while (i < *(s16 *)(base + 0x84));
    }
}
