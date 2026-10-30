/* Not matching yet: BYTES 8/80 (tools/try_func.py func_0015F018 --diff). Not part of the build. */
/* Stores arg1 at offset 0x1C0 of the object that the callee's out-pointer leads to, once D_0021DFE8 is still empty. */
s32 D_0021DFE8 = 0;
extern s32 func_01EC94C0(void *);

void func_0015F018(s32 a0, s32 arg1) {
    void *sp0 = NULL;
    if (func_01EC94C0(&sp0) == 0 && D_0021DFE8 == 0) {
        D_0021DFE8 = *(s32 *)((u8 *)sp0 + 0x1C);
        *(s32 *)(D_0021DFE8 + 0x1C0) = arg1;
    }
}
