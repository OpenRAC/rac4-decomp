/* cflags: @ee29 */
#include "common.h"

typedef struct Type1 Type1;
struct Type1 {
    char _p0[0x28];
    s64 f28;
};

s32 func_L00_004F89B0(void *);
s32 func_L00_004F8C38(void *, void *);
extern Type1 *D_004A1888;
void func_L00_0051C768(void);
void func_L00_0051C788(void);
void func_L00_0051C7A0(void);

void func_L00_0051C7E0(void) {
    if (D_004A1888 != NULL) {
        D_004A1888->f28 = 0;
        func_L00_004F8C38(D_004A1888, func_L00_0051C768);
        func_L00_004F8C38(D_004A1888, func_L00_0051C788);
        func_L00_004F8C38(D_004A1888, func_L00_0051C7A0);
        func_L00_004F89B0(D_004A1888);
        D_004A1888 = NULL;
    }
}
