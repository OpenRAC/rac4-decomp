/* cflags: -mno-split-addresses */
#include "net_allocator.h"

typedef struct Type1 Type1;
struct Type1 {
    char _p0[0x18];
    s32 f18;
};


void func_01F0C4CC(Type1 *arg0) {
    func_01EF0550(arg0->f18, (s32)arg0);
}
