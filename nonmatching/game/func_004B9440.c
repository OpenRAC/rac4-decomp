/* Not matching yet: BYTES 6/284 (tools/try_func.py func_004B9440 --diff). Not part of the build. */
/* cflags: -G16 */
/* Note: the cflags above were a diagnostic experiment; a landable version must build with the file's normal flags. */
#include "common.h"

typedef struct {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    s32 unkC;
} Type1;

extern s32 func_0045E038(s32);
extern s32 func_004A1A60(s32 *arg0, s32 arg1);
extern s32 func_00505238(u32, s32);
extern s32 func_00505B20(void);
extern s32 D_003D9488[][13];
extern s32 D_002217B0;
extern Type1 D_002217B8[];

s32 D_0021F8A0[4] = {0x2F1B, 0x2F19, 0x2F1A, 0};
s32 D_0021F8B0[4] = {0x3163, 0x3164, 0x3165, 0};

void func_004B9440(void) {
    Type1 *p;
    s32 h;
    s32 i;

    i = 0;
    p = &D_002217B8[func_00505B20()];
    h = func_004A1A60(&D_002217B0, 0x64);
    func_00505238(h, func_0045E038(D_0021F8A0[p->unk4]));
    do {
        h = func_004A1A60(&D_002217B0, i + 0xB4);
        func_00505238(h, func_0045E038(D_003D9488[p->unk4][i]));
        i++;
    } while (i < 13);
    h = func_004A1A60(&D_002217B0, 0xB6);
    func_00505238(h, func_0045E038(D_0021F8B0[p->unk8]));
}
