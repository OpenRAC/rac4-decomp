/* Not matching yet: BYTES 2/116 (tools/try_func.py func_01EE992C --diff). Not part of the build. */
/* cflags: @ee296 -O2 -G0 -falign-jumps=1 -mno-split-addresses -fno-optimize-sibling-calls -fno-gcse */
extern u8 D_0019B460[];
extern void *func_01EE34E0(s32 *out);
extern void func_01EE4CDC(void *arg0);
extern void func_01F0C090(char *arg0, s32 arg1);

void func_01EE992C(void *arg0) {
    void *t;

    if (*(s32 *)(*(u8 **)((u8 *)arg0 + 0x635C) + 4) != 0) {
        func_01F0C090(D_0019B460, 0xA4E);
    }
    t = func_01EE34E0(*(s32 **)((u8 *)arg0 + 0x635C));
    *(void **)(*(u8 **)((u8 *)arg0 + 0x635C) + 4) = t;
    if (t == 0) {
        func_01F0C090(D_0019B460, 0xA52);
    }
    func_01EE4CDC(*(void **)(*(u8 **)((u8 *)arg0 + 0x635C) + 4));
}
