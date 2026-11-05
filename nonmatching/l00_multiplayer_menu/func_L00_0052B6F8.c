/* Not matching yet: BYTES 3/344 (tools/try_func.py func_L00_0052B6F8 --diff). Not part of the build. */
/* cflags: @ee29 -O2 -G0 */

typedef struct {
    char pad0[0x184];
    s32 unk184;
    void *unk188;
    s32 unk18C;
    s32 unk190;
} Sub54;

typedef struct {
    char pad0[0xAC];
    s32 unkAC;
} SubB0;

typedef struct {
    char pad0[0x54];
    s32 unk54;
    char pad58[0xB0 - 0x58];
    SubB0 *unkB0;
} Obj;

extern void func_0011A518(void *, s32, s32);
extern void func_004FAD28(void *);
extern s32 func_0051A6E0(s32);
extern s32 func_0051A6F8(s32);
extern s32 func_0051A700(s32);
extern void func_L00_004F84C8(int, int, int, int, int);
extern void *func_L00_004FACD8(unsigned int);
extern s32 func_L00_005061D0(s32, s32 *, s32 *);
extern void func_L00_00527D88(Obj *);
extern s32 func_L00_0052B150(Obj *, void *, void *, s32);

s32 func_L00_0052B6F8(Obj *obj) {
    s32 buf[2];
    s32 len;
    s32 size;
    void *a;
    void *b;

    if (((Sub54 *)obj->unk54)->unk184 != 0) {
        return 1;
    }
    if (func_L00_005061D0(obj->unkB0->unkAC, &buf[0], &buf[1]) == 0) {
        func_L00_004F84C8(0x14, 0xD4, 0x8A, 0, 0);
        return 0;
    }
    ((Sub54 *)obj->unk54)->unk18C = buf[0];
    ((Sub54 *)obj->unk54)->unk190 = buf[1];
    len = func_0051A6F8(buf[0]) + func_0051A6E0(buf[1]) + func_0051A700(buf[0]);
    size = len * 2 + 1;
    func_L00_00527D88(obj);
    a = func_L00_004FACD8(size);
    if (a != 0 && (b = func_L00_004FACD8(size)) != 0) {
        ((Sub54 *)obj->unk54)->unk184 = size;
        ((Sub54 *)obj->unk54)->unk188 = a;
        if (func_L00_0052B150(obj, a, b, size) != 0) {
            func_0011A518(b, 0, size);
            func_004FAD28(b);
            return 1;
        }
    } else {
        func_L00_004F84C8(0x14, 0xD4, 0x21, 0, 0);
    }
    return 0;
}
