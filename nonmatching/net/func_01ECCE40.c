/* Not matching yet: SIZE ours 144 / retail 136 (tools/try_func.py func_01ECCE40 --diff). Not part of the build. */
/* cflags: -O2 -G8 */
typedef struct {
    char pad[0x10];
    unsigned int f10;
    unsigned int f14;
} Arg;

typedef struct {
    char pad[0x10C];
    unsigned int f10C;
} Ctx;

extern Ctx *D_00167F38;

extern signed char *func_01EC9A08(unsigned int, unsigned int);

void func_01ECCE40(Arg *arg0) {
    unsigned int i;
    signed char *p;

    if (arg0 == 0) {
        return;
    }
    if (arg0->f10 >= D_00167F38->f10C) {
        return;
    }
    for (i = 0; i < arg0->f14; i++) {
        p = func_01EC9A08(i + arg0->f10, arg0->f10);
        if (p == 0) {
            continue;
        }
        *p = 1;
    }
}
