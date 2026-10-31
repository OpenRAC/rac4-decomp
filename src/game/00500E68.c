#include "common.h"

typedef struct Type2 Type2;
typedef struct {
    char pad[0x10];
    s32 (*f10)(Type2 *);
} Type3;
struct Type2 {
    s32 f0;
    Type3 *f4;
};
typedef struct {
    char pad[0x2C];
    Type2 *f2C[12];
} Type4;
typedef struct {
    s32 f0;
    Type4 *f4;
} Type1;

/* Call the slot-0x10 method of each non-null entry (of 12) in the table at arg0->f4->f2C. */
void func_00500E68(Type1 *arg0) {
    s32 i;
    Type2 *p;

    for (i = 0; i < 12; i++) {
        p = arg0->f4->f2C[i];
        if (p != NULL) {
            p->f4->f10(p);
        }
    }
}
