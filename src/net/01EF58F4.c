/* cflags: -mno-split-addresses */
#include "net_allocator.h"

typedef struct Type1 Type1;
struct Type1 {
    char _p0[0x4];
    s32 f4;
};


void func_01EF58F4(Type1 *arg0) {
    func_01EF0550(arg0->f4, (s32)arg0);
}
