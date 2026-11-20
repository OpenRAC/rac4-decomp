/* Not matching yet: BYTES 0/588, exact only with inline asm (plzcw), which matched C may not use (tools/check_func.py func_00461740). Not part of the build. */
#include "common.h"

typedef struct SpriteRec {
    u64 f0;
    s16 h;
    s16 w;
    s16 log_a;
    s16 log_b;
} SpriteRec;

typedef struct SpriteItem {
    void *data;
    u8 pad4[0x1C];
} SpriteItem;

typedef struct SpriteGroup {
    s16 count;
    u8 pad2[2];
    s16 f4;
    s16 f6;
    u8 pad8[0x18];
    SpriteItem items[1];
} SpriteGroup;

typedef struct SpriteFile {
    u8 pad0[4];
    s16 loaded;
    s16 group_count;
    u8 pad8[4];
    s16 sprite_count;
    u8 padE[2];
    SpriteRec *sprites;
    void *f14;
    void *f18;
    void *f1C;
    SpriteGroup *groups[1];
} SpriteFile;

typedef struct SpriteState {
    SpriteFile *file;
} SpriteState;

extern SpriteState D_00221CF0;
extern s32 D_0021DE10;

/* plzcw (R5900 MMI): leading sign bits minus one, so 30 - n is floor(log2(x)) for x > 0. No C form
 * gives retail's bare plzcw: SN's __builtin_plzcw works on 128-bit values and adds por copies and a
 * sign extension. */
static inline s32 lead_sign_bits(s32 x)
{
    s32 r;
    __asm__("plzcw %0, %1" : "=r"(r) : "r"(x));
    return r;
}

void func_00461740(SpriteFile *file)
{
    s32 *src;
    s32 i;
    s32 j;
    s32 k;
    s32 m;

    D_00221CF0.file = file;
    file->loaded = 1;
    D_00221CF0.file->sprites = (SpriteRec *)((u8 *)D_00221CF0.file->sprites + (s32)file);
    D_00221CF0.file->f14 = (u8 *)D_00221CF0.file->f14 + (s32)file;
    D_00221CF0.file->f18 = (u8 *)D_00221CF0.file->f18 + (s32)file;
    if (D_00221CF0.file->f1C != NULL) {
        D_00221CF0.file->f1C = (u8 *)D_00221CF0.file->f1C + (s32)file;
    }
    src = (s32 *)D_00221CF0.file->sprites;
    for (i = 0; i < D_00221CF0.file->sprite_count; i++) {
        s32 w = *src++ >> 4;
        s32 h = *src++ >> 4;
        s32 a = 30 - lead_sign_bits(*src++);
        s32 b = 30 - lead_sign_bits(*src++);

        D_00221CF0.file->sprites[i].w = w;
        D_00221CF0.file->sprites[i].h = h;
        D_00221CF0.file->sprites[i].log_a = a;
        D_00221CF0.file->sprites[i].log_b = b;
        D_00221CF0.file->sprites[i].f0 = 0;
    }
    for (k = 0; k < D_00221CF0.file->group_count; k++) {
        SpriteGroup *g;

        g = D_00221CF0.file->groups[k] = (SpriteGroup *)((u8 *)D_00221CF0.file->groups[k] + (s32)file);
        for (j = 0; j < g->count; j++) {
            ((SpriteItem *)g)[j + 1].data = (u8 *)((SpriteItem *)g)[j + 1].data + (s32)file;
        }
    }
    if (D_0021DE10 > 0 && D_0021DE10 < 80 && D_0021DE10 % 20 == 7) {
        for (m = 1; m < D_00221CF0.file->group_count; m++) {
            D_00221CF0.file->groups[m]->f4 = 0x2AAA;
            D_00221CF0.file->groups[m]->f6 = 0x1D4C;
        }
    }
}
