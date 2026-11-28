#ifndef PAL_PROFILE_001721E0_H
#define PAL_PROFILE_001721E0_H
#include "common.h"
/* The byte member is an object-representation view of the existing opaque region. */
union Type4Region20 {
    u8 bytes[0x208];
    struct {
        u8 opaque20[8];
        s32 f28;
        u8 opaque2C[8];
        s32 f34;
        u8 opaque38[0xA0];
        s32 fD8;
        u8 fDC;
        u8 opaqueDD[0x20];
        u8 fFD, fFE;
        u8 opaqueFF[0x1D];
        s32 f11C;
        u8 f120;
        u8 opaque121[3];
        s32 f124, f128;
        u8 opaque12c[0xEC];
        u32 f218;
        u8 opaque21c[0xC];
    } words;
};
typedef struct Type4 {
    s32 f0;
    u8 opaque04[8];
    u32 fC;
    s32 f10, f14;
    u8 opaque18[4];
    s32 f1C;
    union Type4Region20 region20;
    s32 f228;
    u8 pad22C[0x258 - 0x22C];
    s32 f258, f25C;
    u8 f260;
    u8 pad261[0x2D5 - 0x261];
    u8 f2D5, f2D6;
    u8 pad2D7[0x6A0 - 0x2D7];
    s32 f6A0[10];
    u8 pad6C8;
    u8 f6C9[16];
    u8 pad6D9[0x120];
    u8 slotState[10];
    u8 slotNames[10][16];
    u8 slotTeams[10];
} Type4;
typedef char Type4RegionSizeCheck[(sizeof(union Type4Region20) == 0x208) ? 1 : -1];
typedef char Type4ViewSizeCheck[(sizeof(Type4) == 0x8B0) ? 1 : -1];
extern Type4 D_001721E0;
#endif
