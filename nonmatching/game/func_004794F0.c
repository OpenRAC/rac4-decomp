/* Not matching yet: BYTES 14/128 (tools/try_func.py func_004794F0 --diff). Not part of the build. */
/* Frees the nonzero entries of the table at +0x120 (count at +0x148), then clears the flag at +0x14C. */
extern void func_0046BDD0(s32 a0);

void func_004794F0(u8 *arg0) {
    s32 i;
    s32 *p;

    if (*(s32 *)(arg0 + 0x14C) != 0) {
        i = 0;
        if (*(s32 *)(arg0 + 0x148) > 0) {
            p = (s32 *)(arg0 + 0x120);
            do {
                if (*p != 0) {
                    func_0046BDD0(*p);
                    *p = 0;
                }
                i++;
                p++;
            } while (i < *(s32 *)(arg0 + 0x148));
        }
        *(s32 *)(arg0 + 0x14C) = 0;
    }
}
