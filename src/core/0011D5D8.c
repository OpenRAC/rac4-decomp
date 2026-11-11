#include "common.h"

typedef struct {
    u8 f0[8];
    struct Type2 *f8;
} Type1;

struct Type2 {
    u8 f0[0x54];
    Type1 *f54;
};

extern Type1 *D_00163E74_[];
#define D_00163E74 (D_00163E74_[0])

void func_00122A28(void *, s32, void *);

void func_0011D5D8(s32 arg0, ...) {
    void *args;

    D_00163E74->f8->f54 = D_00163E74;
    args = (void *)((u8 *)__builtin_next_arg(arg0) - 0x38);
    func_00122A28(D_00163E74->f8, arg0, args);
}
