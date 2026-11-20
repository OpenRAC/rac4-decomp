/* Not matching yet: BYTES 0/284, exact only with inline asm (plzcw), which matched C may not use (tools/check_func.py func_00461570). Not part of the build. */
#include "common.h"

typedef struct SpritePack {
    s32 count;
    s32 pad4;
    s32 data_offset;
    s32 data_size;
    s32 offsets[1];
} SpritePack;

typedef struct SpriteCoord {
    s32 u;
    s32 v;
} SpriteCoord;

extern u8 D_00270B70[];
extern u8 *D_00270918[];
extern SpriteCoord D_002702C0[];
extern s32 D_002214F4;
extern void func_00453718(void *, void *, s32);

/* plzcw (R5900 MMI): leading sign bits minus one, so 30 - n is floor(log2(x)) for x > 0. No C form
 * gives retail's bare plzcw: SN's __builtin_plzcw works on 128-bit values and adds por copies and a
 * sign extension. */
static inline s32 lead_sign_bits(s32 x)
{
    s32 r;
    __asm__("plzcw %0, %1" : "=r"(r) : "r"(x));
    return r;
}

void func_00461570(SpritePack *pack, s32 base, s32 *src, s32 n)
{
    s32 *offs = pack->offsets;
    s32 count = pack->count;
    s32 data = pack->data_offset;
    s32 size = pack->data_size;
    s32 i;

    for (i = 0; i < count; i++, offs++) {
        if (*offs == 0) {
            D_00270918[i] = D_00270B70;
        } else {
            D_00270918[i] = (u8 *)(*offs - (data - (s32)D_00270B70));
        }
    }
    func_00453718(D_00270B70, (u8 *)pack + data, size);
    for (D_002214F4 = 0; D_002214F4 < n; D_002214F4++) {
        s32 x = *src++;
        s32 y = *src++;
        s32 z = *src++;
        s32 w = *src++;

        D_002702C0[D_002214F4].u = ((base + x) << 4) + y;
        {
            s32 lw = 30 - lead_sign_bits(w);
            D_002702C0[D_002214F4].v = ((base + z) << 4) + lw;
        }
    }
}
