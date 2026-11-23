/* Not matching yet: BYTES 41/136 (tools/try_func.py func_00547B08 --diff). Not part of the build. */
extern char *func_0011A9EC(char *, char *);

extern s32 D_222064[];
extern s32 D_222068[];
extern s32 D_22206C[];
extern s32 D_222070[];
extern char D_355220[];
extern char D_3552A0[];

void func_00547B08(char *arg0, s32 arg1, s32 arg2) {
    s32 *p;
    s32 *q;
    char *buf;

    if (arg0 != 0) {
        if ((arg2 > 0) && (arg1 >= 0)) {
            if ((D_222064[0] > 0) && (D_222068[0] > 0)) {
                return;
            }
            p = &D_222064[0];
            q = &D_22206C[0];
            buf = D_355220;
            if (D_222064[0] > 0) {
                p = &D_222068[0];
                q = &D_222070[0];
                buf = D_3552A0;
            }
            *p = arg2;
            *q = arg1;
            func_0011A9EC(buf, arg0);
        }
    }
}
