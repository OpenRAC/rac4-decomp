/* Not matching yet: BYTES 30/384 (tools/try_func.py func_004D7BC0 --diff). Not part of the build. */
typedef struct { s32 f0; s32 f4; s32 f8; } Type1;
typedef struct { s32 f0; char *f4; s32 f8; } Type3;

extern void func_004979A8(void *, s32, s32);
extern void func_004A1170(void *arg0);
extern void func_004A1240(void *, s32);
extern void func_004A1440(void *, s32 *, s32);
extern void func_004D7D40(void);
extern void func_004D7EE0(void);
extern s32 func_004D8058(void);
extern s32 func_00505B20(void);
extern s32 D_31E898[];
extern Type3 D_31FD38[];
extern Type3 D_31FDBC[];
extern Type1 D_31FF90[];
extern char D_320030[];
extern u8 D_0021FC10;
s32 D_0021FC14 = 0;
char D_00221AF8[8] = { 0 };

// Sets up the current slot's list of 11 entries from the D_31FF90 table, plus the selected one.
void func_004D7BC0(void) {
    char *ent;
    s32 i;

    ent = (char *)D_31E898 + func_00505B20() * 0x528;
    func_004D7D40();
    func_004D7EE0();
    D_0021FC14 = func_004D8058();
    func_004A1170(ent + 0x4BC);
    for (i = 0; i < 11; i++) {
        func_004A1440(ent + 0x4BC, (s32 *)&D_31FD38[i], -1);
        D_31FD38[i].f0 = D_31FF90[i].f0;
        D_31FD38[i].f8 = D_31FF90[i].f8;
        func_004979A8(&D_320030[i * 15], D_31FF90[i].f4, 0);
        D_31FD38[i].f4 = &D_320030[i * 15];
    }
    if (D_0021FC14 < 11) {
        D_0021FC10 = 1;
        func_004A1240(ent + 0x4BC, D_0021FC14);
    }
    func_004A1440(ent + 0x4BC, (s32 *)D_31FDBC, -1);
    func_004979A8(D_00221AF8, D_31FF90[D_0021FC14].f4, 0);
    D_31FDBC[0].f4 = D_00221AF8;
    *(s32 *)(ent + 4) &= ~1;
    D_31FDBC[0].f0 = D_31FF90[D_0021FC14].f0;
    D_31FDBC[0].f8 = D_31FF90[D_0021FC14].f8;
}
