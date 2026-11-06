#include "common.h"

extern u8 D_00306EC0[];
extern s16 D_001F36AC[];
extern s32 D_0021EE54;
extern s32 D_0021EE58;
extern s32 D_0021EE4C;
extern s32 D_002216A4;
extern void (*D_003D8EC8[])(s32 arg0);

s32 func_00506BB8(void);
void func_00498B48(s32 arg0);

void func_0049B9B0(void)
{
    s32 index;
    s32 object;
    s32 count;
    s32 entry;
    void (*callback)(s32 arg0);

    index = func_00506BB8();
    object = (s32)(D_00306EC0 + index * 0x3C);
    D_001F36AC[0] = 0;
    if (D_0021EE54 == 0 && D_0021EE58 == 1) {
        D_0021EE4C = D_002216A4;
    }
    count = *(s32 *)(object + 0xC);
    if (count > 0) {
        do {
            count--;
            *(s32 *)(object + 0xC) = count;
            entry = (s32)D_003D8EC8 + (count << 4);
            callback = *(void (**)(s32 arg0))(entry + 4);
            if (callback != 0) {
                callback(index);
            }
            count = *(s32 *)(object + 0xC);
        } while (count > 0);
    }
    func_00498B48(index);
}
