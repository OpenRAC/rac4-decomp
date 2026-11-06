#include "common.h"
typedef struct {
    s32 type, key, value;
    u32 rest[3];
} Request;
typedef struct {
    u8 prefix[8];
    s16 text;
} Resource;
typedef struct {
    u8 prefix[0x36];
    u16 text;
} Descriptor;
extern s32 func_00506BB8(void);
extern void func_004999D0(Request *);
extern s32 func_004CD818(void);
extern s32 func_004CDC60(s32), func_004CDE78(s32);
extern Resource *func_0047DB88(s32);
extern Descriptor *func_0054A290(s32, s32);
extern u8 D_0030EAA0[];
extern s32 D_0021EE54, D_0021EE58;

s32 func_004CD748(s32 selection)
{
    Request request;
    u32 state = (u32)D_0030EAA0 + (u32)func_00506BB8() * 0x64;
    if (selection == 8) {
        request.type = 5;
        request.key = *(s32 *)(state + 0x38);
        func_004999D0(&request);
        return request.value;
    }
    if (selection == 9)
        return func_004CD818();
    if ((D_0021EE54 || D_0021EE58 != 1) && selection < 8)
        return func_0047DB88(func_004CDC60(selection))->text;
    return func_0054A290(func_004CDE78(selection), 0)->text;
}
