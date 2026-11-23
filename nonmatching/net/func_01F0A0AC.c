/* Not matching yet: BYTES 2/124 (tools/try_func.py func_01F0A0AC --diff). Not part of the build. */
/* cflags: @ee296 -O2 -G0 -falign-loops=1 -mno-split-addresses -fno-schedule-insns */
extern s32 func_01F09C2C(s32 *arg0);
extern s32 func_01F09CAC(s32 *arg0, s32 arg1);
extern void func_01F0C090(char *arg0, s32 arg1);
extern s32 D_0019E5C0[];
void func_01F0A0AC(s32 *arg0, s32 arg1)
{
    s32 *p;
    s32 i;
    s32 r;

    p = arg0;
    if (arg1 == 0) {
        func_01F0C090((char *)D_0019E5C0, 0xAC);
    }
    i = 0;
    do {
        r = func_01F09CAC(p, arg1);
        i++;
        if (r != 0) {
            func_01F09C2C(p);
            return;
        }
        p += 2;
    } while (i < 5);
}
