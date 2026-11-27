/* Not matching yet: BYTES 2/244 (tools/try_func.py func_00152BC8 --diff). Not part of the build. */
/* cflags: @ee296 -O2 -G0 */
extern s32 func_0011D5D8(const char *fmt, ...);
extern void func_00126BC0(s32);
extern void func_00126BE0(s32);
extern s32 func_0012A718();
typedef struct { s32 f0; char _p4[8]; s32 fC; char f10; char f11; } G;
extern G *D_0016F8DC;
extern s32 D_0016F8E4[];
extern char D_001A4148[];
extern s32 D_1B9300[];

s32 func_00152BC8(s32 arg0, unsigned char arg1, unsigned char arg2) {
    s32 r;
    G *p;
    if (D_0016F8E4[0] == -1) {
        return 0x8000000A;
    }
    func_00126BE0(D_0016F8E4[0]);
    p = D_0016F8DC;
    D_0016F8DC->f10 = arg1;
    p->fC = arg0;
    D_0016F8DC->f11 = arg2;
    if (func_0012A718(D_1B9300, 0xD, 0, D_0016F8DC, 0x20, D_0016F8DC, 0x20, 0, 0) == 0) {
        r = D_0016F8DC->f0;
        func_00126BC0(D_0016F8E4[0]);
        return r;
    }
    func_0011D5D8(D_001A4148);
    func_00126BC0(D_0016F8E4[0]);
    return 0x80000000;
}
