/* Not matching yet: BYTES 27/192 (tools/try_func.py func_01EEBC70 --diff). Not part of the build. */
/* cflags: @ee296 -O2 -G8 */
extern s32 func_01EED528(s32);

typedef struct Obj Obj;
typedef struct Inner Inner;
typedef struct Vtbl Vtbl;
typedef struct Vtbl0 Vtbl0;

struct Vtbl {
    char pad00[0x24];
    s32 (*unk24)(Inner *, s32, s32);
    char pad28[0x14];
    s32 (*unk3C)(Inner *);
};

struct Inner {
    char pad00[0x8];
    Vtbl *unk8;
};

struct Vtbl0 {
    char pad00[0x4C];
    s32 (*unk4C)(Obj *, s32);
};

struct Obj {
    Vtbl0 *unk0;
    char pad04[0x14];
    s32 unk18;
    s32 unk1C;
    Inner *unk20;
    s32 unk24;
};

s32 func_01EEBC70(Obj *arg0) {
    if (arg0->unk20->unk8->unk24(arg0->unk20, arg0->unk1C, arg0->unk24) == 0) {
        return func_01EED528(0xF);
    }
    arg0->unk18 = 1;
    if (arg0->unk20->unk8->unk3C(arg0->unk20) == 0) {
        if (arg0->unk0->unk4C(arg0, 6) == 0) {
            return func_01EEBEA4((s32)arg0, 0xA);
        }
        return func_01EEBEA4((s32)arg0, 7);
    }
    func_01EEBEA4((s32)arg0, 6);
}
