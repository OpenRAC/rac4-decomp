/* Not matching yet: SIZE ours 40 / retail 56 (tools/try_func.py func_01EA8BD0 --diff). Not part of the build. */
extern void *D_00167F34;

/* Call the current object's handler at 0x58 with the two arguments. */
void func_01EA8BD0(u64 arg0, u64 arg1) {
    void *object = D_00167F34;
    void (*handler)(u64, u64) = *(void **)((u8 *)object + 0x58);

    handler(arg0, arg1);
}
