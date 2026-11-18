/* Not matching yet: SIZE ours 184 / retail 188 (tools/try_func.py func_01EE66B0 --diff). Not part of the build. */
#include "common.h"

typedef struct Type1 Type1;
struct Type1 {
    char _p0[0x3A34];
    void **f3A34;
    char _p1[0x20C4];
    char _p2[0x10];
    s32 f5B0C;
    s32 f5B10;
    char _p3[4];
    s32 f5B18;
    s32 f5B1C;
    void **f5B20;
};

void func_01EE38C4(void **);
void func_01EE90EC(void *);
void func_01EE955C(void *, s32);
void *func_01EE98D8(void *, s32);
void func_01EEFA5C(void);
void func_01EF0C1C(s32);
void func_01EF0C54(s32);

void func_01EE66B0(Type1 *arg0, s32 arg1) {
    s32 temp_s0;

    if (arg1 == 0) {
        if (arg0->f5B10 != 0) {
            if (arg0->f5B20 != 0) {
                (*(void (**)(void *))((u8 *)*arg0->f5B20 + 0x18))(arg0->f5B20);
                arg0->f5B20 = 0;
            }
            func_01EE955C(arg0, 0);
        }
    }
    if (func_01EE98D8(arg0, 0) != 0) {
        func_01EE90EC(arg0);
    }
    if (arg0->f3A34 != 0) {
        func_01EE38C4(arg0->f3A34);
        arg0->f3A34 = 0;
    }
    temp_s0 = (s32)((u8 *)arg0 + 0x5AFC);
    arg0->f5B18 = 0;
    arg0->f5B1C = 0;
    func_01EF0C54(temp_s0);
    func_01EF0C1C(temp_s0);
    arg0->f5B0C = 0;
    func_01EEFA5C();
}
