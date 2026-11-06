#ifndef PAL_PROFILE_001721E0_H
#define PAL_PROFILE_001721E0_H
#include "common.h"
/* The byte member is an object-representation view of the existing opaque region. */
union Type4Region20 {
    u8 bytes[0x208];
    struct {
        u8 opaque20[0x104];
        s32 f124, f128;
        u8 opaque12c[0xEC];
        u32 f218;
        u8 opaque21c[0xC];
    } words;
};
typedef struct Type4 {
    s32 f0;
    u8 opaque04[0x18];
    s32 f1C;
    union Type4Region20 region20;
    s32 f228;
    u8 pad22C[0x258 - 0x22C];
    s32 f258, f25C;
    u8 f260;
    u8 pad261[0x6C9 - 0x261];
    u8 f6C9;
} Type4;
typedef char Type4RegionSizeCheck[(sizeof(union Type4Region20) == 0x208) ? 1 : -1];
typedef char Type4PrefixSizeCheck[(sizeof(Type4) == 0x6CC) ? 1 : -1];
extern Type4 D_001721E0;
#endif
