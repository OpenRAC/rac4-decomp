/* Not matching yet: BYTES 8/92 (tools/try_func.py func_01EB6918 --diff). Not part of the build. */
extern s32 func_01EBD798(void);
void func_01EB6978();
extern s32 D_00167F40_[];
#define D_00167F40 (D_00167F40_[0])

/* Calls func_01EB6978 and func_01EBD798, then if the global pointer D_00167F40 is set copies four words from arg0 into that object at 0x84..0x90. */
s32 func_01EB6918(void *arg0) {
    void *p;

    func_01EB6978();
    func_01EBD798();
    p = (void *)D_00167F40;
    if (p == NULL) {
        return 0;
    }
    *(s32 *)(p + 0x84) = *(s32 *)(arg0 + 0x0);
    *(s32 *)(p + 0x88) = *(s32 *)(arg0 + 0x4);
    *(s32 *)(p + 0x8C) = *(s32 *)(arg0 + 0xC);
    *(s32 *)(p + 0x90) = *(s32 *)(arg0 + 0x8);
    return 0;
}
