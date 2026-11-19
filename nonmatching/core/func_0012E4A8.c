/* Not matching yet: BYTES 18/160 (tools/try_func.py func_0012E4A8 --diff). Not part of the build. */
/* cflags: @ee29 -O2 -G0 */
typedef struct Type1 {
    int f0;
    int f4;
    int f8;
    int fC;
} Type1;

typedef struct Type2 {
    char pad0[0x10];
    int f10;
    int f14;
    char pad18[4];
    int f1C;
} Type2;

extern Type2 D_00165D28[];
extern int func_0012E040(Type1 *p);

int func_0012E4A8(unsigned int id) {
    Type1 *p = (Type1 *)((id >> 10) << 6);
    Type2 *d;

    if ((int)id < 0) {
        return 0x80008002;
    }
    if ((id & 0x3FF) != p->f8) {
        return 0x80008002;
    }
    d = D_00165D28;
    if (d->f1C == (int)id) {
        return 0x80000010;
    }
    if (p->fC & 2) {
        func_0012E040(p);
    }
    p->f8 = 0;
    p->fC = 0;
    p->f0 = d->f14;
    d->f14 = (int)p;
    d->f10--;
    return 0;
}
