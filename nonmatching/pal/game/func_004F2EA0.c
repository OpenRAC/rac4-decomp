/* Not matching yet: 19/25 (76.00%) relocation-masked positional words; 100/100 candidate/target bytes. The draft reloads the global while the target polls a cached pointer; polling semantics remain unresolved. Reproduce: python tools/check_func.py --version pal func_004F2EA0 nonmatching/pal/game/func_004F2EA0.c --diff. Not part of the build. */
/* cflags: -O2 -G8 -fno-schedule-insns2 -Wuninitialized */
#include "common.h"

/* 19/25 target words match (76.00%) under relocation-masked positional
 * comparison; 100/100 bytes. The target caches the video pointer and reloads
 * its +0xC field; this draft reloads the global each iteration. Its polling
 * semantics and the first callee's concrete pointer type remain unresolved.
 * Verify with tools/diff_func.py --version pal func_004F2EA0. */
extern s32 func_004F0D68(void *);
extern s32 func_004F1CA8(u8 *, s32);
extern s32 func_004F2F08(void *);
extern void func_004F22C8(void *);
typedef struct Video Video;
extern Video *D_00221FA8;
s32 func_004F2EA0(void *arg0) {

    func_004F0D68((u8 *)arg0 + 0x48);
    func_004F22C8(D_00221FA8);
    func_004F2F08(arg0);

loop:
    if (*(s32 *)((u8 *)D_00221FA8 + 0xC)) goto loop;
    return func_004F1CA8((u8 *)arg0, 3);
}


