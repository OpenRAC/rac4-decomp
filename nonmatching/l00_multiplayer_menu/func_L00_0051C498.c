/* Not matching yet: BYTES 4/176 (tools/try_func.py func_L00_0051C498 --diff). Not part of the build. */
/* cflags: @ee29 */
#include "common.h"

typedef struct Type1 Type1;
struct Type1 {
    char _p0[0x28];
    s64 f28;
};

s32 func_L00_004F89B0(void *);
s32 func_L00_004F8C38(void *, void *);
void func_L00_00508338(void *);

extern Type1 *D_004A03AC;
extern void *D_004A03B4;
extern void *D_004A03B8;
extern void *D_004A03BC;
extern s32 D_00476F7C;

void func_L00_0051C468(void);

void func_L00_0051C498(s32 arg0) {
    if (D_004A03AC != NULL) {
        s64 t = D_004A03AC->f28;
        D_00476F7C = arg0;
        D_004A03AC->f28 = 0;
        func_L00_004F8C38(D_004A03AC, func_L00_0051C468);
        if (arg0 < 0) {
            func_L00_004F89B0(D_004A03AC);
            func_L00_00508338(D_004A03B8);
            func_L00_00508338(D_004A03B4);
            func_L00_00508338(D_004A03BC);
            D_004A03AC = NULL;
            D_004A03B8 = NULL;
            D_004A03B4 = NULL;
            D_004A03BC = NULL;
        } else {
            D_004A03AC->f28 = t;
        }
    }
}
