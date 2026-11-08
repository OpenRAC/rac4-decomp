#include "common.h"

typedef struct Type1 Type1;
typedef struct Type2 Type2;
struct Type1 {
    char _p0[0x114];
    u8 f114;
};
struct Type2 {
    char _p0[0x260];
    u8 f260;
};

s32 func_0071BE80(void *);
s32 func_L00_0071B478();
extern Type1 *D_00220D14;

void func_L00_0074A3C8(Type2 *arg0) {
    D_00220D14->f114 = (u8) arg0->f260;
    func_L00_0071B478();
    func_0071BE80(arg0);
}
