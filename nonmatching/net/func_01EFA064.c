/* Not matching yet: SIZE ours 176 / retail 180 (tools/try_func.py func_01EFA064 --diff). Not part of the build. */
extern char D_0019D240[];
extern void func_01F0C090(char *arg0, s32 arg1);

typedef struct {
    char pad0[0xEC];
    s32 fEC;
    s32 fF0;
    s32 fF4;
    char padF8[4];
    s32 fFC;
    s32 f100;
    char pad104[0x18];
    s32 f11C;
    s32 f120;
    char pad124[0x3C];
    f32 f160;
} Obj;

void func_01EFA064(Obj *arg0) {
    s32 a1, v1, a0;

    arg0->f160 = 0.0f;

    if ((arg0->fF0 + arg0->fFC) < arg0->fF0) {
        func_01F0C090(D_0019D240, 0x275);
    }

    a1 = arg0->f100;
    v1 = arg0->fEC;
    if (a1 < v1) {
        arg0->f160 = (f32)arg0->fF4 / (f32)v1;
    }

    a0 = arg0->fF0;
    if (a0 == 0) {
        arg0->f11C = 0;
    } else {
        arg0->f11C = 1;
    }

    if ((a0 + a1) >= (v1 + 1)) {
        arg0->f120 = 0;
    } else {
        arg0->f120 = 1;
    }
}
