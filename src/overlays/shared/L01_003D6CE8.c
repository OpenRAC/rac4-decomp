#include "common.h"

typedef struct Type1 Type1;
struct Type1 {
    char _p0[0x20];
    u8 f20;
};

s32 func_005AF4B8(void);

s32 func_L01_003D6CE8(Type1 *arg0) {
    if ((u32)(arg0->f20 - 0xD) < 3U) {
        return 0;
    }
    func_005AF4B8();
    return 0;
}
