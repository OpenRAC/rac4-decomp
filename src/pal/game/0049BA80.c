#include "common.h"

typedef struct {
    u8 pad[0x354];
    u32 unk354[7];
} Unk0049BA80Sub;

typedef struct {
    u8 pad[0x3BA];
    s16 unk3BA;
    u8 pad2[0x2B44];
    Unk0049BA80Sub *unk2F00;
} Unk0049BA80Obj;

typedef struct {
    u8 unk0;
    u8 unk1;
    u8 pad[2];
    s32 unk4;
    u8 pad2[0x30];
    s32 unk38;
} Unk0049BA80Entry;

extern Unk0049BA80Entry D_00306EC0[];
extern u8 D_0021EE98;
extern s32 D_0021EE54;
extern s32 D_0021DE3C;

extern s32 func_00506BB8(void);
extern Unk0049BA80Obj *func_00511CC0(s32);
extern s32 *func_0046DD08(s32, s32, s32);
extern void func_00498090(s32, s32, s32);
extern void func_00490538(Unk0049BA80Sub *);
extern void func_00490298(Unk0049BA80Sub *);
extern void func_00502520(void *);
extern void func_0049BCA0(s32);
extern void func_0049BCF8(s32);

void func_0049BA80(void *arg0) {
    s32 buf[7];
    s32 index;
    s32 j;
    Unk0049BA80Obj *obj;
    Unk0049BA80Entry *entry;
    s32 *o;
    s32 *p;
    s32 f;

    index = func_00506BB8();
    obj = func_00511CC0(index);
    entry = &D_00306EC0[index];
    switch (entry->unk38) {
    case 0:
        if (D_0021EE98 == 0 && D_0021EE54 != 1 && D_0021DE3C != 3) {
            break;
        }
        o = func_0046DD08(0x2120, 0, 0xC);
        if (o != NULL) {
            f = o[0];
            if (f != 0) {
                ((void (*)(void)) f)();
            }
        }
        func_0049BCA0(index);
        entry->unk38 = 2;
        break;
    case 1:
        obj->unk3BA = 5;
        func_00498090(index, 5, 0);
        if (D_0021EE54 == 1) {
            j = 0;
            p = buf;
            do {
                *p++ = obj->unk2F00->unk354[j];
                j++;
            } while (j < 7);
            func_00490538(obj->unk2F00);
            func_00490298(obj->unk2F00);
            j = 0;
            p = buf;
            do {
                obj->unk2F00->unk354[j] = *p++;
                j++;
            } while (j < 7);
        } else {
            func_00490538(obj->unk2F00);
            func_00490298(obj->unk2F00);
        }
        if (entry->unk4 == 0) {
            o = func_0046DD08(0x2120, 0, 0xC);
            if (o != NULL) {
                f = o[1];
                if (f != 0) {
                    ((void (*)(void)) f)();
                }
            }
            func_00502520(arg0);
        }
        break;
    case 2:
        obj->unk3BA = 5;
        if (entry->unk1 != 0) {
            func_0049BCF8(index);
            entry->unk38 = 1;
            entry->unk1 = 0;
        }
        break;
    }
}
