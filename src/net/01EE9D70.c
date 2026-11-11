/* cflags: -mno-split-addresses */
#include "net_allocator.h"

typedef struct Type1 Type1;
struct Type1 {
    char _p0[0x138];
    s32 f138;
};


void func_01EE9D70(Type1 *arg0) {
    func_01EF0550(arg0->f138, (s32)arg0);
}
